#ifndef BUS_H
#define BUS_H
#include "glut.h"
#include "DynamicObject.h"


class Bus : public DynamicObject {
public:
	Bus(){
		collxmin = -0.7;
		collxmax = 1.3;
		collymin = -0.4;
		collymax = 0.4;
	}
	~Bus(){}

	int answerToColision(){ return 1; } // 1 = being run over

	void draw(){
		Vector3* vector = getPosition();

		GLfloat mat_specular[] = { 1.0, 1.0, 1.0,1.0};
		GLfloat shininess = 0.55;
		glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
		glMaterialf(GL_FRONT, GL_SHININESS, shininess);

		glPushMatrix();
		glTranslatef(vector->getX(), vector->getY(), vector->getZ());

		glPushMatrix();//capo
		glTranslatef(-0.4, 0.0, -0.1);
		glScalef(1.0, 1.0, 0.5);
		glColor3f(1.0, 1.0, 0.0);
		glutSolidCube(0.6);
		glPopMatrix();

		glPushMatrix(); //cockpit
		glTranslatef(0.5, 0.0, 0.1);
		glColor3f(1.0, 1.0, 0.0);
		glScalef(2.0, 1.0, 1.0);
		glutSolidCube(0.8);
		glPopMatrix();

		glPushMatrix();//paineis sobre as rodas da frente
		glTranslatef(-0.3, 0.0, -0.15);
		glScalef(1.0, 1.0, 0.15);
		glColor3f(1.0, 1.0, 0.0);
		glutSolidCube(0.8);
		glPopMatrix();

		glPushMatrix();
		glTranslatef(-0.45, 0.3, -0.35);
		glColor3f(0.25, 0.25, 0.25);
		glutSolidSphere(0.15, 12, 12);
		glPopMatrix();

		glPushMatrix();
		glTranslatef(-0.45, -0.3, -0.35);
		glColor3f(0.25, 0.25, 0.25);
		glutSolidSphere(0.15, 12, 12);
		glPopMatrix();

		glPushMatrix();
		glTranslatef(0.8, 0.3, -0.3);
		glColor3f(0.25, 0.25, 0.25);
		glutSolidSphere(0.2, 12, 12);
		glPopMatrix();

		glPushMatrix();
		glTranslatef(0.8, -0.3, -0.3);
		glColor3f(0.25, 0.25, 0.25);
		glutSolidSphere(0.2, 12, 12);
		glPopMatrix();


		glPopMatrix();
	}
};

#endif