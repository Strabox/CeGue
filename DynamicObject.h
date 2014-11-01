#ifndef DYNAMICOBJECT_H
#define DYNAMICOBJECT_H

#include <stdlib.h>
#include "glut.h"
#include "GameObject.h"
#include "Vector3.h"
#include <time.h>
#include <cmath>

class DynamicObject : public GameObject {

protected:

	Vector3 _speed;

	double _speed_multiplier;

public:

	DynamicObject(Box box): GameObject(box){
		_speed_multiplier = 1.0;
		_speed = Vector3(0.0, 0.0, 0.0);
	}

	~DynamicObject(){}


	void setSpeed(const Vector3 &speed){ 
		_speed = speed; 
	}

	void setSpeed(double x, double y, double z){ 
		_speed.set(x, y, z);
	}

	public: double getSpeedMultiplier(){
		return _speed_multiplier;
	}

	Vector3 getSpeed(){ 
		return _speed; 
	}

	virtual void update(int delta_t){
		double _x, _vx;
		Vector3 pos = getPosition();
		Vector3 distance = getSpeed();
		
		distance = distance *(((double)delta_t / 1000)*_speed_multiplier);
		setPosition(pos + distance);
		pos = getPosition();
		
		_x = pos.getX();
		_vx = distance.getX();

		if ( (_x < -7.5) && (_vx < 0.0) ){			//If an object is beyond the left wall
			setPosition(_x + 15,pos.getY(),pos.getZ()); //and moving left, he gets respawned
		}
		else if ((_x > +7.5) && (_vx > 0.0)){			//If an object is beyond the right wall
			setPosition(_x - 15, pos.getY(), pos.getZ()); //and moving right, he gets respawned
		}
	}

};

#endif