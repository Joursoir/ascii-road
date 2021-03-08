#include <ncurses.h>

#include "Vehicle.hpp"
#include "veh_models.hpp"

bool Vehicle::Draw(int bound_x)
{
	bool ret = false;
	int i, j, k;
	const struct vehicle_info car = veh_info[type];

	for(i = pos_x, j = car.length-1; i >= 0 && j >= 0; i--, j--) {
		if(i >= bound_x)
			continue;
		ret = true;

		int h = car.height;
		for(k = 0; k < h; k++) {
			if(car.model[k][j] != SUPPORT_CHAR)
				mvaddch(pos_y - (h - k), i, car.model[k][j]);
		}
	}

	return ret;
}
