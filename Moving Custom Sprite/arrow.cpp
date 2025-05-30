#include "arrow.h"
arrowClass::arrowClass()
{
	speed=0;
	x=100;
	y=100;
	dir=1;
	score = 0;
	for(int i=0; i<4; i++)
	{
		arrow_bmp[i]=NULL;
	}
}
arrowClass::~arrowClass()
{
	for(int i=0; i<4; i++)
	{
		al_destroy_bitmap(arrow_bmp[i]);
	}
}
void arrowClass::drawArrow()
{
	al_draw_bitmap(arrow_bmp[getDirection()], getX(), getY(), 0);
}
void arrowClass::create_arrow_bitmap(ALLEGRO_DISPLAY *display)
{
	for(int i=0;i<4; i++)
	{
		arrow_bmp[i]=al_create_bitmap(64,64);   
		if(!arrow_bmp[i]) {
			exit(1);
			al_destroy_display(display);

		}

		al_set_target_bitmap(arrow_bmp[i]);

		int x = 0;
		int y = 0;

		switch(i)
		{
		case 0://custom sprite
			al_draw_line(x + 6, y + 48, x + 6, y + 32, al_map_rgb(140, 140, 140), 4);
			al_draw_line(x + 14, y + 50, x + 14, y + 26, al_map_rgb(140, 140, 140), 4);
			al_draw_line(x + 50, y + 48, x + 50, y + 26, al_map_rgb(130, 130, 130), 4);
			al_draw_line(x + 58, y + 50, x + 58, y + 32, al_map_rgb(130, 130, 130), 4);
			al_draw_filled_triangle(x, y + 48, x + 32, y + 24, x + 64, y + 48, al_map_rgb(150, 150, 150));
			al_draw_filled_rectangle(x, y + 48, x + 64, y + 56, al_map_rgb(150, 150, 150));
			al_draw_filled_triangle(x + 18, y + 64, x + 32, y + 32, x + 48, y + 64, al_map_rgb(150, 150, 150));
			al_draw_filled_ellipse(x + 32, y + 32, x + 9, y + 32, al_map_rgb(160, 160, 160));
			al_draw_filled_ellipse(x + 32, y + 16, x + 4, y + 8, al_map_rgb(100, 130, 250));
			break;
		case 1:
			al_draw_line(x + 16, y + 6, x + 32, y + 6, al_map_rgb(140, 140, 140), 4);
			al_draw_line(x + 16, y + 14, x + 38, y + 14, al_map_rgb(140, 140, 140), 4);
			al_draw_line(x + 16, y + 50, x + 38, y + 50, al_map_rgb(130, 130, 130), 4);
			al_draw_line(x + 16, y + 58, x + 32, y + 58, al_map_rgb(130, 130, 130), 4);
			al_draw_filled_triangle(x + 16, y, x + 40, y + 32, x + 16, y + 64, al_map_rgb(150, 150, 150));
			al_draw_filled_rectangle(x + 16, y, x + 8, y + 64, al_map_rgb(150, 150, 150));
			al_draw_filled_triangle(x, y + 18, x + 32, y + 32, x, y + 46, al_map_rgb(150, 150, 150));
			al_draw_filled_ellipse(x + 32, y + 32, x + 32, y + 9, al_map_rgb(160, 160, 160));
			al_draw_filled_ellipse(x + 48, y + 32, x + 8, y + 4, al_map_rgb(100, 130, 250));
			break;
		case 2:
			al_draw_line(x + 58, y + 16, x + 58, y + 32, al_map_rgb(140, 140, 140), 4);
			al_draw_line(x + 50, y + 14, x + 50, y + 38, al_map_rgb(140, 140, 140), 4);
			al_draw_line(x + 14, y + 16, x + 14, y + 38, al_map_rgb(130, 130, 130), 4);
			al_draw_line(x + 6, y + 14, x + 6, y + 32, al_map_rgb(130, 130, 130), 4);
			al_draw_filled_triangle(x + 64, y + 16, x + 32, y + 40, x + 0, y + 16, al_map_rgb(150, 150, 150));
			al_draw_filled_rectangle(x + 64, y + 16, x + 0, y + 8, al_map_rgb(150, 150, 150));
			al_draw_filled_triangle(x + 46, y + 0, x + 32, y + 32, x + 16, y + 0, al_map_rgb(150, 150, 150));
			al_draw_filled_ellipse(x + 32, y + 32, x + 9, y + 32, al_map_rgb(160, 160, 160));
			al_draw_filled_ellipse(x + 32, y + 48, x + 4, y + 8, al_map_rgb(100, 130, 250));
			break;
		case 3:
			al_draw_line(x + 48, y + 58, x + 32, y + 58, al_map_rgb(140, 140, 140), 4);
			al_draw_line(x + 48, y + 50, x + 26, y + 50, al_map_rgb(140, 140, 140), 4);
			al_draw_line(x + 48, y + 14, x + 26, y + 14, al_map_rgb(130, 130, 130), 4);
			al_draw_line(x + 48, y + 6, x + 32, y + 6, al_map_rgb(130, 130, 130), 4);
			al_draw_filled_triangle(x + 48, y + 64, x + 24, y + 32, x + 48, y + 0, al_map_rgb(150, 150, 150));
			al_draw_filled_rectangle(x + 48, y + 64, x + 56, y + 0, al_map_rgb(150, 150, 150));
			al_draw_filled_triangle(x + 64, y + 46, x + 32, y + 32, x + 64, y + 18, al_map_rgb(150, 150, 150));
			al_draw_filled_ellipse(x + 32, y + 32, x + 32, y + 9, al_map_rgb(160, 160, 160));
			al_draw_filled_ellipse(x + 16, y + 32, x + 8, y + 4, al_map_rgb(100, 130, 250));
			break;
		}
	}
}
void arrowClass::erase_arrow()//updated to adjust for the new 64x64 sprite
{

	int left = x ;
	int top = y;
	int right = x + 64;
	int bottom =y + 64;

	al_draw_filled_rectangle(left, top, right, bottom, al_map_rgb(0, 0, 0));
}

void arrowClass::up()
{
	dir=0;
	speed++;
	if (speed > MAXSPEED)
		speed = MAXSPEED;
}

void arrowClass::down()
{
	dir=2;
	speed++;
	if (speed > MAXSPEED)
		speed = MAXSPEED;

}


void arrowClass::left()
{
	dir=3;
	speed++;
	if (speed > MAXSPEED)
		speed = MAXSPEED;

}

void arrowClass::right()
{
	dir=1;
	speed++;
	if (speed > MAXSPEED)
		speed = MAXSPEED;

}
int arrowClass::getDirection()
{
	return dir;
}
int arrowClass::getSpeed()
{
	return speed;
}
int arrowClass::getX()
{
	return x;
}
int arrowClass::getY()
{
	return y;
}
void arrowClass::move_arrow(int width, int height)
{

	//update arrow position based on direction
	switch(dir)
	{
	case 0:
		y -= speed;
		break;
	case 1:
		x += speed;
		break;
	case 2:
		y += speed;
		break;
	case 3:
		x -= speed;
	}

	//keep arrow inside the screen
	if (x > width-64)//adjusted for new sprite size
	{
		x = width-64;//adjusted for new sprite size
		speed = 0;
	}
	if (x < 0)
	{
		x = 0;
		speed = 0;
	}
	if (y > height-64)//adjusted for new sprite size
	{
		y = height-64;//adjusted for new sprite size
		speed = 0;
	}
	if (y < 0)
	{
		y = 0;
		speed = 0;
	}
}
