#ifndef RIVER_H
#define RIVER_H
#include <glut.h>
#include "StaticObject.h"


class River : public StaticObject {
public:
	River(){}
	~River(){}
	void draw(){
		Vector3* vector = getPosition();
		glPushMatrix();
		glTranslatef(vector->getX(), vector->getY(), vector->getZ());

		glPushMatrix();
		glTranslatef(0.0, 0.0, 0.0);
		glColor3f(0.5, 0.5, 1.0);
		glutSolidCube(1.0);
		glPopMatrix();

		glPopMatrix();
	}
};

#endif