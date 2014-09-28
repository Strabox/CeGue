#ifndef DYNAMICOBJECT_H
#define DYNAMICOBJECT_H

#include <glut.h>
#include "GameObject.h"
#include "Vector3.h"

class DynamicObject : public GameObject {
protected:
	Vector3* _speed;
public:
	DynamicObject(){}
	~DynamicObject(){}
	void update(double delta_t){}
	void setSpeed(Vector3 &speed){ _speed = &speed; }
	void setSpeed(double x, double y, double z){ _speed = new Vector3(x, y, z); }
	Vector3* getSpeed(){ return _speed; }
};

#endif