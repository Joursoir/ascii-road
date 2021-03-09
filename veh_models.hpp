#ifndef ASCIIROAD_VEHMODELS_H
#define ASCIIROAD_VEHMODELS_H

#include "models.hpp"

enum veh_types {
	veh_default,
	veh_ems,
	veh_cabriolet,
	veh_bus,
	veh_zaz,
	veh_landrover,
	veh_police,
	veh_smalltruck,
	veh_bigtruck,
	veh_bicycle,
	veh_manipulator,
	veh_camper,
	veh_types_max,
};

const char * const veh_default_model[] = {
	"??_______????",
	"?/|_||_\\`.__?",
	"(   _    _ _\\",
	"=`-(_)--(_)-'"
};

const char * const veh_ems_model[] = {
	"o____________<0>??????",
	"|           |@??\\?????",
	"|   EMS     ||_/_\\__??",
	"|-----------|       |?",
	"|  _        |    _  []",
	"`-(_)-----------(_)-'?"
};

const char * const veh_cabriolet_model[] = {
	"???????@??\\???????",
	"?______|_/_>____??",
	"/  _\\<>    |  _ \\?",
	"`-(_)--------(_)-]"
};

const char * const veh_bus_model[] = {
	"?_____________________???",
	"|   |     |     | |@  \\??",
	"|___|_____|_____|_||_/_\\?",
	"|   _  _        | |_    \\",
	"`--(_)(_)---------(_)---'"
};

const char * const veh_zaz_model[] = {
	"?????_____??????",
	"?___/__|__\\____?",
	"|  _   |    _ o)",
	"`-(_)------(_)-'"
};

const char * const veh_landrover_model[] = {
	"?????????___??????",
	"?_______|___\\____?",
	"|o  _   |-  | _ o)",
	"`--(_)-------(_)'?"
};

const char * const veh_police_model[] = {
	"?________<o>_??????",
	"|___][__][__\\\\____?",
	"|o _  PD |-  |_  o)",
	"`-(_)--------(_)-'?"
};

const char * const veh_smalltruck_model[] = {
	"?__________???___???",
	"|          |?|__\\\\_?",
	"|  _    _  |-|  _  |",
	"`-(_)--(_)-'?`-(_)-'"
};

const char * const veh_bigtruck_model[] = {
	"?__________???__________???___???",
	"|          |?|          |?|__\\\\_?",
	"|  _    _  |-|  _    _  |-|  _  |",
	"`-(_)--(_)-'?`-(_)--(_)-'?`-(_)-'"
};

const char * const veh_bicycle_model[] = {
	"???@????",
	"??/?\\>??",
	"?_I--.\\?",
	"(_))\"(_)"
};

const char * const veh_manipulator_model[] = {
	"????????..??",
	"???????//\\\\?",
	"???_??//??\\\\",
	"?_[_]//??(_/",
	"|_____|?????",
	"(O_o_O)?????"
};

const char * const veh_camper_model[] = {
	"?______________???",
	"|            __]??",
	"|  [] [] [] |_\\__?",
	"|                ]",
	"`--(_)-------(_)-'"
};

const struct object_info veh_store[] = {
	{veh_default_model, 13, 4},
	{veh_ems_model, 22, 6},
	{veh_cabriolet_model, 18, 4},
	{veh_bus_model, 25, 5},
	{veh_zaz_model, 16, 4},
	{veh_landrover_model, 18, 4},
	{veh_police_model, 19, 4},
	{veh_smalltruck_model, 20, 4},
	{veh_bigtruck_model, 33, 4},
	{veh_bicycle_model, 8, 4},
	{veh_manipulator_model, 12, 6},
	{veh_camper_model, 18, 5}
};

#endif /* ASCIIROAD_VEHMODELS_H */