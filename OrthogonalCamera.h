#ifndef ORTHOGONAL_CAMERA_H
#define ORTHOGONAL_CAMERA_H

#include "Camera.h"

class OrthogonalCamera : public Camera {

	private: double _left;

	private: double _right;

	private: double _bottom;

	private: double _top;


	public: OrthogonalCamera(double left,double right,double bottom,double top,double near,double far): Camera(near,far){
		_left = left;
		_right = right;
		_bottom = bottom;
		_top = top;
	}

	public: ~OrthogonalCamera(){}

	public: void update(){


	}

	public: void computeProjectionMatrix(){
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		glOrtho(_left, _right, _bottom, _top, _near, _far);
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
	}

	public: void computeVisualizationMatrix(){
		
	}

};

#endif