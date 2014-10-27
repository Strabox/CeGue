#ifndef FROG_H
#define FROG_H
#include <vector>
#include "glut.h"
#include "DynamicObject.h"
#include "Car.h"

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

	void moveDown(int direction){
		setZRotation(180.0);
		if (direction == 0){		//If its turned West
			Vector3* new_speed = new Vector3(0.0, 0.0, 0.0);
			new_speed->addVector3(platformSpeed);
			new_speed->addVector3(new Vector3(0.0, -FROG_SPEED_MODULE, 0.0));
			setSpeed(new_speed);
		}
		else if (direction == 1){	//If its turned South
			Vector3* new_speed = new Vector3(0.0, 0.0, 0.0);
			new_speed->addVector3(platformSpeed);
			new_speed->addVector3(new Vector3(0.0, -FROG_SPEED_MODULE, 0.0));
			setSpeed(new_speed);
		}
		else if (direction == 2){	//If its turned East
			Vector3* new_speed = new Vector3(0.0, 0.0, 0.0);
			new_speed->addVector3(platformSpeed);
			new_speed->addVector3(new Vector3(0.0, -FROG_SPEED_MODULE, 0.0));
			setSpeed(new_speed);
		}
		else if (direction == 3){	//If its turned North
			Vector3* new_speed = new Vector3(0.0, 0.0, 0.0);
			new_speed->addVector3(platformSpeed);
			new_speed->addVector3(new Vector3(0.0, -FROG_SPEED_MODULE, 0.0));
			setSpeed(new_speed);
		}
	}

	void moveUp(int direction){
		setZRotation(0.0);
		Vector3* new_speed = new Vector3(0.0, 0.0, 0.0);
		new_speed->addVector3(platformSpeed);
		new_speed->addVector3(new Vector3(0.0, FROG_SPEED_MODULE, 0.0));
		setSpeed(new_speed);
	}

	void moveLeft(int direction){
		setZRotation(90.0);
		Vector3* new_speed = new Vector3(0.0, 0.0, 0.0);
		new_speed->addVector3(platformSpeed);
		new_speed->addVector3(new Vector3(-FROG_SPEED_MODULE, 0.0, 0.0));
		setSpeed(new_speed);
	}

	void moveRight(int direction){
		setZRotation(-90.0);
		Vector3* new_speed = new Vector3(0.0, 0.0, 0.0);
		new_speed->addVector3(platformSpeed);
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
			if ((int) this == (int)*iter) continue;
			
			colision_type = ((*iter)->checkColisions(pos->getY() + FROG_DIMENSION_YMIN, pos->getX() + FROG_DIMENSION_XMIN, pos->getY() + FROG_DIMENSION_YMAX, pos->getX() + FROG_DIMENSION_XMAX));
			
			if (colision_type == 1){
				die();
				break;
			}

			else if (colision_type == 3) ground = true;
			else if (colision_type == 5) water = true;
			else if (colision_type == 2){
				logOrTurtle = true;
				break;
			}
		}

		if (ground) return 0; //ground keeps the frog safe from the water
		
		else if (water){
			if (!logOrTurtle){ //the frog will survive the water if there's a 
				die();
				return 0;
			}
			else{
				platformSpeed = (*iter)->getSpeed();
			}
		}

		return 0;
	}

	void die(){
		setPosition(0.0, 0.0, 0.0);
		platformSpeed = new Vector3(0.0, 0.0, 0.0);
		setSpeed(0.0, 0.0, 0.0);
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