#ifndef CAR_H
#define CAR_H

#include "glut.h"
#include "DynamicObject.h"

class Car : public DynamicObject {

public:

	Car():DynamicObject(Box(-0.6,0.6,-0.3,0.3)){}

	~Car(){}

	int answerToColision(){ return 1; }						// 1 = being run over

	void draw(){
		Vector3 vector = getPosition();
		//corpo do carro - azul
		GLfloat mat_specular_corpo[] = { 0.0, 0.0, 1.0, 1.0 };
		GLfloat mat_ambient_corpo[] = { 0.2, 0.2, 0.5, 1.0 };
		GLfloat mat_diffuse_corpo[] = { 0.5, 0.5, 0.5, 1.0 };
		GLfloat shininess_corpo = 10;
		//vidros - branco
		GLfloat mat_specular_vidros[] = { 0.75, 0.75, 0.75, 1.0 };
		GLfloat mat_ambient_vidros[] = { 0.75, 0.75, 0.75, 1.0 };
		GLfloat mat_diffuse_vidros[] = { 0.75, 0.75, 0.75, 1.0 };
		GLfloat shininess_vidros = 50;
		//farois
		GLfloat mat_specular_farois[] = { 1.0, 0.0, 0.0, 1.0 };
		GLfloat mat_ambient_farois[] = { 0.5, 0.2, 0.0, 1.0 };
		GLfloat mat_diffuse_farois[] = { 0.75, 0.5, 0.5, 1.0 };
		GLfloat shininess_farois = 10;
		//pneus
		GLfloat mat_specular_pneus[] = { 0.2, 0.2, 0.2, 1.0 };
		GLfloat mat_ambient_pneus[] = { 0.2, 0.2, 0.2, 1.0 };
		GLfloat mat_diffuse_pneus[] = { 0.2, 0.2, 0.2, 1.0 };
		GLfloat shininess_pneus = 10;


		glEnable(GL_NORMALIZE);		
		glPushMatrix();
		glTranslatef(vector.getX(), vector.getY(), vector.getZ() - 0.3);

		//corpo do carro inteiro, sem luzes e vidros
		glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular_corpo);
		glMaterialf(GL_FRONT, GL_SHININESS, shininess_corpo);
		glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient_corpo);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_ambient_corpo);
		
		//roof
		//top
		glColor3f(0.0, 0.5, 1.0);
		glBegin(GL_POLYGON);
		glNormal3f(-1, 0, 1);
		glVertex3f(-0.1, 0, 0.4);
		glNormal3f(-1, -1, 1);
		glVertex3f(0.0, -0.15, 0.4);
		glNormal3f(1, -1, 1);
		glVertex3f(0.2, -0.15, 0.4);
		glNormal3f(1, 0, 1);
		glVertex3f(0.3, 0.0, 0.4);
		glNormal3f(1, 1, 1);
		glVertex3f(0.2, 0.15, 0.4);
		glNormal3f(-1, 1, 1);
		glVertex3f(0.0, 0.15, 0.4);
		glEnd();
		//rear
		//esquerdo
		glBegin(GL_POLYGON);
		glNormal3f(1, -1, 1);
		glVertex3f(0.2, -0.15, 0.4);
		glNormal3f(1, -1, 1);
		glVertex3f(0.35, -0.3, 0.25);
		glNormal3f(1, -1, 1);
		glVertex3f(0.45, -0.15, 0.25);
		glNormal3f(1, 0, 1);
		glVertex3f(0.3, 0.0, 0.4);
		glEnd();
		//direito
		glBegin(GL_POLYGON);
		glNormal3f(1, 1, 1);
		glVertex3f(0.2, 0.15, 0.4);
		glNormal3f(1, 0, 1);
		glVertex3f(0.3, 0.0, 0.4);
		glNormal3f(1, 1, 1);
		glVertex3f(0.45, 0.15, 0.25);
		glNormal3f(1, 1, 1);
		glVertex3f(0.35, 0.3, 0.25);
		glEnd();

		//body (carrocaria sem para-choques frontal e traseiro
		glColor3f(0.0, 0.5, 1.0);
		//lados
		//esquerdo
		glBegin(GL_POLYGON);
		glNormal3f(0, -1, 1);
		glVertex3f(-0.25, -0.3, 0.25);
		glNormal3f(0, -1, 0);
		glVertex3f(-0.25, -0.3, -0.1);
		glNormal3f(0.25, -1, 0);
		glVertex3f(0.45, -0.3, -0.1);
		glNormal3f(0.25, -1, 1);
		glVertex3f(0.45, -0.3, 0.25);
		glEnd();
		//right
		glBegin(GL_POLYGON);
		glNormal3f(0, 1, 1);
		glVertex3f(-0.25, 0.3, 0.25);
		glNormal3f(0.25, 1, 1);
		glVertex3f(0.45, 0.3, 0.25);
		glNormal3f(0.25, 1, 0);
		glVertex3f(0.45, 0.3, -0.1);
		glNormal3f(0, 1, 1);
		glVertex3f(-0.25, 0.3, -0.1);
		glEnd();
		//top
		glBegin(GL_POLYGON);
		glNormal3f(0, -1, 1);
		glVertex3f(-0.25, -0.3, 0.25);
		glNormal3f(0.25, -1, 1);
		glVertex3f(0.45, -0.3, 0.25);
		glNormal3f(0.25, 1, 1);
		glVertex3f(0.45, 0.3, 0.25);
		glNormal3f(0, 1, 1);
		glVertex3f(-0.25, 0.3, 0.25);
		glEnd();

		//para-choques
		//da frente
		glColor3f(0.0, 0.5, 1.0);
		//topo
		glBegin(GL_POLYGON);
		glNormal3f(0, -1, 1);
		glVertex3f(-0.25, -0.3, 0.25);
		glNormal3f(-1, -1, 1);
		glVertex3f(-0.75, -0.25, 0.1);
		glNormal3f(-1, 1, 1);
		glVertex3f(-0.75, 0.25, 0.1);
		glNormal3f(0, 1, 1);
		glVertex3f(-0.25, 0.3, 0.25);
		glEnd();
		//parte da frente
		glBegin(GL_POLYGON);
		glNormal3f(-1, -1, 1);
		glVertex3f(-0.75, -0.25, 0.1);
		glNormal3f(-1, -1, 0);
		glVertex3f(-0.75, -0.25, 0.0);
		glNormal3f(-1, 1, 0);
		glVertex3f(-0.75, 0.25, 0.0);
		glNormal3f(-1, 1, 1);
		glVertex3f(-0.75, 0.25, 0.1);
		glEnd();
		//sides
		//esquerda
		glBegin(GL_POLYGON);
		glNormal3f(0, -1, 1);
		glVertex3f(-0.25, -0.3, 0.25);
		glNormal3f(-1, -1, 1);
		glVertex3f(-0.75, -0.25, 0.1);
		glNormal3f(-1, -1, 0);
		glVertex3f(-0.75, -0.25, 0.0);
		glNormal3f(0, -1, 0);
		glVertex3f(-0.25, -0.3, -0.1);
		glEnd();
		//direita
		glBegin(GL_POLYGON);
		glNormal3f(0, 1, 1);
		glVertex3f(-0.25, 0.3, 0.25);
		glNormal3f(0, 1, 1);
		glVertex3f(-0.25, 0.3, -0.1);
		glNormal3f(-1, 1, 0);
		glVertex3f(-0.75, 0.25, 0.0);
		glNormal3f(-1, 1, 1);
		glVertex3f(-0.75, 0.25, 0.1);
		glEnd();
		//para-choques
		//de tras
		glColor3f(0.0, 0.5, 1.0);
		//topo
		glBegin(GL_POLYGON);
		glNormal3f(0.25, -1, 1);
		glVertex3f(0.45, -0.3, 0.25);
		glNormal3f(0.25, -1, 0);
		glVertex3f(0.65, -0.15, 0.15);
		glNormal3f(0.25, 1, 0);
		glVertex3f(0.65, 0.15, 0.15);
		glNormal3f(0.25, 1, 1);
		glVertex3f(0.45, 0.3, 0.25);
		glEnd();
		//fundo
		glBegin(GL_POLYGON);
		glNormal3f(0.25, -1, 0);
		glVertex3f(0.65, -0.15, 0.15);
		glNormal3f(0.25, -1, 0);
		glVertex3f(0.45, -0.3, -0.1);
		glNormal3f(0.25, 1, 0);
		glVertex3f(0.45, 0.3, -0.1);
		glNormal3f(0.25, 1, 0);
		glVertex3f(0.65, 0.15, 0.15);
		glEnd();
		//painel esquerdo
		glBegin(GL_TRIANGLES);
		glNormal3f(0.25, -1, 0);
		glVertex3f(0.45, -0.3, 0.15);
		glNormal3f(0.25, -1, 0);
		glVertex3f(0.45, -0.3, -0.1);
		glNormal3f(0.25, -1, 0);
		glVertex3f(0.65, -0.15, 0.15);
		glEnd();
		//painel direito
		glBegin(GL_TRIANGLES);
		glNormal3f(0.25, 1, 0);
		glVertex3f(0.45, 0.3, 0.15);
		glNormal3f(0.25, 1, 0);
		glVertex3f(0.65, 0.15, 0.15);
		glNormal3f(0.25, 1, 0);
		glVertex3f(0.45, 0.3, -0.1);
		glEnd();

		//farois traseiros
		glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular_farois);
		glMaterialf(GL_FRONT, GL_SHININESS, shininess_farois);
		glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient_farois);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_ambient_farois);
		
		glColor3f(0.5, 0.0, 0.0);
		//esquerdo
		glBegin(GL_TRIANGLES);
		glNormal3f(0.25, -1, 1);
		glVertex3f(0.45, -0.3, 0.25);
		glNormal3f(0.25, -1, 0);
		glVertex3f(0.45, -0.3, 0.15);
		glNormal3f(0.25, -1, 0);
		glVertex3f(0.65, -0.15, 0.15);
		glEnd();
		//direito
		glBegin(GL_TRIANGLES);
		glNormal3f(0.25, 1, 1);
		glVertex3f(0.45, 0.3, 0.25);
		glNormal3f(0.25, 1, 0);
		glVertex3f(0.65, 0.15, 0.15);
		glNormal3f(0.25, 1, 0);
		glVertex3f(0.45, 0.3, 0.15);
		glEnd();



		//vidros
		glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular_vidros);
		glMaterialf(GL_FRONT, GL_SHININESS, shininess_vidros);
		glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient_vidros);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_ambient_vidros);
		
		glColor3f(0.75, 0.75, 0.75);
		//frente
		//esquerdo
		glBegin(GL_POLYGON);
		glNormal3f(-1, -1, 1);
		glVertex3f(0.0, -0.15, 0.4);
		glNormal3f(-1, 0, 1);
		glVertex3f(-0.1, 0, 0.4);
		glNormal3f(-1, -1, 1);
		glVertex3f(-0.25, -0.15, 0.25);
		glNormal3f(-1, -1, 1);
		glVertex3f(-0.15, -0.3, 0.25);
		glEnd();
		//direito
		glBegin(GL_POLYGON);
		glNormal3f(-1, 1, 1);
		glVertex3f(0.0, 0.15, 0.4);
		glNormal3f(-1, 1, 1);
		glVertex3f(-0.15, 0.3, 0.25);
		glNormal3f(-1, 1, 1);
		glVertex3f(-0.25, 0.15, 0.25);
		glNormal3f(-1, 0, 1);
		glVertex3f(-0.1, 0, 0.4);
		glEnd();
		//lados
		//esquerdo
		glBegin(GL_POLYGON);
		glNormal3f(-1, -1, 1);
		glVertex3f(0.0, -0.15, 0.4);
		glNormal3f(-1, -1, 1);
		glVertex3f(-0.15, -0.3, 0.25);
		glNormal3f(1, -1, 1);
		glVertex3f(0.35, -0.3, 0.25);
		glNormal3f(1, -1, 1);
		glVertex3f(0.2, -0.15, 0.4);
		glEnd();
		//direito
		glBegin(GL_POLYGON);
		glNormal3f(-1, 1, 1);
		glVertex3f(0.0, 0.15, 0.4);
		glNormal3f(1, 1, 1);
		glVertex3f(0.2, 0.15, 0.4);
		glNormal3f(1, 1, 1);
		glVertex3f(0.35, 0.3, 0.25);
		glNormal3f(-1, 1, 1);
		glVertex3f(-0.15, 0.3, 0.25);
		glEnd();
		//traseiro
		glBegin(GL_TRIANGLES);
		glNormal3f(1, 0, 1);
		glVertex3f(0.3, 0.0, 0.4);
		glNormal3f(1, -1, 1);
		glVertex3f(0.45, -0.15, 0.25);
		glNormal3f(1, 1, 1);
		glVertex3f(0.45, 0.15, 0.25);
		glEnd();
		//frente
		glBegin(GL_TRIANGLES);
		glNormal3f(-1, 0, 1);
		glVertex3f(-0.1, 0.0, 0.4);
		glNormal3f(-1, 1, 1);
		glVertex3f(-0.25, 0.15, 0.25);
		glNormal3f(-1, -1, 1);
		glVertex3f(-0.25, -0.15, 0.25);
		glEnd();


		//pneus
		glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular_pneus);
		glMaterialf(GL_FRONT, GL_SHININESS, shininess_pneus);
		glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient_pneus);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_ambient_pneus);
		
		class Pneu{					//FUNC-CEPTION
		public:
			static void drawPneu(){
				glColor3f(0.5, 0.5, 0.5);
				glBegin(GL_POLYGON);
				glNormal3f(0, -1, -1);
				glVertex3f(0, -0.05, -1.0);
				glNormal3f(-1, -1, -0.85);
				glVertex3f(-0.85, -0.05, -0.5);
				glNormal3f(-1, -1, 0.85);
				glVertex3f(-0.85, -0.05, 0.5);
				glNormal3f(0, -1, 1);
				glVertex3f(0, -0.05, 1.0);
				glNormal3f(1, -1, 0.85);
				glVertex3f(0.85, -0.05, 0.5);
				glNormal3f(1, -1, -0.85);
				glVertex3f(0.85, -0.05, -0.5);
				glEnd();
				glBegin(GL_POLYGON);
				glNormal3f(0, 1, -1);
				glVertex3f(0, 0.05, -1.0);
				glNormal3f(1, 1, -0.85);
				glVertex3f(0.85, 0.05, -0.5);
				glNormal3f(1, 1, 0.85);
				glVertex3f(0.85, 0.05, 0.5);
				glNormal3f(0, 1, 1);
				glVertex3f(0, 0.05, 1.0);
				glNormal3f(-1, 1, 0.85);
				glVertex3f(-0.85, 0.05, 0.5);
				glNormal3f(-1, 1, -0.85);
				glVertex3f(-0.85, 0.05, -0.5);
				glEnd();
				glColor3f(0.1, 0.1, 0.1);
				glBegin(GL_QUAD_STRIP);
				glNormal3f(0, -1, -1);
				glVertex3f(0, -0.05, -1.0);
				glNormal3f(0, 1, -1);
				glVertex3f(0, 0.05, -1.0);
				glNormal3f(1, -1, -0.85);
				glVertex3f(0.85, -0.05, -0.5);
				glNormal3f(-1, 1, -0.85);
				glVertex3f(-0.85, 0.05, -0.5);
				glNormal3f(1, -1, 0.85);
				glVertex3f(0.85, -0.05, 0.5);
				glNormal3f(-1, 1, 0.85);
				glVertex3f(-0.85, 0.05, 0.5);
				glNormal3f(0, -1, 1);
				glVertex3f(0, -0.05, 1.0);
				glNormal3f(0, 1, 1);
				glVertex3f(0, 0.05, 1.0);
				glNormal3f(-1, -1, 0.85);
				glVertex3f(-0.85, -0.05, 0.5);
				glNormal3f(1, 1, 0.85);
				glVertex3f(0.85, 0.05, 0.5);
				glNormal3f(-1, -1, -0.85);
				glVertex3f(-0.85, -0.05, -0.5);
				glNormal3f(1, 1, -0.85);
				glVertex3f(0.85, 0.05, -0.5);
				glEnd();

				glColor3f(0.1, 0.1, 0.1);

			}
		};
		//desenhar os 4
		//frente direita
		glPushMatrix();
			glTranslatef(-0.3, -0.3, 0.0);
			glScalef(0.2, 0.5, 0.2);
			Pneu::drawPneu();
		glPopMatrix();
		//frente esquerda
		glPushMatrix();
			glTranslatef(-0.3, 0.3, 0.0);
			glRotatef(180, 0.0, 0.0, 1.0);
			glScalef(0.2, 0.5, 0.2);
			Pneu::drawPneu();
		glPopMatrix();
		//tras direita
		glPushMatrix();
		glTranslatef(0.3, -0.3, 0.0);
		glScalef(0.2, 0.5, 0.2);
		Pneu::drawPneu();
		glPopMatrix();
		//tras esquerda
		glPushMatrix();
		glTranslatef(0.3, 0.3, 0.0);
		glRotatef(180, 0.0, 0.0, 1.0);
		glScalef(0.2, 0.5, 0.2);
		Pneu::drawPneu();
		glPopMatrix();


		glPopMatrix();

		glNormal3f(0, 0, 1);
		glDisable(GL_NORMALIZE);
	}
};

#endif