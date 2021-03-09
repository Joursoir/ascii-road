#include <ncurses.h>

#include "Vehicle.hpp"
#include "veh_models.hpp"
#include "GameWorld.hpp"

bool Vehicle::MoveRight(GameWorld *world)
{
	const struct object_info *car = &veh_store[type];
	int h = car->height, i;
	for(i = 0; i < h; i++)
		world->RedrawCh(pos_y - i, pos_x);

	pos_x++;
	return world->Draw(car, pos_y, pos_x, false);
}
