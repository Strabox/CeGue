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

		Vector3* _speed;

	public:

		DynamicObject(){
			_speed = new Vector3(0.0, 0.0, 0.0);
		}

		~DynamicObject(){}

		virtual void update(int delta_t){
			srand(time(NULL));
			double _x;
			Vector3* pos = getPosition();
			Vector3* distance = getSpeed()->makeCopy();
			distance->multiplyScale( ((double) delta_t / 1000)*speed_multiplier );
			pos->addVector3(distance);
			if ((_x = pos->getX()) < -7.5){
				pos->setX(_x + 15);
				//setSpeed(getSpeed()->getX()*speed_multiplier, 0.0, 0.0);
			}
		}

		void setSpeed(Vector3* speed){ _speed = speed; }

		void setSpeed(double x, double y, double z){ _speed = new Vector3(x, y, z); }

		Vector3* getSpeed(){ return _speed; }
};

#endif