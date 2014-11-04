#ifndef RIVERSIDE_H
#define RIVERSIDE_H

#include "glut.h"
#include "StaticObject.h"

class Riverside : public StaticObject {

public:

	Riverside():StaticObject(Box(-6.0, 6.0, -0.2, 0.5)){}

	~Riverside(){}


	int answerToColision(){ return 6; }							// 6 = win

	void draw(){
		Vector3 vector = getPosition();
		GLfloat mat_specular[] = { 0.5, 0.5, 0.3, 1.0 };
		GLfloat mat_ambient[] = { 0.75, 0.75, 0.3, 1.0 };
		GLfloat mat_diffuse[] = { 0.75, 0.75, 0.3, 1.0 };
		GLfloat shininess = 100;

		
		glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
		glMaterialf(GL_FRONT, GL_SHININESS, shininess);
		glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_ambient);

		glPushMatrix();
		glTranslatef(vector.getX(), vector.getY(), vector.getZ());

		for (double y = -0.25; y <= 0.25; y += 0.5){
			for (double x = -5.25; x <= 5.25; x += 0.5){
				glPushMatrix();
				glTranslatef(x, y, 0.0);
				glScalef(0.5, 0.5, 1.0);
				glColor3f(1.0, 1.0, 0.5);
				glutSolidCube(1.0);
				glPopMatrix();
			}
		}
		glPopMatrix();
	}

};

#endif