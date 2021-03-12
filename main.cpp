#include <ncurses.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#include "GameWorld.hpp"
#include "Vehicle.hpp"
#include "models.hpp"
#include "veh_models.hpp"

#define APP_NAME "aroad" 
const int key_escape = 27;

int main(int argc, char *argv[])
{
	if(argc > 1) {
		if(strcmp(argv[1], "-h") == 0 || strcmp(argv[1], "--help") == 0) {
			printf("Usage: %s [-h, --help]\n"
				"Copyright (C) 2021 Aleksandr D. Goncharov (Joursoir)\n"
				"Control:\n"
				"\t'Q', 'q', 'ESC' - exit app\n"
				"\tKey right - speed up vehicles\n"
				"\tKey left - speed down vehicles\n", APP_NAME);
			return 0;
		}
		printf("%s: invalid argument -- '%s'\n", APP_NAME, argv[1]);
		return 1;
	}
	int total_rows, total_cols;
	initscr();
	noecho();
	curs_set(0);
	srand(time(0));
	nodelay(stdscr, true);
	keypad(stdscr, true);

	getmaxyx(stdscr, total_rows, total_cols);
	struct timespec my_timer;
	my_timer.tv_sec = 0;
	my_timer.tv_nsec = 100000000;

	GameWorld *world = new GameWorld(total_rows, total_cols);
	Vehicle *car = 0;
	struct ll_vehicle *ptr_first = new struct ll_vehicle(0, 0);
	struct ll_vehicle *ptr;
	int wait_move = 0;
	int pressed_button = 0;
	bool flag_ride = true;
	for(;;) {

		/* buttons handling */
		while((pressed_button = getch()) != ERR) {
			if(pressed_button == key_escape ||
				pressed_button == 'Q' ||
				pressed_button == 'q') {
				flag_ride = false;
				break;
			}
			else if(pressed_button == KEY_RIGHT) {
				if(my_timer.tv_nsec > 10000000)
					my_timer.tv_nsec -= 10000000;
			}
			else if(pressed_button == KEY_LEFT) {
				if(my_timer.tv_nsec < 900000000)
					my_timer.tv_nsec += 10000000;
			}
			else
				break;
		}

		/* vehicle road */
		ptr = ptr_first;
		while(ptr)
		{
			car = ptr->data;
			if(!car) {
				if(wait_move > 0)
					break;
				if(!flag_ride)
					break;

				int type = rand() % veh_types_max;
				ptr->data = new Vehicle(type, total_rows-1, -veh_store[type].length);
				car = ptr->data;
				wait_move = veh_store[type].length + 3 + rand() % 10;

				ptr->next = new struct ll_vehicle(0, 0);
			}
			
			ptr = ptr->next;
			if(!car->MoveRight(world)) {
				delete car;
				delete ptr_first;
				ptr_first = ptr;
				if(ptr_first->data == 0) {
					delete ptr_first;
					ptr_first = 0;
					ptr = 0;
				}
			}
		}
		if(ptr_first == 0)
			break;

		wait_move--;
		world->Update();
		nanosleep(&my_timer, NULL);
	}

	delete world;
	endwin();
	return 0;
}
