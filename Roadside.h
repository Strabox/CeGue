#ifndef ROADSIDE_H
#define ROADSIDE_H
#include "glut.h"
#include "StaticObject.h"


class Roadside : public StaticObject {
public:

	Roadside(){
		collxmin = -6.0;
		collxmax = 6.0;
		collymin = -0.5;
		collymax = 0.5;
	}

	~Roadside(){}

	int answerToColision(){ printf("road\n"); return 4; } // 4 = ground

	void draw(){
		Vector3* vector = getPosition();
		glPushMatrix();
		glTranslatef(vector->getX(), vector->getY(), vector->getZ());

		glPushMatrix();
		glTranslatef(0.0, 0.0, 0.0);
		glScalef(11.0, 1.0, 1.0);
		glColor3f(0.0, 0.25, 0.0);
		glutSolidCube(1.0);
		glPopMatrix();

		glPopMatrix();
	}

};

#endif