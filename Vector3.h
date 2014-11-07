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

	Vector3(double x, double y, double z){ _x = x; _y = y; _z = z;}

	~Vector3(){}


	double getX(){ return _x; }

	double getY(){ return _y; }

	double getZ(){ return _z; }

	void setX(double x){ _x = x; }

	void setY(double y){ _y = y; }

	void setZ(double z){ _z = z; }

	void set(double x, double y, double z){ _x = x; _y = y; _z = z; }

	Vector3 operator+(const Vector3& vec){
		Vector3 res;
		res._x = this->getX() + vec._x;
		res._y = this->getY() + vec._y;
		res._z = this->getZ() + vec._z;
		return res;
	}

	Vector3 operator-(const Vector3& vec){
		Vector3 res;
		res._x = this->getX() - vec._x;
		res._y = this->getY() - vec._y;
		res._z = this->getZ() - vec._z;
		return res;
	}

	Vector3 operator*(double multiplier){
		Vector3 res;
		res._x = this->getX() * multiplier;
		res._y = this->getY() * multiplier;
		res._z = this->getZ() * multiplier;
		return res;
	}

	void operator=(const Vector3& vec){
		this->setX(vec._x);
		this->setY(vec._y);
		this->setZ(vec._z);
		
	}

};

#endif