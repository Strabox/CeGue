#ifndef ORTHOGONAL_CAMERA_H
#define ORTHOGONAL_CAMERA_H

#include "Camera.h"

class OrthogonalCamera : public Camera {

	private: double _left;

	private: double _right;

	private: double _bottom;

	private: double _top;


	public: OrthogonalCamera(double left,double right,double bottom,double top,double near,double far){
		_left = left;
		_right = right;
		_bottom = bottom;
		_top = top;
	}

	public: ~OrthogonalCamera(){}

	public: void update(){


	}

	public: void computeProjectionMatrix(){

	}

	public: void computeVisualizationMatrix(){

	}
};

#endif