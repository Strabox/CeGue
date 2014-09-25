#ifndef ROADSIDE_H
#define ROADSIDE_H
#include <glut.h>
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
		glColor3f(0.5, 0.5, 0.5);
		glutSolidCube(1.0);
		glPopMatrix();

		glPopMatrix();
	}
};

#endif