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

#define VPORTLEFT -5.0
#define VPORTRIGHT 5.0
#define VPORTBOTTOM -2.0
#define VPORTTOP 12.0
#define FRAMESTOMOVE 6


Frog* sapo; //sapo DUMMY
Roadside* estradaborda; //estradaborda DUMMY
Road* estrada;
River* rio;
Riverside* rioborda; //tudo DUMMIES
Timberlog* tronco;
Bus* bus;

class GameManager {
protected:
	std::vector < GameObject* > _game_objects;
public:

	int rotate_y; //usado para rodar a câmara e assim ver se os modelos estão em ordem
	int rotate_x;
	double movex;
	double movey;
	Frog* frog;
	int frogQ, frogA, frogO, frogP, frogFrames;

	GameManager(){
		rotate_x = 0;
		rotate_y = 0;
		movex = 0;
		movey = 0;
		frogQ = 0;
		frogA = 0;
		frogO = 0;
		frogP = 0;
		frogFrames = 0;
	}
	~GameManager();

	void addGameObject(GameObject* obj){ _game_objects.push_back(obj); }
	void setFrog(Frog* f){ frog = f; }
	
	void update(int useless) {
		std::vector<GameObject* >::iterator iter = _game_objects.begin();
		if (frogFrames == 0){
			if (frogQ){ frog->moveUp(); frogQ = 0;}
			else if (frogA){ frog->moveDown(); frogA = 0; }
			else if (frogO){ frog->moveLeft(); frogO = 0; }
			else if (frogP){ frog->moveRight(); frogP = 0; }
		}
		frogFrames = (++frogFrames) % FRAMESTOMOVE;

		for (iter; iter != _game_objects.end(); iter++){
			//do things with positions
		}

		display();
	};

	void display(){ //vem do lab0.cpp
		/*  clear all pixels  */
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		// Reset transformations
		glLoadIdentity();
		glScalef(-2.0/11.0, 0.2 / 1.4, 2.0 / 11.0);
		glRotatef(rotate_x, 1.0, 0.0, 0.0);
		glRotatef(rotate_y, 0.0, 0.0, 1.0);
		glTranslatef(movex, movey-6, 0);
		// Rotate when user changes rotate_x and rotate_y
		
		
		glRotatef(180, 0.0, 1.0, 0.0); //enquanto a rotação estranha (glOrtho?) não estiver arranjada, isto deixa tudo em ordem.
		
		std::vector<GameObject* >::iterator iter = _game_objects.begin();
		for (iter; iter != _game_objects.end(); iter++){
			(*iter)->draw();
		}
		glFlush();
	}
	void reshape(int w, int h) { //arranjar esta coisa
		float xmin = VPORTLEFT, xmax = VPORTRIGHT, ymin = VPORTBOTTOM, ymax = VPORTTOP;
		float ratio = (xmax - xmin) / (ymax - ymin);
		float aspect = (float)w / h;
		if (aspect > ratio)
			glViewport((w - h*ratio) / 2, 0, h*ratio, h);
		else
			glViewport(0, (h - w / ratio) / 2, w, w / ratio);
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		//glMatrixMode(GL_MODELVIEW);
		//glLoadIdentity();
		glOrtho(xmin, xmax, ymin, ymax , 3.0, 0.0);
		//glOrtho(0.0, 1.0, 0.0, 1.0, -1.0, 1.0);
	}

	void keyPressed(unsigned char key, int x, int y){
		if ((key == 'a') || (key == 'A')) frogA = 1;
		else if ((key == 'q') || (key == 'Q')) frogQ = 1;
		else if ((key == 'p') || (key == 'P')) frogP = 1; // trocar estas duas caso necessário: quando se arranjar a ortho.
		else if ((key == 'o') || (key == 'O')) frogO = 1;
		else if ((key == '2')) movey += 0.5;
		else if ((key == '4')) movex += 0.5;
		else if ((key == '8')) movey -= 0.5;
		else if ((key == '6')) movex -= 0.5;
		//glutPostRedisplay();
	}

	void specialKeyPressed(int key, int x, int y){
		//  Right arrow - increase rotation by 5 degrees
		if (key == GLUT_KEY_RIGHT)
			rotate_y += 5;
		//  Left arrow - decrease rotation by 5 degrees
		else if (key == GLUT_KEY_LEFT)
			rotate_y -= 5;
		else if (key == GLUT_KEY_UP)
			rotate_x += 5;
		else if (key == GLUT_KEY_DOWN)
			rotate_x -= 5;
		//  Request display update
		//glutPostRedisplay();
	}

	void init(void){
		/*  select clearing (background) color       */
		glClearColor(0.0, 0.0, 0.0, 0.0);
		glEnable(GL_DEPTH_TEST);
		/*  initialize viewing values  */
		//glMatrixMode(GL_MODELVIEW);
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		glOrtho(VPORTLEFT, VPORTRIGHT, VPORTBOTTOM, VPORTTOP, 3.0, 0.0);
		//glOrtho(0.0, 1.0, 0.0, 1.0, -1.0, 1.0);
	}
};


#endif