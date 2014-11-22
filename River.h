#ifndef RIVER_H
#define RIVER_H

#include "glut.h"
#include "SOIL.h"
#include "StaticObject.h"

class River : public StaticObject {

public:

	River():StaticObject(Box(-6.0,6.0,-2.2,2.2)){}

	~River(){}

	int answerToColision(){ return 5; }			// 5 = above water

	void draw(){
		Vector3 vector = getPosition();
		GLfloat mat_specular[] = {0.2, 0.2, 0.5, 1.0 };
		GLfloat mat_ambient[] = { 0.1, 0.1, 0.25, 1.0 };
		GLfloat mat_diffuse[] = { 0.5, 0.5, 0.75, 1.0 };
		GLfloat shininess = 1;

		glPushMatrix();
		glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
		glMaterialf(GL_FRONT, GL_SHININESS, shininess);
		glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_ambient);
		glTranslatef(vector.getX(), vector.getY(), vector.getZ());

		for (double y = -2.25; y <= 2.25; y += 0.5){
			for (double x = -5.25; x <= 5.25; x += 0.5){
				glPushMatrix();
				glTranslatef(x, y, -0.5);
				glColor3f(0.25, 0.5, 1.0);
				glBegin(GL_QUADS);
				glNormal3f(0.0, 0.0, 1.0);
				glTexCoord2f(0, 0);
				glVertex3f(-0.25, -0.25, 0.5);
				glNormal3f(0.0, 0.0, 1.0);
				glTexCoord2f(1, 0);
				glVertex3f(0.25, -0.25, 0.5);
				glNormal3f(0.0, 0.0, 1.0);
				glTexCoord2f(1, 1);
				glVertex3f(0.25, 0.25, 0.5);
				glNormal3f(0.0, 0.0, 1.0);
				glTexCoord2f(0, 1);
				glVertex3f(-0.25, 0.25, 0.5);
				glEnd();
				glPopMatrix();
			}
		}

		glPopMatrix();
	}

};

#endif