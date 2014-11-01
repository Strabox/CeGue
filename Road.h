#ifndef ROAD_H
#define ROAD_H

#include "glut.h"
#include "StaticObject.h"

class Road : public StaticObject {

public:

	Road() :StaticObject(Box(-6.0, 6.0, -2.5, 2.5)){}

	~Road(){}

	int answerToColision(){ return 4; }				// 4 = ground

	void draw(){
		Vector3 vector = getPosition();
		GLfloat mat_specular[] = { 0.1, 0.1, 0.1, 1.0 };
		GLfloat mat_ambient[] = { 0.2, 0.2, 0.2, 1.0 };
		GLfloat mat_diffuse[] = { 0.2, 0.2, 0.2, 1.0 };
		GLfloat shininess = 5;

		glPushMatrix();
		glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
		glMaterialf(GL_FRONT, GL_SHININESS, shininess);
		glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_ambient);
		glTranslatef(vector.getX(), vector.getY(), vector.getZ());

		glPushMatrix();
		glTranslatef(0.0, 0.0, 0.0);
		glScalef(11.0, 5.0, 1.0);
		glColor3f(0.1, 0.1, 0.1);
		glutSolidCube(1.0);
		glPopMatrix();

		glPopMatrix();
	}

};

#endif