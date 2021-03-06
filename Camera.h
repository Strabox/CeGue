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

	public: Camera(double neara,double fara){
		_up.set(0, 1, 0);
		_at.set(0, 0, 0);
		_center.set(0, 0, 0);
		_near = neara;
		_far = fara;
	}

	public: ~Camera(){};

	public: void setUp(double x, double y, double z){
		_up.set(x, y, z);
	}
	
	public: void setCenter(double x, double y, double z){
		_center.set(x, y, z);
	}

	public: virtual void update(){}

	public: virtual void computeProjectionMatrix(){}

	public: virtual void computeVisualizationMatrix(){}

};

#endif