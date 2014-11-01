#ifndef RIVER_H
#define RIVER_H

#include "glut.h"
#include "StaticObject.h"

class River : public StaticObject {

public:

	River():StaticObject(Box(-6.0,6.0,-2.2,2.2)){}

	~River(){}

	int answerToColision(){ return 5; }			// 5 = above water

	void draw(){
		Vector3 vector = getPosition();
		GLfloat mat_specular[] = {0.0, 0.0, 0.1, 1.0 };
		GLfloat mat_ambient[] = { 0.0, 0.0, 0.3, 1.0 };
		GLfloat mat_diffuse[] = { 0.0, 0.0, 0.3, 1.0 };
		GLfloat shininess = 15;

		glPushMatrix();
		glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
		glMaterialf(GL_FRONT, GL_SHININESS, shininess);
		glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_ambient);
		glTranslatef(vector.getX(), vector.getY(), vector.getZ());

		glPushMatrix();
		glTranslatef(0.0, 0.0, -0.25);
		glColor3f(0.25, 0.5, 1.0);
		glScalef(11.0, 5.0, 0.5);				//River area
		glutSolidCube(1.0);
		glPopMatrix();

		glPopMatrix();
	}

};

#endif