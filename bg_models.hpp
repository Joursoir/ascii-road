#ifndef ASCIIROAD_BGMODELS_H
#define ASCIIROAD_BGMODELS_H

#include "models.hpp"

enum background_types {
	bg_ftree,
	bg_stree,
	bg_tree_types_max,
	bg_bridge = bg_tree_types_max
};

const char * const bg_ftree_model[] = {
	"       _-_       ",
	"    /~~   ~~\\    ",
	" /~~         ~~\\ ",
	"{               }",
	" \\  _-     -_  / ",
	"   ~  \\\\ //  ~   ",
	"       | |       ",
	"       | |       ",
	"      // \\\\      "
};

const char * const bg_stree_model[] = {
	"       _____       ",
	"    __/~~~~~\\__    ",
	"  _/~~       ~~\\_  ",
	" /~             ~\\ ",
	"{                 }",
	" \\__\\~       ~/__/ ",
	"    \\_      _/     ",
	"      \\\\  //       ",
	"       |  |        ",
	"       |  |        ",
	"       |  |        ",
	"      //  \\\\       "
};

const char * const bg_bridge_model[] = {
	"                  ..                   ",
	"                  []                   ",
	"                ,:[]:_                 ",
	"             ,-: :[]: :-.              ",
	"          ,.': : :[]: : :`._           ",
	"      _,-: : : : :[]: : : : :-._       ",
	"___.-: : : : : : :[]: : : : : : :-.____",
	"_:_:_:_:_:_:_:_:_:[]:_:_:_:_:_:_:_:_:_:",
	"!!!!!!!!!!!!!!!!!![]!!!!!!!!!!!!!!!!!!!",
	"^^^^^^^^^^^^^^^^^^[]^^^^^^^^^^^^^^^^^^^",
	"                  []                   ",
	"                  []                   ",
	"                  []                   "
};

const struct object_info bg_store[] = {
	{bg_ftree_model, 17, 9},
	{bg_stree_model, 19, 12},
	{bg_bridge_model, 39, 13}
};

#endif /* ASCIIROAD_BGMODELS_H */