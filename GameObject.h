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

	int checkColisions(double frogbottom, double frogleft, double frogtop, double frogright){
		double selfleft = getPosition()->getX() + collxmin;
		double selfright = getPosition()->getX() + collxmax;
		double selfbottom = getPosition()->getY() + collymin;
		double selftop = getPosition()->getY() + collymax;

		if (!(selfleft > frogright || selfright < frogleft || selfbottom > frogtop || selftop < frogbottom)){
			printf("col\n");
			return answerToColision();
		}
		else {
			printf("ncol\n");
			return 0;
		}
	}
	/* http://www.gamedev.net/page/resources/_/technical/game-programming/swept-aabb-collision-detection-and-response-r3084
	* ver Board-Phasing
	*/
	
	virtual int answerToColision(){ printf("oops\n"); return 0; }

	virtual Vector3* getSpeed(){ return NULL; }
};

#endif