#ifndef VECTOR3_H
#define VECTOR3_H
#include "glut.h"

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
	void setX(double x){ _x = x; }
	void setY(double y){ _y = y; }
	void setZ(double z){ _z = z; }
	void set(double x, double y, double z){ _x = x; _y = y; _z = z; }
	void addVector3(Vector3* toAdd){
		_x += toAdd->getX();
		_y += toAdd->getY();
		_z += toAdd->getZ();
	}
	void multiplyScale(double scale){
		_x *= scale;
		_y *= scale;
		_z *= scale;
	}
	Vector3* makeCopy(Vector3* orig){
		Vector3* copy = new Vector3();
		copy->setX(orig->getX());
		copy->setY(orig->getY());
		copy->setZ(orig->getZ());
		return copy;
	}

};

#endif