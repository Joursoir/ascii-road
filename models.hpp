#ifndef ASCIIROAD_MODELS_H
#define ASCIIROAD_MODELS_H

#define SUPPORT_CHAR '?'
/* SUPPORT_CHAR use for support rectangular array */ 

struct object_info {
	const char * const *model;
	int length;
	int height;
};

#endif /* ASCIIROAD_MODELS_H */
