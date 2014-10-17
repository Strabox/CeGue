#ifndef CAMERA_H
#define CAMERA_H

#include "glut.h"
#include "Entity.h"

class Camera : public Entity {

	protected: Vector3 up;

	protected: Vector3 at;

	protected: Vector3 near;

	protected: Vector3 far;

	public:Camera(){}

	public:~Camera(){};


};

#endif