#ifndef BUS_H
#define BUS_H

#include "glut.h"
#include "DynamicObject.h"

class Bus : public DynamicObject {

public:

	Bus():DynamicObject(Box(-0.7,1.3,-0.4,0.4)){}

	~Bus(){}

	int answerToColision(){ return 1; }				// 1 = being run over

	void draw(){
		Vector3 vector = getPosition();
		
		GLfloat mat_specular_corpo[] = { 0.5, 0.5, 0.1, 1.0 };
		GLfloat mat_ambient_corpo[] = { 0.75, 0.75, 0.1, 1.0 };
		GLfloat mat_diffuse_corpo[] = { 0.75, 0.75, 0.1, 1.0 };
		GLfloat shininess_corpo = 1;

		GLfloat mat_specular_rodas[] = { 0.2, 0.2, 0.2, 1.0 };
		GLfloat mat_ambient_rodas[] = { 0.2, 0.2, 0.2, 1.0 };
		GLfloat mat_diffuse_rodas[] = { 0.2, 0.2, 0.2, 1.0 };
		GLfloat shininess_rodas = 10;

		glPushMatrix();
		glTranslatef(vector.getX(), vector.getY(), vector.getZ());

		glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular_corpo);
		glMaterialf(GL_FRONT, GL_SHININESS, shininess_corpo);
		glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient_corpo);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_ambient_corpo);

		glPushMatrix();								//capo
		glTranslatef(-0.4, 0.0, -0.1);
		glScalef(1.0, 1.0, 0.5);
		glColor3f(1.0, 1.0, 0.0);
		glutSolidCube(0.6);
		glPopMatrix();

		glPushMatrix();								//cockpit
		glTranslatef(0.5, 0.0, 0.1);
		glColor3f(1.0, 1.0, 0.0);
		glScalef(2.0, 1.0, 1.0);
		glutSolidCube(0.8);
		glPopMatrix();

		glPushMatrix();								//paineis sobre as rodas da frente
		glTranslatef(-0.3, 0.0, -0.15);
		glScalef(1.0, 1.0, 0.15);
		glColor3f(1.0, 1.0, 0.0);
		glutSolidCube(0.8);
		glPopMatrix();

		//rodas
		glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular_rodas);
		glMaterialf(GL_FRONT, GL_SHININESS, shininess_rodas);
		glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient_rodas);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_ambient_rodas);

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