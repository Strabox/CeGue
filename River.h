#ifndef RIVER_H
#define RIVER_H
#include "glut.h"
#include "StaticObject.h"


class River : public StaticObject {
protected:
	int colorId;
public:
	River(int randomInt){
		colorId = randomInt*10;
		colorId %= 40;
	}
	~River(){}
	void draw(){
		colorId = (++colorId) % 40;
		Vector3* vector = getPosition();
		glPushMatrix();
		glTranslatef(vector->getX(), vector->getY(), vector->getZ());

		glPushMatrix();
		glTranslatef(0.0, 0.0, -0.25);
		if (colorId < 10){
			glColor3f(0.5, 0.5, 1.0);
		}
		else if (colorId < 20){
			glColor3f(0.25, 0.25, 1.0);
		}
		else if (colorId < 30){
			glColor3f(0.25, 0.5, 1.0);
		}
		else{
			glColor3f(0.0, 0.25, 1.0);
		}
		glScalef(1.0, 1.0, 0.5);
		glutSolidCube(1.0);
		glPopMatrix();

		glPopMatrix();
	}
};

#endif