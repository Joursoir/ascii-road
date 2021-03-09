#include <ncurses.h>
#include <stdlib.h>

#include "GameWorld.hpp"
#include "bg_models.hpp"
#include "veh_models.hpp"

GameWorld::GameWorld(int y, int x)
	: w_y(y), w_x(x)
{
	int i, j; //, k, h;
	world = new char*[y];

	for(i = 0; i < y; i++) {
		world[i] = new char[x+1];
		for(j = 0; j < x; j++)
			world[i][j] = ' ';
		world[i][x] = '\0';
	}

	// generate road
	move(y-1, 0);
	for(i = 0; i < x; i++) {
		world[y-1][i] = '_';
		addch('_');
	}

	// generate bridge
	for(i = 0; i < x; i += bg_store[bg_bridge].length)
		Draw(&bg_store[bg_bridge], bg_store[bg_bridge].height-1, i, true);

	// generate water

	// generate trees
	i = 0;
	while(i < x) {
		const struct object_info *tree = &bg_store[rand() % bg_tree_types_max];
		Draw(tree, y-1, i, true);
		i += tree->length + rand() % 10;
	}
}

GameWorld::~GameWorld()
{
	int i;
	for(i = 0; i < w_y; i++)
		delete[] world[i];
	delete[] world;
}

bool GameWorld::Draw(const struct object_info *obj, int y, int x,
	bool replace)
{
	// draw from down left corner
	bool ret = false;
	int i, j, k, h;
	int length = obj->length;
	for(i = x, j = 0; (i < w_x) && (j < length); i++, j++) {
		if(i < 0)
			continue;
		ret = true;

		h = obj->height - 1;
		for(k = 0; k <= h; k++) {
			char ch = obj->model[k][j];
			if(ch != SUPPORT_CHAR) {
				if(replace)
					world[y - (h - k)][i] = ch;
				mvaddch(y - (h - k), i, ch);
			}
			else RedrawCh(y - (h - k), i);
		}
	}
	return ret;
}

void GameWorld::RedrawCh(int y, int x)
{
	mvaddch(y, x, world[y][x]);
}

void GameWorld::Update()
{
	refresh();
}
