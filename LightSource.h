#ifndef LIGHTSOURCE_H
#define LIGHTSOURCE_H

#include "Vector4.h"

/* Class LightSource - */
class LightSource{

	private: Vector4 _ambient;

	private: Vector4 _diffuse;

	private: Vector4 _specular;

	private: Vector3 _position;

	private: Vector3 _direction;

	private: double _cut_off;

	private: double _exponent;

	private: GLenum _num;

	private: bool _state;


	public: LightSource(GLenum number){
		_num = number;
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

	public: void draw(){

	}

};

#endif