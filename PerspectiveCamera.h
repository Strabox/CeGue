#ifndef PERSPECTIVE_CAMERA_H
#define PERSPECTIVE_CAMERA_H

#include "Camera.h"

class PerspectiveCamera : public Camera {

	private: double _fovy;

	private: double _aspect;


	public: PerspectiveCamera(double fovy,double aspect, double zNear,double zFar): Camera(zNear,zFar){
			_fovy = fovy;
			_aspect = aspect;
	}

	public: ~PerspectiveCamera(){}


	public: void update(){


	}

	public: void computeProjectionMatrix(){
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		gluPerspective(_fovy, _aspect, _near, _far);
	}

	public: void computeVisualizationMatrix(){
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
		gluLookAt(_at.getX(), _at.getY(), _at.getZ(), _center.getX(), _center.getY(), _center.getZ(), _up.getX(), _up.getY(), _up.getZ());
	}

};


#endif