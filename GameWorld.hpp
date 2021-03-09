#ifndef ASCIIROAD_GAMEWORLD_H
#define ASCIIROAD_GAMEWORLD_H

class GameWorld {
	char **world;
	int w_y, w_x;
public:
	GameWorld(int a_y, int a_x);
	~GameWorld();

	bool Draw(const struct object_info *obj, int y, int x,
		bool replace);
	void RedrawCh(int y, int x);
	void Update();
};

#endif /* ASCIIROAD_GAMEWORLD_H */
