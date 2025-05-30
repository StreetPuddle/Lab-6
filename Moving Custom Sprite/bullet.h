#include <allegro5\allegro.h>
#include <allegro5\allegro_primitives.h>


class bullet
{
public:
	bullet();
	~bullet();
	void fire();
	int move_bullet(int arrowX, int arrowY, int width, int length, int height);
	void erase_bullet();
	bool getStatus();
	void create_bullet_bitmap(ALLEGRO_DISPLAY* display);//bitmap of bullet
private:
	int x,y;
	bool alive;
	ALLEGRO_BITMAP* bullet_bmp;//bitmap of bullet
};

