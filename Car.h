#ifndef CAR_H
#define CAR_H
#include "glut.h"
#include "DynamicObject.h"


class Car : public DynamicObject {
public:
	Car(){
		collxmin = -0.6;
		collxmax = 0.6;
		collymin = -0.5;
		collymax = 0.5;
	}
	~Car(){}
	
	int checkColisions(double frogbottom, double frogleft, double frogtop, double frogright){
		double selfleft = getPosition()->getX() + collxmin;
		double selfright = getPosition()->getX() + collxmax;
		double selfbottom = getPosition()->getY() + collymin;
		double selftop = getPosition()->getY() + collymax;
		//bool
		
		if (!(selfleft > frogright || selfright < frogleft || selfbottom > frogbottom || selftop < frogtop)){
			printf("colide\ncolide\ncolide\ncolide\ncolide\ncolide\ncolide\ncolide\ncolide\ncolide\ncolide\ncolide\ncolide\ncolide\ncolide\n");
			return 1;
		}
		printf("car:\nleft %f \t right %f\ntop %f \t bottom%f\n", selfleft, selfright, selftop, selfbottom);
		printf("frog:\nleft %f \t right %f\ntop %f \t bottom%f\n", frogleft, frogright, frogtop, frogbottom);
		printf("%d %d %d %d", selfleft > frogright, selfright < frogleft, selfbottom > frogbottom, selftop < frogtop);

		return 0;
		
	}

	void draw(){
		Vector3* vector = getPosition();
		glPushMatrix();
		glTranslatef(vector->getX(), vector->getY(), vector->getZ());
		
		//front/rear
		glPushMatrix();
		glTranslatef(0.0, 0.0, -0.3);
		glColor3f(0.0, 0.5, 1.0);
		glScalef(2.0, 1.0, 0.5);
		glutSolidCube(0.6);
		glPopMatrix();
		//roof:
		glPushMatrix();
		glTranslatef(0.1, 0.0, -0.1);
		glColor3f(1.0, 1.0, 0.75);
		glScalef(1.0, 1.0, 0.5);
		glutSolidCube(0.5);
		glPopMatrix();

		glPushMatrix();
		glTranslatef(0.4, 0.3, -0.4);
		glColor3f(0.25, 0.25, 0.25);
		glutSolidSphere(0.1, 12, 12);
		glPopMatrix();

		glPushMatrix();
		glTranslatef(0.4, -0.3, -0.4);
		glColor3f(0.25, 0.25, 0.25);
		glutSolidSphere(0.1, 12, 12);
		glPopMatrix();

		glPushMatrix();
		glTranslatef(-0.4, 0.3, -0.4);
		glColor3f(0.25, 0.25, 0.25);
		glutSolidSphere(0.1, 12, 12);
		glPopMatrix();

		glPushMatrix();
		glTranslatef(-0.4, -0.3, -0.4);
		glColor3f(0.25, 0.25, 0.25);
		glutSolidSphere(0.1, 12, 12);
		glPopMatrix();


		glPopMatrix();
	}
};

#endif