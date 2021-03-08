#ifndef ASCIIROAD_VEHICLE_H
#define ASCIIROAD_VEHICLE_H

class Vehicle {
	int type;
	int pos_y, pos_x;
public:
	Vehicle(int a_type, int a_y, int a_x)
		: type(a_type), pos_y(a_y), pos_x(a_x) { }
	~Vehicle() { }

	void MoveRight() { pos_x++; }
	bool Draw(int bound_x); /* return false if not draw anything */
};

#endif /* ASCIIROAD_VEHICLE_H */
