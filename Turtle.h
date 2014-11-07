#ifndef TURTLE_H
#define TURTLE_H

#include "glut.h"
#include "DynamicObject.h"
#include <stdio.h>

class Turtle : public DynamicObject {

public:

	Turtle():DynamicObject(Box(-1.35,1.35,-0.2,0.2)){}

	~Turtle(){}

	int answerToColision(){ return 2; }					// 2 = must float

	void draw(){
		Vector3 vector = getPosition();
		GLfloat mat_specular_pernas[] = { 0.1, 0.75, 0.1, 1.0 };
		GLfloat mat_ambient_pernas[] = { 0.1, 0.5, 0.1, 1.0 };
		GLfloat mat_diffuse_pernas[] = { 0.1, 0.5, 0.1, 1.0 };
		GLfloat shininess_pernas = 1;

		GLfloat mat_specular_corpo[] = { 0.25, 0.15, 0.1, 1.0 };
		GLfloat mat_ambient_corpo[] = { 0.25, 0.15, 0.1, 1.0 };
		GLfloat mat_diffuse_corpo[] = { 0.25, 0.15, 0.1, 1.0 };
		GLfloat shininess_corpo = 1;
		
		glPushMatrix();
		glTranslatef(vector.getX()-1, vector.getY(), vector.getZ());

		//turtle 1
		glTranslatef(+0.0, 0.0, 0.0);

		glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular_corpo);
		glMaterialf(GL_FRONT, GL_SHININESS, shininess_corpo);
		glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient_corpo);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_ambient_corpo);

		glPushMatrix();
		glTranslatef(0.0, 0.0, 0.2);
		glColor3f(0.5, 0.25, 0.1);
		glScalef(1.0, 0.75, 0.5);
		glutSolidSphere(0.35, 8, 8);
		glPopMatrix();
		
		glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular_pernas);
		glMaterialf(GL_FRONT, GL_SHININESS, shininess_pernas);
		glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient_pernas);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_ambient_pernas);

		glPushMatrix();
		glColor3f(0.5, 1.0, 0.0);
		glTranslatef(-0.4, 0.0, 0.1);
		glScalef(0.3, 0.25, 0.25);
		glutSolidSphere(0.35, 8, 8);
		glPopMatrix();

		glPushMatrix();
		glTranslatef(-0.15, 0.3, 0.1);
		glColor3f(0.5, 1.0, 0.0);
		glutSolidSphere(0.1, 8, 8);
		glPopMatrix();

		glPushMatrix();
		glTranslatef(-0.15, -0.3, 0.1);
		glColor3f(0.5, 1.0, 0.0);
		glutSolidSphere(0.1, 8, 8);
		glPopMatrix();

		glPushMatrix();
		glTranslatef(0.3, 0.25, 0.1);
		glColor3f(0.5, 1.0, 0.0);
		glutSolidSphere(0.1, 8, 8);
		glPopMatrix();

		glPushMatrix();
		glTranslatef(0.3, -0.25, 0.1);
		glColor3f(0.5, 1.0, 0.0);
		glutSolidSphere(0.1, 8, 8);
		glPopMatrix();
		
		//turtle 2
		glTranslatef(+1.0, 0.0, 0.0);

		glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular_corpo);
		glMaterialf(GL_FRONT, GL_SHININESS, shininess_corpo);
		glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient_corpo);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_ambient_corpo);

		glPushMatrix();
		glTranslatef(0.0, 0.0, 0.2);
		glColor3f(0.5, 0.25, 0.1);
		glScalef(1.0, 0.75, 0.5);
		glutSolidSphere(0.35, 8, 8);
		glPopMatrix();

		glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular_pernas);
		glMaterialf(GL_FRONT, GL_SHININESS, shininess_pernas);
		glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient_pernas);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_ambient_pernas);

		glPushMatrix();
		glColor3f(0.5, 1.0, 0.0);
		glTranslatef(-0.4, 0.0, 0.1);
		glScalef(0.3, 0.25, 0.25);
		glutSolidSphere(0.35, 8, 8);
		glPopMatrix();

		glPushMatrix();
		glTranslatef(-0.15, 0.3, 0.1);
		glColor3f(0.5, 1.0, 0.0);
		glutSolidSphere(0.1, 8, 8);
		glPopMatrix();

		glPushMatrix();
		glTranslatef(-0.15, -0.3, 0.1);
		glColor3f(0.5, 1.0, 0.0);
		glutSolidSphere(0.1, 8, 8);
		glPopMatrix();

		glPushMatrix();
		glTranslatef(0.3, 0.25, 0.1);
		glColor3f(0.5, 1.0, 0.0);
		glutSolidSphere(0.1, 8, 8);
		glPopMatrix();

		glPushMatrix();
		glTranslatef(0.3, -0.25, 0.1);
		glColor3f(0.5, 1.0, 0.0);
		glutSolidSphere(0.1, 8, 8);
		glPopMatrix();

		//turtle 3
		glTranslatef(+1.0, 0.0, 0.0);

		glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular_corpo);
		glMaterialf(GL_FRONT, GL_SHININESS, shininess_corpo);
		glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient_corpo);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_ambient_corpo);

		glPushMatrix();
		glTranslatef(0.0, 0.0, 0.2);
		glColor3f(0.5, 0.25, 0.1);
		glScalef(1.0, 0.75, 0.5);
		glutSolidSphere(0.35, 8, 8);
		glPopMatrix();

		glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular_pernas);
		glMaterialf(GL_FRONT, GL_SHININESS, shininess_pernas);
		glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient_pernas);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_ambient_pernas);

		glPushMatrix();
		glColor3f(0.5, 1.0, 0.0);
		glTranslatef(-0.4, 0.0, 0.1);
		glScalef(0.3, 0.25, 0.25);
		glutSolidSphere(0.35, 8, 8);
		glPopMatrix();

		glPushMatrix();
		glTranslatef(-0.15, 0.3, 0.1);
		glColor3f(0.5, 1.0, 0.0);
		glutSolidSphere(0.1, 8, 8);
		glPopMatrix();

		glPushMatrix();
		glTranslatef(-0.15, -0.3, 0.1);
		glColor3f(0.5, 1.0, 0.0);
		glutSolidSphere(0.1, 8, 8);
		glPopMatrix();

		glPushMatrix();
		glTranslatef(0.3, 0.25, 0.1);
		glColor3f(0.5, 1.0, 0.0);
		glutSolidSphere(0.1, 8, 8);
		glPopMatrix();

		glPushMatrix();
		glTranslatef(0.3, -0.25, 0.1);
		glColor3f(0.5, 1.0, 0.0);
		glutSolidSphere(0.1, 8, 8);
		glPopMatrix();

		glPopMatrix();
	}
};

#endif