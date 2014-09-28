#ifndef TIMBERLOG_H
#define TIMBERLOG_H
#include "glut.h"
#include "DynamicObject.h"


class Timberlog : public DynamicObject {
public:
	Timberlog(){}
	~Timberlog(){}
	void draw(){
		GLUquadricObj* quadric = gluNewQuadric(); //isto � preciso para o 
		Vector3* vector = getPosition();
		glPushMatrix();
		glTranslatef(vector->getX(), vector->getY(), vector->getZ());
		glTranslatef(1.5, 0.0, 0.1);
		glRotatef(270, 0.0, 1.0, 0.0);

		glPushMatrix();
		glColor3f(0.5, 0.25, 0.1);
		gluCylinder(quadric, 0.4, 0.4, 3 , 12, 3);
		glPopMatrix();

		glPopMatrix();
	}
};

#endif