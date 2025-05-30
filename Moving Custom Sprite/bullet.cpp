#include "bullet.h"
bullet::bullet()
{
	alive = false;;
	bullet_bmp = nullptr;
}
bool bullet::getStatus()
{
	return alive;
}

void bullet::fire()
{
	x=rand()%615+10;
	y = 10;
	alive=true;

}
void bullet::erase_bullet()
{
	al_draw_filled_rectangle(x, y, x + 16, y + 16, al_map_rgb(0,0,0)); //black color and adjust for new bullet size
}
int bullet::move_bullet (int arrowX, int arrowY, int width, int length, int height)//updated to adjust for new bullet size
{
	y++;
	//al_draw_filled_rectangle(x,y,x+5,y+5,al_map_rgb(255,255,0));//yellow color
	al_draw_bitmap(bullet_bmp, x, y, 0);//draws bitmap of bullet on specified location

	if (x + 16 > arrowX && x < arrowX+width && y + 16 > arrowY && y < arrowY+length) {//updated collision space to account for a 64x64 sprite
		al_draw_filled_rectangle(x, y, x + 16, y + 16, al_map_rgb(0, 0, 0)); //BLACK
		alive = false;
		return 1;
	}
	if (y > height)
		alive = false;
	return 0;
}
bullet::~bullet()
{
	if (bullet_bmp) {
		al_destroy_bitmap(bullet_bmp);
	}
}
void bullet::create_bullet_bitmap(ALLEGRO_DISPLAY* display)
{
	bullet_bmp = al_create_bitmap(16, 16);//16x16 bitmap
	if (!bullet_bmp)
	{
		al_destroy_display(display);
		exit(1);
	}

	al_set_target_bitmap(bullet_bmp);

	int r = rand() % 255;
	int n = rand() % 255;
	int g = rand() % 255;
	//triforce sprite as "bullets"
	al_draw_filled_triangle(8, 2, 4, 8, 12, 8, al_map_rgb(r, n, g));
	al_draw_filled_triangle(4, 8, 0, 14, 8, 14, al_map_rgb(r, n, g));
	al_draw_filled_triangle(12, 8, 8, 14, 16, 14, al_map_rgb(r, n, g));
}