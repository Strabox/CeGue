#ifndef FROG_H
#define FROG_H

#include <vector>
#include <Windows.h>
#include "glut.h"
#include "DynamicObject.h"
#include "Car.h"
#include "resource.h"

#define FROG_SPEED_MODULE 4.0
#define FROG_DIMENSION_YMIN -0.3
#define FROG_DIMENSION_YMAX 0.3
#define FROG_DIMENSION_XMIN -0.3
#define FROG_DIMENSION_XMAX 0.3

class Frog : public DynamicObject {

	private:

	double zRotation;

	Vector3 *platformSpeed;

	/*flags*/
	bool ground;

	bool water;

	bool logOrTurtle;

	public:

	Frog() : DynamicObject() {
		zRotation=0;
		platformSpeed = new Vector3(0.0, 0.0, 0.0);
		ground = true;
		water = false;
		logOrTurtle = false;
	}

	~Frog(){}

	void setZRotation(double z){ zRotation = z; }

	void moveDown(){
		setZRotation(180.0);
		Vector3* new_speed = new Vector3(0.0, 0.0, 0.0);
		new_speed->addVector3(platformSpeed);
		//new_speed->multiplyScale(speed_multiplier);
		new_speed->addVector3(new Vector3(0.0, -FROG_SPEED_MODULE, 0.0));
		setSpeed(new_speed);
	}

	void moveUp(){
		setZRotation(0.0);
		Vector3* new_speed = new Vector3(0.0, 0.0, 0.0);
		new_speed->addVector3(platformSpeed);
		//new_speed->multiplyScale(speed_multiplier);
		new_speed->addVector3(new Vector3(0.0, FROG_SPEED_MODULE, 0.0));
		setSpeed(new_speed);
	}

	void moveLeft(){
		setZRotation(90.0);
		Vector3* new_speed = new Vector3(0.0, 0.0, 0.0);
		new_speed->addVector3(platformSpeed);
		//new_speed->multiplyScale(speed_multiplier);
		new_speed->addVector3(new Vector3(-FROG_SPEED_MODULE, 0.0, 0.0));
		setSpeed(new_speed);
	}

	void moveRight(){
		setZRotation(-90.0);
		Vector3* new_speed = new Vector3(0.0, 0.0, 0.0);
		new_speed->addVector3(platformSpeed);
		//new_speed->multiplyScale(speed_multiplier);
		new_speed->addVector3(new Vector3(FROG_SPEED_MODULE, 0.0, 0.0));
		setSpeed(new_speed);
	}

	void stopMovement(){
		setSpeed(platformSpeed);
	}

	
	int checkIfColided(std::vector <GameObject *> collidable){
		std::vector<GameObject* >::iterator iter = collidable.begin();
		int colision_type = 0;
		ground = false;
		water = false;
		logOrTurtle = false;
		Vector3* pos = getPosition();

		for (iter; iter != collidable.end(); iter++){
			if ((int) this == (int)*iter) continue;		//Collision with itself.
			
			colision_type = ((*iter)->checkColisions(pos->getY() + FROG_DIMENSION_YMIN, pos->getX() + FROG_DIMENSION_XMIN, pos->getY() + FROG_DIMENSION_YMAX, pos->getX() + FROG_DIMENSION_XMAX));
			
			if (colision_type == 1){					//Crashed with a car/bus.	
				winOrDie();
				break;
			}

			else if (colision_type == 6){				//WIN 
				winOrDie();
				break;
			}
			else if (colision_type == 4) ground = true;	//It is in the ground.
			else if (colision_type == 5) water = true;	//Fall in water.
			else if (colision_type == 2){				//Its is in a turtle or log.
				logOrTurtle = true;
				break;
			}
		}
		
		if (ground){
			platformSpeed = new Vector3(0.0, 0.0, 0.0);
			return 0;								 //ground keeps the frog safe from the water
		}

		else if (water){
			if (!logOrTurtle){						//the frog will survive the water if there's a log or a turtle
				winOrDie();
				return 0;
			}
			else{
				platformSpeed = (*iter)->getSpeed();
			}
		}

		return 0;
	}

	void winOrDie(){
		setPosition(0.0, 0.0, 0.0);
		platformSpeed = new Vector3(0.0, 0.0, 0.0);
		setSpeed(0.0, 0.0, 0.0);
		PlaySound((LPCWSTR)IDR_WAVE1, NULL, SND_RESOURCE | SND_ASYNC);
	}

	void update(int delta_t){
		double _x, _y;
		Vector3* pos = getPosition();
		Vector3* distance = getSpeed()->makeCopy();
		distance->multiplyScale((double)delta_t / 1000);
		pos->addVector3(distance);
		_x = pos->getX();
		_y = pos->getY();
		if (_x > 5.5 - FROG_DIMENSION_XMAX){
			pos->setX(5.5 - FROG_DIMENSION_XMAX);
		}
		else if (_x < -5.5 - FROG_DIMENSION_XMIN){
			pos->setX(-5.5 - FROG_DIMENSION_XMIN);
		}
		if (_y > 12.5 - FROG_DIMENSION_YMAX){
			pos->setY(12.5 - FROG_DIMENSION_YMAX);
		}
		else if (_y < -0.5 - FROG_DIMENSION_YMIN){
			pos->setY(-0.5 - FROG_DIMENSION_YMIN);
		}
	}

	void draw(){
		Vector3* vector = getPosition();
		glPushMatrix();
		glTranslatef(vector->getX(), vector->getY(), vector->getZ()-0.25);
		glRotatef(zRotation, 0, 0, 1.0);
		glScalef(0.5, 0.5, 0.5);

		glPushMatrix();		//front leg
		glColor3f(0.0, 1.0, 0.0);
		glTranslatef(0.3, 0.2, -0.45);
		glutSolidCube(0.1);
		glPopMatrix();
		
		glPushMatrix();
		glColor3f(0.0, 1.0, 0.0);
		glTranslatef(-0.3, 0.2, -0.45);
		glutSolidCube(0.1);
		glPopMatrix();
		
		glPushMatrix();
		glColor3f(0.0, 1.0, 0.0);
		glTranslatef(0.3, -0.3, -0.35);
		glutSolidCube(0.3);
		glPopMatrix();
		
		glPushMatrix();
		glColor3f(0.0, 1.0, 0.0);
		glTranslatef(-0.3, -0.3, -0.35);
		glutSolidCube(0.3);
		glPopMatrix();
		
		glPushMatrix();		// body
		glColor3f(0.5, 1.0, 0.5);
		glTranslatef(0.0, -0.1, -0.1);
		glutSolidSphere(0.3, 16, 16);
		glPopMatrix();
		
		glPushMatrix();		//head
		glColor3f(0.0, 1.0, 0.0);
		glTranslatef(0.0, 0.2, 0.2);
		glutSolidSphere(0.2, 12, 12);
		glPopMatrix();
		
		glPopMatrix();
	}

};

#endif