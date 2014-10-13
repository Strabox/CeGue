#ifndef DYNAMICOBJECT_H
#define DYNAMICOBJECT_H

#include <math.h>
#include "glut.h"
#include "GameObject.h"
#include "Vector3.h"

class DynamicObject : public GameObject {
protected:
	Vector3* _speed;
public:
	DynamicObject(){}
	~DynamicObject(){}
	void update(int delta_t){
		Vector3* pos = getPosition();
		printf("Xspeed %f\n",getSpeed()->getX());
		Vector3* distance = getSpeed()->makeCopy();
		distance->multiplyScale((double) delta_t / 1000);
		pos->addVector3(distance);
		printf("dyna pos final %f %f %f\n", distance->getX(), distance->getY(), distance->getZ());
		pos->setX( fmod(pos->getX(), 11.0));
	}
	void setSpeed(Vector3 &speed){ _speed = &speed; }
	void setSpeed(double x, double y, double z){ _speed = new Vector3(x, y, z); }
	Vector3* getSpeed(){ return _speed; }
};

#endif