#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H
#include "glut.h"
#include "Entity.h"
#include "stdio.h"

class GameObject : public Entity {
public:
	double collxmin;
	double collxmax;
	double collymin;
	double collymax;
	GameObject() : Entity(){}
	~GameObject(){}
	virtual void draw(){
		printf("An empty instance of GameObject was created.\n");
	}
	virtual void update(int delta_t){}
	virtual int checkColisions(double bottom, double left, double top, double right){ return 0; }
	/* http://www.gamedev.net/page/resources/_/technical/game-programming/swept-aabb-collision-detection-and-response-r3084
	* ver Board-Phasing
	*/
};

#endif