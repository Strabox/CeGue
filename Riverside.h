#ifndef RIVERSIDE_H
#define RIVERSIDE_H
#include "glut.h"
#include "StaticObject.h"


class Riverside : public StaticObject {
public:

	Riverside(){
		collxmin = -6.0;
		collxmax = 6.0;
		collymin = -0.2;
		collymax = 0.5;
	}

	~Riverside(){}

	int answerToColision(){ return 6; } // 6 = win

	void draw(){
		Vector3* vector = getPosition();
		GLfloat mat_specular[] = { 1.0, 1.0, 0.0, 0.7 };
		GLfloat shininess = 0.30;

		glPushMatrix();
		glTranslatef(vector->getX(), vector->getY(), vector->getZ());

		glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
		glMaterialf(GL_FRONT, GL_SHININESS, shininess);

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