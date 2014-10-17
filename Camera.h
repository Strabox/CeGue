#ifndef CAMERA_H
#define CAMERA_H

#include "glut.h"
#include "Entity.h"

class Camera : public Entity {

	protected: Vector3 _up;
	
	/* "Eye" Position. */
	protected: Vector3 _at;
	
	protected: Vector3 _center;

	protected: double _near;

	protected: double _far;

	public: Camera(double near,double far){
		_up.set(0, 0, 1);
		_at.set(0, 0, -1);
		_center.set(0, 0, 0);
		_near = near;
		_far = far;
	}

	public: ~Camera(){};


	public: virtual void update(){}

	public: virtual void computeProjectionMatrix(){}

	public: virtual void computeVisualizationMatrix(){}

};

#endif