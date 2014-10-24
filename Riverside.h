#ifndef RIVERSIDE_H
#define RIVERSIDE_H
#include "glut.h"
#include "StaticObject.h"


class Riverside : public StaticObject {
public:

	Riverside(){}

	~Riverside(){}

	void draw(){
		Vector3* vector = getPosition();
		glPushMatrix();
		glTranslatef(vector->getX(), vector->getY(), vector->getZ());

		glPushMatrix();
		glTranslatef(0.0, 0.0, 0.0);
		glScalef(11.0, 1.0, 1.0);
		glColor3f(1.0, 1.0, 0.5);
		glutSolidCube(1.0);
		glPopMatrix();

		glPopMatrix();
	}

};

#endif