#ifndef TIMBERLOG_H
#define TIMBERLOG_H

#include "glut.h"
#include "DynamicObject.h"
#include <stdio.h>

class Timberlog : public DynamicObject {

public:

	Timberlog() : DynamicObject(Box(-1.35,1.35,-0.2,0.2)){}

	~Timberlog(){}

	int answerToColision(){ return 2; }							 //2 = must float

	void draw(){
		GLUquadricObj* quadric = gluNewQuadric();				 //Necessary for Cylinder.
		Vector3 vector = getPosition();
		GLfloat mat_specular[] = { 0.25, 0.15, 0.1, 1.0 };
		GLfloat mat_ambient[] = { 0.25, 0.15, 0.1, 1.0 };
		GLfloat mat_diffuse[] = { 0.25, 0.15, 0.1, 1.0 };
		GLfloat shininess = 15;

		glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
		glMaterialf(GL_FRONT, GL_SHININESS, shininess);
		glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_ambient);
		
		glPushMatrix();
		glTranslatef(vector.getX(), vector.getY(), vector.getZ());
		
		glTranslatef(1.5, 0.0, 0.1);
		glRotatef(270, 0.0, 1.0, 0.0);
		
		glPushMatrix();
		glColor3f(0.25, 0.15, 0.0);
		gluCylinder(quadric, 0.4, 0.4, 3 , 12, 9);
		glPopMatrix();

		glPopMatrix();
	}
};

#endif