#ifndef ROADSIDE_H
#define ROADSIDE_H
#include "glut.h"
#include "StaticObject.h"


class Roadside : public StaticObject {
public:

	Roadside(){}

	~Roadside(){}

	void draw(){
		Vector3* vector = getPosition();
		glPushMatrix();
		glTranslatef(vector->getX(), vector->getY(), vector->getZ());

		glPushMatrix();
		glTranslatef(0.0, 0.0, 0.0);
		glScalef(13.0, 1.0, 1.0);
		glColor3f(0.0, 0.25, 0.0);
		glutSolidCube(1.0);
		glPopMatrix();

		glPopMatrix();
	}

};

#endif