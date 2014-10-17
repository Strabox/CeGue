#ifndef ROAD_H
#define ROAD_H
#include "glut.h"
#include "StaticObject.h"


class Road : public StaticObject {
public:

	Road(){}

	~Road(){}

	void draw(){
		Vector3* vector = getPosition();
		glPushMatrix();
		glTranslatef(vector->getX(), vector->getY(), vector->getZ());

		glPushMatrix();
		glTranslatef(0.0, 0.0, 0.0);
		glScalef(13.0, 5.0, 1.0);
		glColor3f(0.1, 0.1, 0.1);
		glutSolidCube(1.0);
		glPopMatrix();

		glPopMatrix();
	}

};

#endif