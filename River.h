#ifndef RIVER_H
#define RIVER_H
#include "glut.h"
#include "StaticObject.h"


class River : public StaticObject {
public:

	River(){
		collxmin = -6.0;
		collxmax = 6.0;
		collymin = -2.5;
		collymax = 2.5;
	}

	~River(){}

	int answerToColision(){ printf("river\n"); return 5; } // 5 = above water

	void draw(){
		Vector3* vector = getPosition();
		glPushMatrix();
		glTranslatef(vector->getX(), vector->getY(), vector->getZ());

		glPushMatrix();
		glTranslatef(0.0, 0.0, -0.25);
		glColor3f(0.25, 0.5, 1.0);
		glScalef(11.0, 5.0, 0.5); //area do rio
		glutSolidCube(1.0);
		glPopMatrix();

		glPopMatrix();
	}

};

#endif