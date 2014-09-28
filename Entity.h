#ifndef ENTITY_H
#define ENTITY_H
#include "glut.h"
#include "Vector3.h"


class Entity {
protected:
	Vector3* _position;
public:
	Entity(){}
	~Entity(){}
	Vector3* getPosition(){ return _position; }
	void setPosition(Vector3 &p){ _position = &p; }
	void setPosition(double x, double y, double z){ _position = new Vector3(x,y,z); }
};

#endif