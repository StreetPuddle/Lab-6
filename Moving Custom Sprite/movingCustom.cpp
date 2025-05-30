#include <allegro5\allegro.h>
#include <allegro5\allegro_primitives.h>
#include "arrow.h";
#include "bullet.h"
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <cstdio>


int main(void)
{
	arrowClass arrow;
	bullet bullets[10];//10 bullet array
	int score=0;
	bool redraw=true;
	const int FPS = 60;

	//variables
	int width = 640;
	int height = 520;//updated to accomodate for text on screen(infoboard)
	bool done = false;
	double countDown = 30.0;//time limit
	double timePassed = 0.0;//time counter


	//allegro variable
	ALLEGRO_DISPLAY *display = NULL;
	ALLEGRO_EVENT_QUEUE *event_queue = NULL;
	ALLEGRO_TIMER *timer = NULL;

	//program init
	if(!al_init())										//initialize Allegro
		return -1;

	display = al_create_display(width, height);			//create our display object

	if(!display)										//test display object
		return -2;

	//addon init
	al_install_keyboard();
	al_init_primitives_addon();
	arrow.create_arrow_bitmap(display);
	al_init_font_addon();
	al_init_ttf_addon();
	ALLEGRO_FONT *font1 = al_load_ttf_font("NiseJSRF.TTF", 25, 0);

	if (!font1) 
	{
		return -3;
	}

	for (int i = 0; i < 10; i++)//bitmap stored in bullets array
	{
		bullets[i].create_bullet_bitmap(display);
	}
	al_set_target_bitmap(al_get_backbuffer(display));
	event_queue = al_create_event_queue();
	timer = al_create_timer(1.0 / FPS);//timer ticks 60 times per second, each tick is a 10th of a second
	al_register_event_source(event_queue, al_get_keyboard_event_source());
	al_register_event_source(event_queue, al_get_timer_event_source(timer));
	al_clear_to_color(al_map_rgb(0,0,0));
	arrow.drawArrow();
	al_flip_display();
	al_start_timer(timer);
	while(!done)
	{
		ALLEGRO_EVENT ev;
		al_wait_for_event(event_queue, &ev);

		if(ev.type == ALLEGRO_EVENT_TIMER)//updated statement
		{
			timePassed += 1.0 / FPS;//incrementing time counter by 10th of a second
			countDown = 30.0 - timePassed;//time left
			if (countDown <= 0.0)//if true, game will end
			{
				done = true;
			}
			redraw = true;
			for(int i=0;i<10;i++)
			{
				if (!bullets[i].getStatus()) {
					bullets[i].fire();
				}
			}
		}
		else if(ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
		{
			done = true;
		}
		else if(ev.type == ALLEGRO_EVENT_KEY_DOWN)
		{
			switch(ev.keyboard.keycode)
			{
			case ALLEGRO_KEY_ESCAPE:
				done = true;
				break;
			case ALLEGRO_KEY_UP:
				arrow.up();
				break;
			case ALLEGRO_KEY_DOWN:
				arrow.down();
				break;
			case ALLEGRO_KEY_LEFT:
				arrow.left();
				break;
			case ALLEGRO_KEY_RIGHT:
				arrow.right();
				break;
			}
		}
		if(redraw && al_is_event_queue_empty(event_queue))
		{
			redraw = false;
			al_draw_filled_rectangle(0, 480, width, height, al_map_rgb(25, 25, 25));//score board

			if (arrow.getSpeed()!=0)
			{
				arrow.erase_arrow();
				arrow.move_arrow(width,height);
			}
			arrow.drawArrow();

			for(int i=0;i<10;i++)
			{
				bullets[i].erase_bullet();
				score+=bullets[i].move_bullet(arrow.getX(),arrow.getY(),64,64,480);//updated to adjust for infoboard and sprite grid size
			}

			char timeText[20];//array for storing text
			sprintf(timeText, "COUNTDOWN: %.1f", countDown);//formats to string
			al_draw_text(font1, al_map_rgb(255, 255, 255), 10, 490, 0, timeText);//renders string with font1

			char scoreText[20];//array for storing text
			sprintf(scoreText, "POINTS: %d", score);
			al_draw_text(font1, al_map_rgb(255, 255, 255), 445, 490, 0, scoreText);//renders string with font1

			al_flip_display();
		}
	}
	al_destroy_font(font1);
	al_destroy_event_queue(event_queue);
	al_destroy_timer(timer);
	al_destroy_display(display);						//destroy our display object
	system("pause");
	return 0;
}
