#ifndef TIMBERLOG_H
#define TIMBERLOG_H
#include "glut.h"
#include "DynamicObject.h"
#include <stdio.h>

class Timberlog : public DynamicObject {
public:
	Timberlog() : DynamicObject(){
		collxmin = -1.35;
		collxmax = 1.35;
		collymin = -0.2;
		collymax = 0.2;
	}
	~Timberlog(){}

	int answerToColision(){ return 2; } // 2 = must float

	void draw(){
		GLUquadricObj* quadric = gluNewQuadric(); //isto é preciso para o cilindro
		Vector3* vector = getPosition();
		glPushMatrix();
		glTranslatef(vector->getX(), vector->getY(), vector->getZ());
		glTranslatef(1.5, 0.0, 0.1);
		glRotatef(270, 0.0, 1.0, 0.0);
		
		glPushMatrix();
		glColor3f(0.25, 0.15, 0.0);
		gluCylinder(quadric, 0.4, 0.4, 3 , 12, 3);
		glPopMatrix();

		glPopMatrix();
	}
};

#endif