#ifndef CAR_H
#define CAR_H
#include "glut.h"
#include "DynamicObject.h"


class Car : public DynamicObject {
public:
	Car(){
		collxmin = -0.6;
		collxmax = 0.6;
		collymin = -0.5;
		collymax = 0.5;
	}
	~Car(){}

	int answerToColision(){ printf("car\n"); return 1; } // 1 = death from being run over

	void draw(){
		Vector3* vector = getPosition();
		glPushMatrix();
		glTranslatef(vector->getX(), vector->getY(), vector->getZ());
		
		//front/rear
		glPushMatrix();
		glTranslatef(0.0, 0.0, -0.3);
		glColor3f(0.0, 0.5, 1.0);
		glScalef(2.0, 1.0, 0.5);
		glutSolidCube(0.6);
		glPopMatrix();
		//roof:
		glPushMatrix();
		glTranslatef(0.1, 0.0, -0.1);
		glColor3f(1.0, 1.0, 0.75);
		glScalef(1.0, 1.0, 0.5);
		glutSolidCube(0.5);
		glPopMatrix();

		glPushMatrix();
		glTranslatef(0.4, 0.3, -0.4);
		glColor3f(0.25, 0.25, 0.25);
		glutSolidSphere(0.1, 12, 12);
		glPopMatrix();

		glPushMatrix();
		glTranslatef(0.4, -0.3, -0.4);
		glColor3f(0.25, 0.25, 0.25);
		glutSolidSphere(0.1, 12, 12);
		glPopMatrix();

		glPushMatrix();
		glTranslatef(-0.4, 0.3, -0.4);
		glColor3f(0.25, 0.25, 0.25);
		glutSolidSphere(0.1, 12, 12);
		glPopMatrix();

		glPushMatrix();
		glTranslatef(-0.4, -0.3, -0.4);
		glColor3f(0.25, 0.25, 0.25);
		glutSolidSphere(0.1, 12, 12);
		glPopMatrix();


		glPopMatrix();
	}
};

#endif