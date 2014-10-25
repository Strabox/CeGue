#ifndef CAR_H
#define CAR_H
#include "glut.h"
#include "DynamicObject.h"


class Car : public DynamicObject {
public:
	Car(){
		xmin = 0.5;
		xmax = 0.5;
		ymin = 0.25;
		ymax = 0.25;
	}
	~Car(){}
	
	int checkColisions(double bottom, double left, double top, double right){
		return 0;

	}

	void draw(){
		Vector3* vector = getPosition();
		glPushMatrix();
		glTranslatef(vector->getX(), vector->getY(), vector->getZ());
		
		//front/rear
		glPushMatrix();
		glTranslatef(-0.2, 0.0, -0.3);
		glColor3f(0.0, 0.5, 1.0);
		glScalef(1.0, 1.0, 0.5);
		glutSolidCube(0.6);
		glPopMatrix();
		//rear/front
		glPushMatrix();
		glTranslatef(-0.8, 0.0, -0.3);
		glColor3f(0.0, 0.5, 1.0);
		glScalef(1.0, 1.0, 0.5);
		glutSolidCube(0.6);
		glPopMatrix();
		//roof:
		glPushMatrix();
		glTranslatef(-0.4, 0.0, -0.1);
		glColor3f(1.0, 1.0, 0.75);
		glScalef(1.0, 1.0, 0.5);
		glutSolidCube(0.5);
		glPopMatrix();

		glPushMatrix();
		glTranslatef(-0.1, 0.3, -0.4);
		glColor3f(0.25, 0.25, 0.25);
		glutSolidSphere(0.1, 12, 12);
		glPopMatrix();

		glPushMatrix();
		glTranslatef(-0.1, -0.3, -0.4);
		glColor3f(0.25, 0.25, 0.25);
		glutSolidSphere(0.1, 12, 12);
		glPopMatrix();

		glPushMatrix();
		glTranslatef(-0.9, 0.3, -0.4);
		glColor3f(0.25, 0.25, 0.25);
		glutSolidSphere(0.1, 12, 12);
		glPopMatrix();

		glPushMatrix();
		glTranslatef(-0.9, -0.3, -0.4);
		glColor3f(0.25, 0.25, 0.25);
		glutSolidSphere(0.1, 12, 12);
		glPopMatrix();


		glPopMatrix();
	}
};

#endif