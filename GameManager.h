#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

#include <stdio.h>
#include <vector>
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

#define DRAWRIGHT -5.5
#define DRAWLEFT 5.5
#define DRAWBOTTOM -1.5
#define DRAWTOP 11.5
#define DRAWFAR -11.5
#define DRAWNEAR 11.5

int frame=0; //para fazer contagem dos frames na consola
int total_time = 0;
int delta_time;

class GameManager {

	protected:

	std::vector <GameObject*> _game_objects;

	std::vector <Camera *> _cameras;

	public:

	Frog* frog;		//relacionado com o movimento do sapo

	int _frogDirection;

	int rotate_y; //usado para rodar a câmara e assim ver se os modelos estão em ordem

	int rotate_x;

	double movex;

	double movey;

	int _activeCamera;

	std::vector <Car *> _cars;

	GameManager(){
		rotate_x = 0;
		rotate_y = 0;
		movex = 0;
		movey = 0;
		_activeCamera = 0;
		_frogDirection = 3;
	}

	~GameManager();

	/* addGameObejct(obj) - adds a new Game object to the list.*/
	void addGameObject(GameObject* obj){ _game_objects.push_back(obj); }

	/* addCamera(cam) - Adds a new camera to the cameras list.*/
	void addCamera(Camera* cam){ _cameras.push_back(cam); }

	void setFrog(Frog* f){ frog = f; }
	
	void update(int useless) {
		std::vector<GameObject* >::iterator iter = _game_objects.begin();
		
		delta_time = glutGet(GLUT_ELAPSED_TIME) - total_time;
		total_time += delta_time;

		for (iter; iter != _game_objects.end(); iter++){
			(*iter)->update(delta_time);
		}
		frog->checkIfColided(_cars);

	};

	void display(){
		/* Reset Color and DEpth Buffer */
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		/* reset À posição do referencial e redefinição da posição da câmara e rotação do mapa */
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
			_cameras[2]->setPosition(frog->getPosition()->getX(), frog->getPosition()->getY() - 2, 2.0);
			_cameras[2]->setCenter(frog->getPosition()->getX(), frog->getPosition()->getY(), frog->getPosition()->getZ());
			_cameras[2]->update();
		}
		
		printf("frame number: %d\ntime:%d\n", ++frame, glutGet(GLUT_ELAPSED_TIME));
		
		std::vector<GameObject* >::iterator iter = _game_objects.begin();
		for (iter; iter != _game_objects.end(); iter++){
			(*iter)->draw();
		}
		glFlush();
	}


	void reshape(int w, int h) { //segue sugestões dos slides mas muda algumas coisas (glOrtho em vez de gluOrtho2d) e os limites da janela
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

	/* !!!!!!!IMPORTANTE: 0 - West, 1 - South, 2 - East,3 - North*/
	int calculateDirection(int actualDirection,int newDirection){
		if (actualDirection == 0 && newDirection == 0) return 1;
		else if (actualDirection == 0 && newDirection == 1) return 2;
		else if (actualDirection == 0 && newDirection == 2) return 0;
		else if (actualDirection == 0 && newDirection == 3) return 0;
		else if (actualDirection == 1 && newDirection == 0) return 2;
		else if (actualDirection == 1 && newDirection == 1) return 3;
		else if (actualDirection == 1 && newDirection == 2) return -1;
		else if (actualDirection == 1 && newDirection == 3) return -1;
		else if (actualDirection == 2 && newDirection == 0) return -1;
		else if (actualDirection == 2 && newDirection == 1) return -1;
		else if (actualDirection == 2 && newDirection == 2) return -1;
		else if (actualDirection == 2 && newDirection == 3) return -1;
		else if (actualDirection == 3 && newDirection == 0) return -1;
		else if (actualDirection == 3 && newDirection == 1) return -1;
		else if (actualDirection == 3 && newDirection == 2) return -1;
		else if (actualDirection == 3 && newDirection == 3) return -1;
	}

	void keyPressed(unsigned char key, int x, int y, bool down){
		if (down) {
			if ((key == 'h')) movey += 0.5;
			else if (key == 'g') movex -= 0.5;
			else if (key == 'y') movey -= 0.5;
			else if (key == 'j') movex += 0.5;
			else if (key == 'q'){
				frog->moveUp(_frogDirection);
			}
			else if (key == 'a'){
				frog->moveDown(_frogDirection);
			}
			else if (key == 'o'){
				frog->moveLeft(_frogDirection);
			}
			else if (key == 'p'){
				frog->moveRight(_frogDirection);
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
		}
		else{ frog->stopMovement(); }
	
	}

	/* - TESTS ONLY */
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
		/*  select clearing (background) color       */
		glClearColor(0.0, 0.0, 0.0, 0.0);
		glEnable(GL_DEPTH_TEST); // permite desenhar as coisas por ordem de profundidade
	}

};


#endif