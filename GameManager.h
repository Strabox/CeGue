#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

#include <stdio.h>
#include <vector>
#include <string>
#include <cmath>
#include "glut.h"
#include "GameObject.h"
#include "Frog.h"
#include "Roadside.h"
#include "Road.h"
#include "Riverside.h"
#include "River.h"
#include "Timberlog.h"
#include "Bus.h"
#include "Camera.h"
#include "Car.h"
#include "LightSource.h"
#include "BlackWall.h"

#define DRAWRIGHT -5.5
#define DRAWLEFT 5.5
#define DRAWBOTTOM -1.5
#define DRAWTOP 11.5
#define DRAWFAR -11.5
#define DRAWNEAR 11.5
#define SPEED_SCALE_INCREASE 1.05

int frame = 0;					//Frame rate counter.

int total_time = 0;				//Total time since app is running.

int delta_time;					//Time between update function calls.


class GameManager {

protected:

	std::vector <GameObject*> _game_objects;

	std::vector <DynamicObject* > _dynamic_objects;

	std::vector <Camera *> _cameras;

	std::vector <LightSource*> _light_sources;

	std::vector <Car *> _cars;

	Frog* frog;					//Used in frog's movement.

	int rotate_y;				//TESTS PURPOSE: rotate camera 1.

	int rotate_x;

	bool light;					//Light Mode Off in Begining

	double movex;

	double movey;

	double tens_of_seconds_passed;

	int _activeCamera;			//Current Camera

	BlackWall* walls;

public:

	GameManager(){
		rotate_x = 0;
		rotate_y = 0;
		movex = 0;
		movey = 0;
		_activeCamera = 0;
		light = false;
		tens_of_seconds_passed=0.0;
		walls = new BlackWall();
	}

	~GameManager();

	/* addGameObejct(obj) - adds a new Game object to the list.*/
	void addGameObject(GameObject* obj){ _game_objects.push_back(obj); }

	void addDynamicObject(DynamicObject* obj){ _dynamic_objects.push_back(obj); }

	void addCarsObject(Car* car){ _cars.push_back(car); }

	/* addCamera(cam) - Adds a new camera to the cameras list.*/
	void addCamera(Camera* cam){ _cameras.push_back(cam); }

	/* addlightSource(source) - Adds a new LightSource to the gameManager. */
	void addLightSource(LightSource* source){ _light_sources.push_back(source);}

	void setFrog(Frog* f){ frog = f; }
	
	/* update() - Called before paint the scene to update Graphic Objects. */
	void update(int useless) {
		std::vector<DynamicObject* >::iterator iter = _dynamic_objects.begin();
		bool increase_speed = false;

		delta_time = glutGet(GLUT_ELAPSED_TIME) - total_time;
		total_time += delta_time;

		if ((total_time / 10000)> (int)tens_of_seconds_passed){
			increase_speed=true;
			tens_of_seconds_passed++;
		}

		for (iter; iter != _dynamic_objects.end(); iter++){
			if (increase_speed){ 
				(*iter)->setSpeed((*iter)->getSpeed() * SPEED_SCALE_INCREASE);
			}
			(*iter)->update(delta_time);
		}
		frog->checkIfColided(_game_objects);

		increase_speed=false;
	}

	/* display() - Call to paint all the scene.*/
	void display(){
		char* vidas = (char*) malloc(sizeof(char)*10);
		memset(vidas, '\0', 10);
		strcpy_s(vidas, 10,"Vidas:  ");
		/* Reset Color and Depth Buffer */
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		if (_activeCamera == 0){
			_cameras[0]->update();
			glTranslatef(movex, movey - 1.0, 0);
			glTranslatef(movex, movey + 6.5, 0);
			glRotatef(rotate_x, 1.0, 0.0, 0.0);
			glRotatef(rotate_y, 0.0, 0.0, 1.0);
			glTranslatef(movex, movey - 6.5, 0);
			glRotatef(180, 0.0, 1.0, 0.0);
		}
		else if (_activeCamera == 1){
			_cameras[1]->update();
		}
		else if (_activeCamera == 2){
			_cameras[2]->setPosition(frog->getPosition().getX(), frog->getPosition().getY() - 2, _cameras[2]->getPosition().getZ());
			_cameras[2]->setCenter(frog->getPosition().getX(), frog->getPosition().getY(), frog->getPosition().getZ());
			_cameras[2]->update();
		}
		
		//printf("frame number: %d\ntime:%d\n", ++frame, glutGet(GLUT_ELAPSED_TIME));
		sprintf_s(vidas + 7, 10, "%d", frog->getLives());
		//writeString(-2, 12, 1.0, 0.0, 0.0, GLUT_BITMAP_HELVETICA_18, vidas);
		
		std::vector<LightSource* >::iterator iterLight = _light_sources.begin();
		for (iterLight; iterLight != _light_sources.end(); iterLight++){
				(*iterLight)->draw();
		}
		walls->draw();
		std::vector<GameObject* >::iterator iter = _game_objects.begin();
		for (iter; iter != _game_objects.end(); iter++){
			(*iter)->draw();
		}
		glFlush();
	
	}

