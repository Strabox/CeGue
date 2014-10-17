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

	}

	public: void computeVisualizationMatrix(){

	}

};


#endif