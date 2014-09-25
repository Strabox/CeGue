#ifndef FROG_H
#define FROG_H
#include <glut.h>
#include "DynamicObject.h"

class Frog : public DynamicObject {
private:
	double zRotation;
public:
	Frog() : DynamicObject() {}
	~Frog(){}
	void setZRotation(double z){ zRotation = z; }
	void draw(){
		Vector3* vector = getPosition();
		glPushMatrix();
		glTranslatef(vector->getX(), vector->getY(), vector->getZ());
		glRotatef(zRotation, 0, 0, 1.0);

		glPushMatrix();
		glColor3f(0.2, 1.0, 0.0);
		glTranslatef(0.0, -0.1, -0.1);
		glutSolidSphere(0.3, 12, 12);
		glPopMatrix();


		glPushMatrix();
		glColor3f(0.0, 1.0, 0.2);
		glTranslatef(0.0, 0.2, -0.2);
		glutSolidSphere(0.2, 8, 8);
		glPopMatrix();


		glPopMatrix();

	}
};

#endif