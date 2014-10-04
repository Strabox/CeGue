#ifndef FROG_H
#define FROG_H
#include "glut.h"
#include <math.h>
#include "DynamicObject.h"

double myRound(double x)
{
	return x >= 0.0f ? floorf(x + 0.5f) : ceilf(x - 0.5f);
}

class Frog : public DynamicObject {
private:
	double zRotation = 0;
public:
	Frog() : DynamicObject() {}
	~Frog(){}
	void setZRotation(double z){ zRotation = z; }
	void moveDown(){
		setZRotation(180.0);
		getPosition()->addVector3(new Vector3(0.0, -1.0, 0.0));
	}
	void moveUp(){
		setZRotation(0.0);
		getPosition()->addVector3(new Vector3(0.0, 1.0, 0.0));
	}
	void moveLeft(){
		setZRotation(90.0);
		getPosition()->addVector3(new Vector3(-1.0, 0.0, 0.0));
	}
	void moveRight(){
		setZRotation(-90.0);
		getPosition()->addVector3(new Vector3(+1.0, 0.0, 0.0));
	}
	void draw(){
		Vector3* vector = getPosition();
		glPushMatrix();
		glTranslatef(vector->getX(), vector->getY(), vector->getZ()-0.25);
		glRotatef(zRotation, 0, 0, 1.0);
		glScalef(0.5, 0.5, 0.5);

		glPushMatrix();		//front leg
		glColor3f(0.0, 1.0, 0.0);
		glTranslatef(0.3, 0.2, -0.45);
		glutSolidCube(0.1);
		glPopMatrix();
		
		glPushMatrix();
		glColor3f(0.0, 1.0, 0.0);
		glTranslatef(-0.3, 0.2, -0.45);
		glutSolidCube(0.1);
		glPopMatrix();
		
		glPushMatrix();
		glColor3f(0.0, 1.0, 0.0);
		glTranslatef(0.3, -0.3, -0.35);
		glutSolidCube(0.3);
		glPopMatrix();
		
		glPushMatrix();
		glColor3f(0.0, 1.0, 0.0);
		glTranslatef(-0.3, -0.3, -0.35);
		glutSolidCube(0.3);
		glPopMatrix();
		
		glPushMatrix();		// body
		glColor3f(0.5, 1.0, 0.5);
		glTranslatef(0.0, -0.1, -0.1);
		glutSolidSphere(0.3, 16, 16);
		glPopMatrix();
		
		glPushMatrix();		//head
		glColor3f(0.0, 1.0, 0.0);
		glTranslatef(0.0, 0.2, 0.2);
		glutSolidSphere(0.2, 12, 12);
		glPopMatrix();
		
		glPopMatrix();

	}
};

#endif