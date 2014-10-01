#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H
#include "glut.h"
#include "Entity.h"
#include "stdio.h"

class GameObject : public Entity {
public:
	GameObject() : Entity(){}
	~GameObject(){}
	virtual void draw(){
		printf("An empty instance of GameObject was created.\n");
	}
	void update(double delta_t){}
};

#endif