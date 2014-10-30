#ifndef VECTOR4_H
#define VECTOR4_H

#include "Vector3.h"

class Vector4 : public Vector3{

	private: double _w;


	public: Vector4(double x,double y,double z,double w): Vector3(x,y,z){
		_w = w;
	}

	public: Vector4(){}

	public: ~Vector4(){}


	public: double getW(){
		return _w;
	}
	
	public: double setW(double w){
		_w = w;
	}

	public: void set(double x, double y, double z, double w){
		_x = x;
		_y = y;
		_z = z;
		_w = w;
	}
	
	Vector4 operator+(const Vector4& vec){
		Vector4 res;
		res._x = this->getX() + vec._x;
		res._y = this->getY() + vec._y;
		res._z = this->getZ() + vec._z;
		res._w = this->getW() + vec._w;
		return res;
	}

	Vector4 operator-(const Vector4& vec){
		Vector4 res;
		res._x = this->getX() - vec._x;
		res._y = this->getY() - vec._y;
		res._z = this->getZ() - vec._z;
		res._w = this->getW() - vec._w;
		return res;
	}

	Vector4 operator*(double multiplier){
		Vector4 res;
		res._x = this->getX() * multiplier;
		res._y = this->getY() * multiplier;
		res._z = this->getZ() * multiplier;
		res._w = this->getW() * multiplier;
		return res;
	}

	Vector4 operator=(const Vector4& vec){
		Vector4 res;
		this->setX(vec._x);
		this->setY(vec._y);
		this->setZ(vec._z);
		this->_w = vec._w;
		return res;
	}

};

#endif