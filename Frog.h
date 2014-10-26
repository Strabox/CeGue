#ifndef FROG_H
#define FROG_H
#include <vector>
#include "glut.h"
#include "DynamicObject.h"
#include "Car.h"

#define FROG_SPEED_MODULE 4.0

class Frog : public DynamicObject {

	private:

	double zRotation;

	Vector3 *platformSpeed;


	/*flags*/
	bool ground;

	bool water;

	bool logOrTurtle;

	bool wall;

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
			colision_type = ((*iter)->checkColisions(pos->getY() - 0.3, pos->getX() - 0.3, pos->getY() + 0.3, pos->getX() + 0.3));
			
			if (colision_type == 1) die();
			else if (colision_type == 2) logOrTurtle = true;
			else if (colision_type == 3) ground = true;
			else if (colision_type == 4) wall = true;
			else if (colision_type == 5) water = true;
		}

		return 0;
	}

	void die(){
		setPosition(0.0, 0.0, 0.0);
		platformSpeed = new Vector3(0.0, 0.0, 0.0);
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