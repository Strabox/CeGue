#ifndef RIVER_H
#define RIVER_H
#include "glut.h"
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
		glTranslatef(0.0, 0.0, -0.25);
		glColor3f(0.25, 0.5, 1.0);
		glScalef(13.0, 5.0, 0.5); //area do rio
		glutSolidCube(1.0);
		glPopMatrix();

		glPopMatrix();
	}
};

#endif