#ifndef ROADSIDE_H
#define ROADSIDE_H

#include "glut.h"
#include "StaticObject.h"

class Roadside : public StaticObject {

public:

	Roadside() :StaticObject(Box(-6.0,6.0,-0.5,0.2)){}

	~Roadside(){}

	int answerToColision(){ return 4; }			// 4 = ground

	void draw(){
		Vector3 vector = getPosition();
		GLfloat mat_specular[] = { 0.0, 0.0, 0.1, 1.0 };
		GLfloat mat_ambient[] = { 0.0, 6.0, 0.0, 1.0 };
		GLfloat mat_diffuse[] = { 0.0, 6.0, 0.0, 1.0 };
		GLfloat shininess = 25;

		glPushMatrix();
		glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
		glMaterialf(GL_FRONT, GL_SHININESS, shininess);
		glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_ambient);
		glTranslatef(vector.getX(), vector.getY(), vector.getZ());

		glPushMatrix();
		glTranslatef(0.0, 0.0, 0.0);
		glScalef(11.0, 1.0, 1.0);
		glColor3f(0.0, 0.25, 0.0);
		glutSolidCube(1.0);
		glPopMatrix();

		glPopMatrix();
	}

};

#endif