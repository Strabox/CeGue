#ifndef BLACKWALL_H
#define BLACKWALL_H
#include "glut.h"
#include "Entity.h"


class BlackWall : public Entity {
public:

	BlackWall(){
		setPosition(0.0, 6.5, 0.0);
	}

	~BlackWall(){}

	void draw(){
		Vector3* vector = getPosition();
		glPushMatrix();
		glTranslatef(vector->getX(), vector->getY(), vector->getZ());

		glPushMatrix();
			glTranslatef(0.0, -6.5, -1.0);
			glColor3f(0.0, 0.0, 0.0);
			glPushMatrix();
				glTranslatef(-5.5, 0.0, 0.0);
				glBegin(GL_TRIANGLES);
				glVertex3f(0, 0, 0); //perto, a superficie   |_\.
				glVertex3f(0, 13.0, 0); //longe, a superficie
				glVertex3f(0, 0, 10.0); //perto, no ar
				glEnd();
				glBegin(GL_TRIANGLES);
				glVertex3f(0, 0, 10.0);
				glVertex3f(0, 13.0, 0);
				glVertex3f(0, 13.0, 10.0);
				glEnd();
			glPopMatrix();
			glPushMatrix();
				glTranslatef(5.5, 0.0, 0.0);
				glBegin(GL_TRIANGLES);
				glVertex3f(0, 0, 0); //perto, a superficie   |_\.
				glVertex3f(0, 13.0, 0); //longe, a superficie
				glVertex3f(0, 0, 10.0); //perto, no ar
				glEnd();
				glBegin(GL_TRIANGLES);
				glVertex3f(0, 0, 10.0);
				glVertex3f(0, 13.0, 0);
				glVertex3f(0, 13.0, 10.0);
				glEnd();
			glPopMatrix();
			glPushMatrix();
				glTranslatef(0.0, 6.5, 0.0);
				glBegin(GL_TRIANGLES);
				glVertex3f(-5.5, 0, 0); //esq inf   |_\.
				glVertex3f(5.5, 0, 0); //dir inf
				glVertex3f(-5.5, 0, 10.0); //esq sup
				glEnd();
				glBegin(GL_TRIANGLES);
				glVertex3f(5.5, 0, 0);
				glVertex3f(5.5, 0.0, 10.0);
				glVertex3f(-5.5, 0.0, 10.0);
				glEnd();
			glPopMatrix();
		glPopMatrix();

		glPopMatrix();
	}

};

#endif