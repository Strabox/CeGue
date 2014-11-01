#ifndef FROG_H
#define FROG_H

#include <vector>
#include <Windows.h>
#include "glut.h"
#include "DynamicObject.h"
#include "Car.h"
#include "resource.h"

#define FROG_SPEED_MODULE 4.0
#define MAX_LIVES 5

#define FROG_DIMENSION_YMIN -0.3
#define FROG_DIMENSION_YMAX 0.3
#define FROG_DIMENSION_XMIN -0.3
#define FROG_DIMENSION_XMAX 0.3

class Frog : public DynamicObject {

private:

	int _lives;
	
	Vector3 _platformSpeed;

	double _zRotation;

	/* Position/Collision Flags */
	bool _ground; 

	bool _water;

	bool _logOrTurtle;

public:

	Frog() : DynamicObject(Box(FROG_DIMENSION_XMIN, FROG_DIMENSION_XMAX, FROG_DIMENSION_YMIN, FROG_DIMENSION_YMAX)) {
		_lives = MAX_LIVES;
		_zRotation=0;
		_platformSpeed = Vector3(0.0, 0.0, 0.0);
		_ground = true;
		_water = false;
		_logOrTurtle = false;
	}

	~Frog(){}

	int getLives(){
		return _lives;
	}

	void setZRotation(double z){ _zRotation = z;}

	void moveDown(){
		setZRotation(180.0);
		Vector3 new_speed;
		new_speed = _platformSpeed + Vector3(0.0, -FROG_SPEED_MODULE, 0.0);
		setSpeed(new_speed);
	}

	void moveUp(){
		setZRotation(0.0);
		Vector3 new_speed;
		new_speed = _platformSpeed + Vector3(0.0, FROG_SPEED_MODULE, 0.0);
		setSpeed(new_speed);
	}

	void moveLeft(){
		setZRotation(90.0);
		Vector3 new_speed;
		new_speed = _platformSpeed + Vector3(-FROG_SPEED_MODULE, 0.0, 0.0);
		setSpeed(new_speed);
	}

	void moveRight(){
		setZRotation(-90.0);
		Vector3 new_speed;
		new_speed = _platformSpeed + Vector3(FROG_SPEED_MODULE, 0.0, 0.0);
		setSpeed(new_speed);
	}

	void stopMovement(){
		setSpeed(_platformSpeed);
	}

	/* checkIfCollided() - Verifies if frog collided with game objects.*/
	int checkIfColided(std::vector <GameObject *> collidable){
		std::vector<GameObject* >::iterator iter = collidable.begin();
		int colision_type = 0;
		_ground = false;
		_water = false;
		_logOrTurtle = false;

		for (iter; iter != collidable.end(); iter++){
			if ((int) this == (int)*iter) continue;			//Collision with itself.
			
			colision_type = (*iter)->checkColisions(getPosition(),getBox());
			
			if (colision_type == 1){						//Crashed with a car/bus.	
				winOrDie();
				_lives--;
				break;
			}
			else if (colision_type == 6){					//WIN 
				winOrDie();
				break;
			}
			else if (colision_type == 4) _ground = true;	//It is in the ground.
			else if (colision_type == 5) _water = true;		//Fall in water.
			else if (colision_type == 2){					//Its is in a turtle or log.
				_logOrTurtle = true;
				break;
			}
		}
		
		if (_ground){
			_platformSpeed = Vector3(0.0, 0.0, 0.0);
			return 0;										 //ground keeps the frog safe from the water
		}
		else if (_water){
			if (!_logOrTurtle){								//the frog will survive the water if there's a log or a turtle
				winOrDie();
				_lives--;
				return 0;
			}
			else{
				_platformSpeed = (*iter)->getSpeed();
			}
		}

		return 0;
	}

	void winOrDie(){
		setPosition(0.0, 0.0, 0.0);
		_platformSpeed = Vector3(0.0, 0.0, 0.0);
		setSpeed(0.0, 0.0, 0.0);
		PlaySound((LPCWSTR)IDR_WAVE1, NULL, SND_RESOURCE | SND_ASYNC);
	}

	void update(int delta_t){
		double _x, _y;
		Vector3 distance = getSpeed();

		distance = distance * ((double)delta_t / 1000);
		setPosition(getPosition() + distance);
		_x = getPosition().getX();
		_y = getPosition().getY();
		if (_x > 5.5 - FROG_DIMENSION_XMAX){
			setPosition(5.5 - FROG_DIMENSION_XMAX, getPosition().getY(), getPosition().getZ());
		}
		else if (_x < -5.5 - FROG_DIMENSION_XMIN){
			setPosition(5.5 - FROG_DIMENSION_XMIN, getPosition().getY(), getPosition().getZ());
		}
		if (_y > 12.5 - FROG_DIMENSION_YMAX){
			setPosition(getPosition().getX(), 12.5 - FROG_DIMENSION_YMAX, getPosition().getZ());
		}
		else if (_y < -0.5 - FROG_DIMENSION_YMIN){
			setPosition(getPosition().getX(), -0.5 - FROG_DIMENSION_YMIN, getPosition().getZ());
		}
	}

	void draw(){
		Vector3 vector = getPosition();
		GLfloat mat_specular[] = { 0.0, 1.0, 0.0, 1.0 };
		GLfloat shininess = 0.25;

		glPushMatrix();

		glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
		glMaterialf(GL_FRONT, GL_SHININESS, shininess);

		glTranslatef(vector.getX(), vector.getY(), vector.getZ()-0.25);
		glRotatef(_zRotation, 0, 0, 1.0);
		glScalef(0.5, 0.5, 0.5);

		glPushMatrix();								//front leg
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
		
		glPushMatrix();								// body
		glColor3f(0.5, 1.0, 0.5);
		glTranslatef(0.0, -0.1, -0.1);
		glutSolidSphere(0.3, 16, 16);
		glPopMatrix();
		
		glPushMatrix();								//head
		glColor3f(0.0, 1.0, 0.0);
		glTranslatef(0.0, 0.2, 0.2);
		glutSolidSphere(0.2, 12, 12);
		glPopMatrix();
		
		glPopMatrix();
	}

};

#endif