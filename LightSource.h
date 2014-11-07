#ifndef LIGHTSOURCE_H
#define LIGHTSOURCE_H

#include "Vector4.h"

/* Class LightSource - Represents a Light Source. */
class LightSource{

	private: Vector4 _ambient;

	private: Vector4 _diffuse;

	private: Vector4 _specular;

	private: Vector4 _position;

	public: Vector3 _direction;

	private: double _cut_off;

	private: GLfloat _exponent;

	private: GLenum _num;				//Number of the GL_LIGHTi

	private: bool _state;				//Light is On/Off


	public: LightSource(GLenum number){
		_num = number;
		_state = false;					//Off by default.
		_exponent = 0.0;				//Default
		_cut_off = 180;					//Default
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

	public: void setPosition(const Vector4 &position){
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

	/* draw() -  */
	public: void draw(){
		GLfloat	light_position[] = {_position.getX(),_position.getY(),_position.getZ(),_position.getW()};
		GLfloat	light_specular[] = { _specular.getX(), _specular.getY(), _specular.getZ(),_specular.getW()};
		GLfloat	light_diffuse[] = { _diffuse.getX(), _diffuse.getY(), _diffuse.getZ(),_diffuse.getW() };
		GLfloat light_ambient[] = { _ambient.getX(), _ambient.getY(), _ambient.getZ(), _ambient.getW() };
		GLfloat light_direction[] = { _direction.getX(), _direction.getY(), _direction.getZ() };
		
		glLightfv(_num, GL_AMBIENT, light_ambient);
		glLightfv(_num, GL_DIFFUSE, light_diffuse);
		glLightfv(_num, GL_SPECULAR, light_specular);
		glLightfv(_num, GL_POSITION, light_position);
		glLightf(_num, GL_SPOT_CUTOFF, _cut_off);
		glLightfv(_num, GL_SPOT_DIRECTION, light_direction);
		glLightfv(_num, GL_SPOT_EXPONENT, &_exponent);
	}

};

#endif