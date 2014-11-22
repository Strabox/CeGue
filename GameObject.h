#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include "glut.h"
#include "Entity.h"
#include "stdio.h"
#include "Box.h"

/* Class GameObject - Abstract Class represents all objects in game.*/
class GameObject : public Entity {

private:

	Box _hitBox;

public:

	GameObject(Box box) : Entity(){
		_hitBox = box;
	}

	~GameObject(){}


	public: Box getBox(){
		return _hitBox;
	}

	virtual void draw(){}

	virtual void update(int delta_t){}

	virtual int checkColisions(Vector3 frogPos,Box frogBox){
		if (Box::Collided(frogBox, frogPos, _hitBox, getPosition()))
			return answerToColision();
		else
			return 0;
	}

	virtual int answerToColision(){ return -1; }

	virtual Vector3 getSpeed(){ return Vector3(0.0, 0.0, 0.0); }
};

#endif