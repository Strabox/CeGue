#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

#include <stdio.h>
#include <vector>
//#include <stdlib.h> //Main.cpp trata do erro do glut redefinir o exit do stdlib.
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
	int rotate_y; //usado para rodar a câmara e assim ver se os modelos estão em ordem
	int rotate_x;
	double movex;
	double movey;
	Frog* frog;		//relacionado com o movimento do sapo
	int frogQ, frogA, frogO, frogP;
	bool regularKeys[256];
	bool specialKeys[32];

	GameManager(){
		rotate_x = 0;
		rotate_y = 0;
		movex = 0;
		movey = 0;
		frogQ = 0;
		frogA = 0;
		frogO = 0;
		frogP = 0;
	}
	~GameManager();

	void addGameObject(GameObject* obj){ _game_objects.push_back(obj); }
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
			(*iter)->update(delta_time);
		}

		
	};

	void display(){
		/* limpa tudo para redesenhar */
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		// reset À posição do referencial e redefinição da posição da câmara e rotação do mapa
		glLoadIdentity();
		glOrtho(DRAWLEFT, DRAWRIGHT, DRAWBOTTOM, DRAWTOP, DRAWNEAR, DRAWFAR);
		glTranslatef(movex, movey - 1.0, 0);
		
		/* rotacao a volta do centro do mapa */
		glTranslatef(movex, movey + 6.5, 0);
		glRotatef(rotate_x, 1.0, 0.0, 0.0);
		glRotatef(rotate_y, 0.0, 0.0, 1.0);
		glTranslatef(movex, movey - 6.5, 0);
		
		
		printf("frame number: %d\ntime:%d\n", ++frame, glutGet(GLUT_ELAPSED_TIME));
		glRotatef(180, 0.0, 1.0, 0.0);
		
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
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		glOrtho(xmin, xmax, ymin, ymax, DRAWNEAR, DRAWFAR);
	}

	void keyPressed(unsigned char key, int x, int y, bool down){
		if (down) {
			if ((key == '2')) movey += 0.5;
			else if ((key == '4')) movex -= 0.5;
			else if ((key == '8')) movey -= 0.5;
			else if ((key == '6')) movex += 0.5;
			else if ((key == 'a') || (key == 'A')) frogA = 1;
			else if ((key == 'q') || (key == 'Q')) frogQ = 1;
			else if ((key == 'p') || (key == 'P')) frogP = 1;
			else if ((key == 'o') || (key == 'O')) frogO = 1;
		}
		else{
			if ((key == 'a') || (key == 'A') ||
				(key == 'q') || (key == 'Q') ||
				(key == 'p') || (key == 'P') ||
				(key == 'o') || (key == 'O'))
					frogQ = 0; frogA = 0; frogO = 0; frogP = 0;
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
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		glOrtho(DRAWLEFT, DRAWRIGHT, DRAWBOTTOM, DRAWTOP, DRAWNEAR, DRAWFAR);
	}
};


#endif