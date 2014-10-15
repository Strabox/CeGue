#ifndef CAMERA_H
#define CAMERA_H
#include "glut.h"
#include "Entity.h"

class Camera : public Entity {
protected:
	Vector3 up;
	Vector3 at;
	Vector3 near;
	Vector3 far;
public:
	Camera(){}
	~Camera(){};


};

#endif