#ifndef STATICOBJECT_H
#define STATICOBJECT_H

#include "glut.h"
#include "Entity.h"

/* Class StaticObject - Abstract class represents objects without movement.*/
class StaticObject : public GameObject {

public:

	StaticObject(Box box):GameObject(box){}

	~StaticObject(){}

};

#endif