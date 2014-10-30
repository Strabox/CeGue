#ifndef ROAD_H
#define ROAD_H
#include "glut.h"
#include "StaticObject.h"


class Road : public StaticObject {
public:

	Road(){
		collxmin = -6.0;
		collxmax = 6.0;
		collymin = -2.5;
		collymax = 2.5;
	}

	~Road(){}

	int answerToColision(){ return 4; } // 4 = ground

	void draw(){
		Vector3* vector = getPosition();
		GLfloat mat_specular[] = { 0.0, 0.0, 0.0, 0.7 };
		GLfloat shininess = 0.30;

		glPushMatrix();
		glTranslatef(vector->getX(), vector->getY(), vector->getZ());

		glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
		glMaterialf(GL_FRONT, GL_SHININESS, shininess);

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