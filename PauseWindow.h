#ifndef PAUSEWINDOW_H
#define PAUSEWINDOW_H

#include "glut.h"
#include "GameObject.h"

class PauseWindow : public Entity {

public:

	PauseWindow(){}

	~PauseWindow(){}

	void draw(){
		Vector3 vector = getPosition();
		GLfloat mat_specular[] = { 1.0, 1.0, 0.5, 1.0 };
		GLfloat mat_ambient[] = { 1.0, 1.0, 0.5, 1.0 };
		GLfloat shininess = 0;

		glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
		glMaterialf(GL_FRONT, GL_SHININESS, shininess);
		glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_ambient);

		glPushMatrix();
			glTranslatef(vector.getX(), vector.getY(), vector.getZ());
			glColor3f(1.0, 1.0, 0.5);

			glBegin(GL_QUADS);
			glVertex3d(-3, -2, 0);
			glVertex3d(3, -2, 0);
			glVertex3d(3, 2, 0);
			glVertex3d(-3, 2, 0);
			glEnd();

		glPopMatrix();
	}
};

#endif