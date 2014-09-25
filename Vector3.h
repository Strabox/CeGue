#ifndef VECTOR3_H
#define VECTOR3_H
#include <glut.h>

class Vector3 {
protected:
	double _x;
	double _y;
	double _z;
public:
	Vector3(){}
	Vector3(double x, double y, double z){ _x = x; _y = y; _z = z; }
	~Vector3(){}
	double getX(){ return _x; }
	double getY(){ return _y; }
	double getZ(){ return _z; }
	void set(double x, double y, double z){ _x = x; _y = y; _z = z; }
	
};

#endif