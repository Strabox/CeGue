#ifndef LIGHTSOURCE_H
#define LIGHTSOURCE_H

#include "Vector4.h"

/* Class LightSource - Represents a Light Source */
class LightSource{

	private: Vector4 _ambient;

	private: Vector4 _diffuse;

	private: Vector4 _specular;

	private: Vector3 _position;

	private: Vector3 _direction;

	private: double _cut_off;

	private: double _exponent;

	private: GLenum _num;			//Number of the GL_LIGHTi

	private: bool _state;			//Light is On/Off


	public: LightSource(GLenum number){
		_num = number;
		_state = false;				//Off by default.
	}

	public: ~LightSource(){}


	public: bool getState(){
		return _state;
	}
	
	public: GLenum getNum(){
		return _num;
	}

	public: void setState(bool state){
		_state = state;
	}

	public: void setPosition(const Vector3 &position){
		_position = position;
	}
	
	public: void setAmbient(const Vector4 &ambient){
		_ambient = ambient;
	}

	public: void setDiffuse(const Vector4 &diffuse){
		_diffuse = diffuse;
	}

	public: void setSpecular(const Vector4 &specular){
		_specular = specular;
	}

	public: void setDirection(const Vector3 &direction){
		_direction = direction;
	}

	public: void setCutOff(double cut_off){
		_cut_off = cut_off;
	}

	public: void setExponent(double exponent){
		_exponent = exponent;
	}

	/* draw() - */
	public: void draw(){
		GLfloat	light_position[] = {_position.getX(),_position.getY(),_position.getZ()};
		glLightfv(GL_LIGHT0, GL_POSITION, light_position);
	
	}

};

#endif