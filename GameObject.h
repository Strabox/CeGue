#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H
#include "glut.h"
#include "Entity.h"

class GameObject : public Entity {
public:
	GameObject() : Entity(){}
	~GameObject(){}
	void draw(){}
	void update(double delta_t){}
};

#endif