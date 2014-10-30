#ifndef RIVER_H
#define RIVER_H
#include "glut.h"
#include "StaticObject.h"


class River : public StaticObject {

	public:

	River(){
		collxmin = -6.0;
		collxmax = 6.0;
		collymin = -2.2;
		collymax = 2.2;
	}

	~River(){}

	int answerToColision(){ return 5; }			// 5 = above water

	void draw(){
		Vector3* vector = getPosition();

		GLfloat mat_specular[] = {0.0, 0.0, 1.0, 0.7 };
		GLfloat shininess = 0.76;

		glPushMatrix();
		glTranslatef(vector->getX(), vector->getY(), vector->getZ());
		
		glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
		glMaterialf(GL_FRONT, GL_SHININESS, shininess);

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