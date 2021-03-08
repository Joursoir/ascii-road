#include <ncurses.h>
#include <stdlib.h>
#include <time.h>

#include "Vehicle.hpp"
#include "veh_models.hpp"

int total_rows, total_cols;

void draw_line(int y, char ch)
{
	int i;
	move(y, 0);
	for(i = 0; i < total_cols; i++)
		addch(ch);
}

/* This version is a dummy */
void draw_background()
{
	draw_line(total_rows-1, '_'); // road

	mvprintw(total_rows-9, 10, "       _-_");
	mvprintw(total_rows-8, 10, "    /~~   ~~\\");
	mvprintw(total_rows-7, 10, " /~~         ~~\\");
	mvprintw(total_rows-6, 10, "{               }");
	mvprintw(total_rows-5, 10, " \\  _-     -_  /");
	mvprintw(total_rows-4, 10, "   ~  \\\\ //  ~");
	mvprintw(total_rows-3, 10, "       | |");
	mvprintw(total_rows-2, 10, "       | |");
	mvprintw(total_rows-1, 10, "______// \\\\");

	mvprintw(total_rows-9, 40, "       _-_");
	mvprintw(total_rows-8, 40, "    /~~   ~~\\");
	mvprintw(total_rows-7, 40, " /~~         ~~\\");
	mvprintw(total_rows-6, 40, "{               }");
	mvprintw(total_rows-5, 40, " \\  _-     -_  /");
	mvprintw(total_rows-4, 40, "   ~  \\\\ //  ~");
	mvprintw(total_rows-3, 40, "       | |");
	mvprintw(total_rows-2, 40, "       | |");
	mvprintw(total_rows-1, 40, "______// \\\\");

	refresh();
}

Vehicle *get_random_vehicle(int y, int x)
{
	Vehicle *car;
	car = new Vehicle(rand() % veh_types_max, y, x);
	return car;
}

int main(int argc, char *argv[])
{
	initscr();
	noecho();
	curs_set(0);
	srand(time(0));

	struct timespec my_timer;
	my_timer.tv_sec = 0;
	my_timer.tv_nsec = 50000000; // 100000000
	getmaxyx(stdscr, total_rows, total_cols);

	Vehicle *car = 0;
	for(;;)
	{
		clear();
		draw_background();

		if(!car)
			car = get_random_vehicle(total_rows, -1);

		car->MoveRight();
		if(!(car->Draw(total_cols))) {
			delete car;
			car = 0;
		}

		refresh();
		nanosleep(&my_timer, NULL);
	}
	
	endwin();
	return 0;
}