	/* writeString() - */
	void writeString(int x, int y, float r, float g, float b, void* font, char *string)
	{
		glColor3f(r, g, b);
		glRasterPos3f(x, y,3);
		int len, i;
		len = (int)strlen(string);
		for (i = 0; i < len; i++) {
			glutBitmapCharacter(font, string[i]);
		}
	}

	/* reshape(w,h) - Event handler called when user resize the game window. */
	void reshape(int w, int h) {
		double xmax = DRAWLEFT;
		double xmin = DRAWRIGHT;
		double ymin = DRAWBOTTOM;
		double ymax = DRAWTOP;
		float ratio = (xmax - xmin) / (ymax - ymin);
		float aspect = (float) w / h;
		if ( aspect > ratio )
			glViewport( (w-h*ratio)/2, 0, h*ratio, h);
		else
			glViewport( 0, (h-w/ratio)/2, w, w/ratio);
	}

	/* keyPressed(key,x,y,down) - Answer to key's event.*/
	void keyPressed(unsigned char key, int x, int y, bool down){
		if (down) {
			if ((key == 'h')) movey += 0.5;
			else if (key == 'g') movex -= 0.5;
			else if (key == 'y') movey -= 0.5;
			else if (key == 'j') movex += 0.5;
			else if (key == 'q'){
				frog->moveUp();
			}
			else if (key == 'a'){
				frog->moveDown();
			}
			else if (key == 'o'){
				frog->moveLeft();
			}
			else if (key == 'p'){
				frog->moveRight();
			}
			else if (key == '1'){
				_activeCamera = 0;
			}
			else if (key == '2'){
				_activeCamera = 1;
			}
			else if (key == '3'){
				_activeCamera = 2;
			}
			else if (key == 'n'){										//Global illumination key.
				if (_light_sources[0]->getState() == false){			//Night -> Day
					_light_sources[0]->setState(true);
					_light_sources[0]->setPosition(Vector4(0.0, 4.5, 10.0, 0.0));
					_light_sources[0]->setSpecular(Vector4(0.4, 0.4, 0.4, 1.0));
					_light_sources[0]->setDiffuse(Vector4(0.4, 0.4, 0.4, 1.0));
					_light_sources[0]->setAmbient(Vector4(0.5, 0.5, 0.5, 1.0));
					_light_sources[0]->setDirection(Vector3(0.0, 0.0, -1.0));
					_light_sources[0]->setCutOff(180);
					_light_sources[0]->setExponent(0.0);
				}
				else{													//Day -> Night
					_light_sources[0]->setState(false);
					_light_sources[0]->setPosition(Vector4(0.0, 4.5, 10.0, 0.0));
					_light_sources[0]->setSpecular(Vector4(0.05, 0.05, 0.05, 0.05));
					_light_sources[0]->setDiffuse(Vector4(0.05, 0.05, 0.05, 0.2));
					_light_sources[0]->setAmbient(Vector4(0.05, 0.05, 0.05, 0.2));
					_light_sources[0]->setDirection(Vector3(0.0, 0.0, -1.0));
					_light_sources[0]->setCutOff(180);
					_light_sources[0]->setExponent(0.0);
				}
			}
			else if (key == 'c'){										//Local spotlight illuminations.
				if (_light_sources[1]->getState() == false){
					for (int i = 1; i <= 6; i++){
						_light_sources[i]->setState(true);
					}
					glEnable(GL_LIGHT1);
					glEnable(GL_LIGHT2);
					glEnable(GL_LIGHT3);
					glEnable(GL_LIGHT4);
					glEnable(GL_LIGHT5);
					glEnable(GL_LIGHT6);
				}
				else{
					for (int i = 1; i <= 6; i++){
						_light_sources[i]->setState(false);
					}
					glDisable(GL_LIGHT1);
					glDisable(GL_LIGHT2);
					glDisable(GL_LIGHT3);
					glDisable(GL_LIGHT4);
					glDisable(GL_LIGHT5);
					glDisable(GL_LIGHT6);
				}
			}
			else if (key == 'l')										//TESTS PURPOSE ONLY (Turns on/off light mode)
			{
				if (light == false){
					glEnable(GL_LIGHTING);
					light = true;
				}
				else{
					glDisable(GL_LIGHTING);
					light = false;
				}
			}
		}
		else{frog->stopMovement();}
	
	}

	/* specialKeysPressed() - TESTS PURPOSE ONLY */
	void specialKeyPressed(int key, int x, int y){
		//  roda para a direita
		if (key == GLUT_KEY_RIGHT)
			rotate_y += 5;
		//  roda a camara para a esquerda
		else if (key == GLUT_KEY_LEFT)
			rotate_y -= 5;
		else if (key == GLUT_KEY_UP)
			rotate_x += 5;
		else if (key == GLUT_KEY_DOWN)
			rotate_x -= 5;
	}
	
	/* init() - Initialize Color and enables depth buffer.*/
	void init(void){
		/*  select clearing (background) color */
		glClearColor(0.0, 0.0, 0.0, 0.0);
		glEnable(GL_DEPTH_TEST);			// permite desenhar as coisas por ordem de profundidade
		glShadeModel(GL_SMOOTH);
		glEnable(GL_LIGHT0);
	}

};


#endif