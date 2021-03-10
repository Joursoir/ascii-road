#include <ncurses.h>
#include <stdlib.h>
#include <time.h>

#include "GameWorld.hpp"
#include "Vehicle.hpp"
#include "models.hpp"
#include "veh_models.hpp"

int main(int argc, char *argv[])
{
	int total_rows, total_cols;
	initscr();
	noecho();
	curs_set(0);
	srand(time(0));

	getmaxyx(stdscr, total_rows, total_cols);
	struct timespec my_timer;
	my_timer.tv_sec = 0;
	my_timer.tv_nsec = 50000000; // 100000000

	GameWorld *world = new GameWorld(total_rows, total_cols);
	Vehicle *car = 0;
	struct ll_vehicle *ptr_first = new struct ll_vehicle(0, 0);
	struct ll_vehicle *ptr;
	int wait_move = 0;
	for(;;) {

		ptr = ptr_first;
		while(ptr)
		{
			car = ptr->data;
			if(!car) {
				if(wait_move > 0)
					break;

				int type = rand() % veh_types_max;
				ptr->data = new Vehicle(type, total_rows-1, -veh_store[type].length);
				car = ptr->data;
				wait_move = veh_store[type].length + 3 + rand() % 10;

				ptr->next = new struct ll_vehicle(0, 0);
			}
						
			if(!car->MoveRight(world)) {
				ptr = ptr->next;
				delete car;
				delete ptr_first;
				ptr_first = ptr;
				continue;
			}

			ptr = ptr->next;
		}

		wait_move--;
		world->Update();
		nanosleep(&my_timer, NULL);
	}

	endwin();
	return 0;
}
