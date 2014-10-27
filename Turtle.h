#ifndef TURTLE_H
#define TURTLE_H
#include "glut.h"
#include "DynamicObject.h"
#include <stdio.h>

class Turtle : public DynamicObject {
public:
	Turtle(){
		collxmin = -1.5;
		collxmax = 1.5;
		collymin = -0.35;
		collymax = 0.35;
	}
	~Turtle(){}

	int answerToColision(){ printf("turtle\n"); return 2; } // 2 = must float

	void draw(){
		Vector3* vector = getPosition();
		glPushMatrix();
		glTranslatef(vector->getX() - 1.0, vector->getY(), vector->getZ());

		//turtle 1
		glTranslatef(+0.0, 0.0, 0.0);

		glPushMatrix();
		glTranslatef(0.0, 0.0, 0.2);
		glColor3f(0.5, 0.25, 0.1);
		glScalef(1.0, 0.75, 0.5);
		glutSolidSphere(0.35, 8, 8);
		glPopMatrix();

		glPushMatrix();
		glColor3f(0.5, 1.0, 0.0);
		glTranslatef(-0.4, 0.0, 0.1);
		glScalef(0.3, 0.25, 0.25);
		glutSolidSphere(0.35, 8, 8);
		glPopMatrix();

		glPushMatrix();
		glTranslatef(-0.15, 0.3, 0.1);
		glColor3f(0.5, 1.0, 0.0);
		glutSolidSphere(0.1, 8, 8);
		glPopMatrix();

		glPushMatrix();
		glTranslatef(-0.15, -0.3, 0.1);
		glColor3f(0.5, 1.0, 0.0);
		glutSolidSphere(0.1, 8, 8);
		glPopMatrix();

		glPushMatrix();
		glTranslatef(0.3, 0.25, 0.1);
		glColor3f(0.5, 1.0, 0.0);
		glutSolidSphere(0.1, 8, 8);
		glPopMatrix();

		glPushMatrix();
		glTranslatef(0.3, -0.25, 0.1);
		glColor3f(0.5, 1.0, 0.0);
		glutSolidSphere(0.1, 8, 8);
		glPopMatrix();
		
		//turtle 2
		glTranslatef(+1.0, 0.0, 0.0);

		glPushMatrix();
		glTranslatef(0.0, 0.0, 0.2);
		glColor3f(0.5, 0.25, 0.1);
		glScalef(1.0, 0.75, 0.5);
		glutSolidSphere(0.35, 8, 8);
		glPopMatrix();

		glPushMatrix();
		glColor3f(0.5, 1.0, 0.0);
		glTranslatef(-0.4, 0.0, 0.1);
		glScalef(0.3, 0.25, 0.25);
		glutSolidSphere(0.35, 8, 8);
		glPopMatrix();

		glPushMatrix();
		glTranslatef(-0.15, 0.3, 0.1);
		glColor3f(0.5, 1.0, 0.0);
		glutSolidSphere(0.1, 8, 8);
		glPopMatrix();

		glPushMatrix();
		glTranslatef(-0.15, -0.3, 0.1);
		glColor3f(0.5, 1.0, 0.0);
		glutSolidSphere(0.1, 8, 8);
		glPopMatrix();

		glPushMatrix();
		glTranslatef(0.3, 0.25, 0.1);
		glColor3f(0.5, 1.0, 0.0);
		glutSolidSphere(0.1, 8, 8);
		glPopMatrix();

		glPushMatrix();
		glTranslatef(0.3, -0.25, 0.1);
		glColor3f(0.5, 1.0, 0.0);
		glutSolidSphere(0.1, 8, 8);
		glPopMatrix();

		//turtle 3
		glTranslatef(+1.0, 0.0, 0.0);

		glPushMatrix();
		glTranslatef(0.0, 0.0, 0.2);
		glColor3f(0.5, 0.25, 0.1);
		glScalef(1.0, 0.75, 0.5);
		glutSolidSphere(0.35, 8, 8);
		glPopMatrix();

		glPushMatrix();
		glColor3f(0.5, 1.0, 0.0);
		glTranslatef(-0.4, 0.0, 0.1);
		glScalef(0.3, 0.25, 0.25);
		glutSolidSphere(0.35, 8, 8);
		glPopMatrix();

		glPushMatrix();
		glTranslatef(-0.15, 0.3, 0.1);
		glColor3f(0.5, 1.0, 0.0);
		glutSolidSphere(0.1, 8, 8);
		glPopMatrix();

		glPushMatrix();
		glTranslatef(-0.15, -0.3, 0.1);
		glColor3f(0.5, 1.0, 0.0);
		glutSolidSphere(0.1, 8, 8);
		glPopMatrix();

		glPushMatrix();
		glTranslatef(0.3, 0.25, 0.1);
		glColor3f(0.5, 1.0, 0.0);
		glutSolidSphere(0.1, 8, 8);
		glPopMatrix();

		glPushMatrix();
		glTranslatef(0.3, -0.25, 0.1);
		glColor3f(0.5, 1.0, 0.0);
		glutSolidSphere(0.1, 8, 8);
		glPopMatrix();

		glPopMatrix();
	}
};

#endif