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

	int rotate_y; //usado para rodar a câmara e assim ver se os modelos estão em ordem

	int rotate_x;

	double movex;

	double movey;

	int frogQ, frogA, frogO, frogP;

	bool regularKeys[256];

	bool specialKeys[32];

	bool cameras[3];

	GameManager(){
		rotate_x = 0;
		rotate_y = 0;
		movex = 0;
		movey = 0;
		frogQ = 0;
		frogA = 0;
		frogO = 0;
		frogP = 0;
		cameras[0] = true;
		cameras[1] = false;
		cameras[2] = false;
	}

	~GameManager();

	void addGameObject(GameObject* obj){ _game_objects.push_back(obj); }

	void addCamera(Camera* cam){ _cameras.push_back(cam); }

	void setFrog(Frog* f){ frog = f; }
	
	void update(int useless) {
		std::vector<GameObject* >::iterator iter = _game_objects.begin();
		
			if (frogQ){ frog->moveUp(); frogA = 0; frogO = 0; frogP = 0; }
			else if (frogA){ frog->moveDown(); frogQ = 0; frogO = 0; frogP = 0; }
			else if (frogO){ frog->moveLeft(); frogQ = 0; frogA = 0; frogP = 0; }
			else if (frogP){ frog->moveRight(); frogQ = 0; frogA = 0; frogO = 0; }
			else{ frog->stopMovement();}
		
		delta_time = glutGet(GLUT_ELAPSED_TIME) - total_time;
		total_time += delta_time;

		for (iter; iter != _game_objects.end(); iter++){
			(*iter)->useKeys(regularKeys, specialKeys);
			(*iter)->update(delta_time);
		}	
	};

	void display(){
		/* limpa tudo para redesenhar */
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		// reset À posição do referencial e redefinição da posição da câmara e rotação do mapa
		if (cameras[0]){
			_cameras[0]->computeProjectionMatrix();
			glTranslatef(movex, movey - 1.0, 0);
			/* Rotacao a volta do centro do mapa. */
			glTranslatef(movex, movey + 6.5, 0);
			glRotatef(rotate_x, 1.0, 0.0, 0.0);
			glRotatef(rotate_y, 0.0, 0.0, 1.0);
			glTranslatef(movex, movey - 6.5, 0);
			glRotatef(180, 0.0, 1.0, 0.0);
		}
		else if (cameras[1]){
			_cameras[1]->computeProjectionMatrix();
			_cameras[1]->computeVisualizationMatrix();
		}
		else if (cameras[2]){
			_cameras[2]->update();
			_cameras[2]->setPosition(frog->getPosition()->getX(), frog->getPosition()->getY() - 2, 6.0);
			_cameras[2]->setCenter(frog->getPosition()->getX(), frog->getPosition()->getY(), frog->getPosition()->getZ());
			_cameras[2]->computeProjectionMatrix();
			_cameras[2]->computeVisualizationMatrix();
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

	void keyPressed(unsigned char key, int x, int y, bool down){
		if (down) {
			if ((key == 'h')) movey += 0.5;
			else if ((key == 'g')) movex -= 0.5;
			else if ((key == 'y')) movey -= 0.5;
			else if ((key == 'j')) movex += 0.5;
			else if (key == '1'){
				cameras[0] = true;
				cameras[1] = false;
				cameras[2] = false;
			}
			else if (key == '2'){
				cameras[0] = false;
				cameras[1] = true;
				cameras[2] = false;
			}
			else if (key == '3'){
				cameras[0] = false;
				cameras[1] = false;
				cameras[2] = true;
			}
		}
		regularKeys[(int)key] = down;
	}

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
		specialKeys[key] = true;
	}

	void init(void){
		/*  select clearing (background) color       */
		glClearColor(0.0, 0.0, 0.0, 0.0);
		glEnable(GL_DEPTH_TEST); // permite desenhar as coisas por ordem de profundidade
		/*  initialize viewing values  */
		
		/*
		GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };
		GLfloat mat_shininess[] = { 80.0 };
		GLfloat light_position[] = { 0.0, 5.0, 5.0, 0.0 };
		glClearColor(0.0, 0.0, 0.0, 0.0);
		glShadeModel(GL_FLAT);

		glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
		glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
		glLightfv(GL_LIGHT0, GL_POSITION, light_position);

		glEnable(GL_LIGHTING);
		glEnable(GL_LIGHT0);
		glEnable(GL_DEPTH_TEST);
		*/
	}

};


#endif