#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

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

	int rotate_y = 0; //usado para rodar a câmara e assim ver se os modelos estão em ordem
	int rotate_x = 0;
	double movex = 0;
	double movey = 0;
	Frog* frog;

	GameManager(){}
	~GameManager();

	void addGameObject(GameObject* obj){ _game_objects.push_back(obj); }
	void setFrog(Frog* f){ frog = f; }
	void update() {
		std::vector<GameObject* >::iterator iter = _game_objects.begin();
		for (iter; iter != _game_objects.end(); iter++){
			//do things with positions
		}
	};

	void display(){ //vem do lab0.cpp
		/*  clear all pixels  */
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		// Reset transformations
		glLoadIdentity();
		glTranslatef(movex, movey, 0);
		// Rotate when user changes rotate_x and rotate_y
		glRotatef(rotate_x, 1.0, 0.0, 0.0);
		glRotatef(rotate_y, 0.0, 1.0, 0.0);
		std::vector<GameObject* >::iterator iter = _game_objects.begin();
		for (iter; iter != _game_objects.end(); iter++){
			(*iter)->draw();
		}
	}
	void reshape(int w, int h) { //arranjar esta coisa
		float xmin = VPORTLEFT, xmax = VPORTRIGHT, ymin = VPORTBOTTOM, ymax = VPORTTOP;
		float ratio = (xmax - xmin) / (ymax - ymin);
		float aspect = (float)w / h;
		glViewport(0, 0, w, h);
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
		if (ratio < aspect)
		{
			float delta = ((ymax - ymin) * aspect - (xmax - xmin)) / 2;
			glOrtho(xmin - delta, xmax + delta, ymin, ymax, 0.0, 3.0);
		}
		else
		{
			float delta = ((xmax - xmin) / aspect - (ymax - ymin)) / 2;
			glOrtho(xmin, xmax, ymin - delta, ymax + delta, 0.0, 3.0);
		}
	}

	void keyPressed(unsigned char key, int x, int y){
		if ((key == 'a') || (key == 'A')) frog->moveDown();
		else if ((key == 'q') || (key == 'Q')) frog->moveUp();
		else if ((key == 'p') || (key == 'P')) frog->moveRight();
		else if ((key == 'o') || (key == 'O')) frog->moveLeft();
		else if ((key == '2')) movey += 0.5;
		else if ((key == '4')) movex += 0.5;
		else if ((key == '8')) movey -= 0.5;
		else if ((key == '6')) movex -= 0.5;
		glutPostRedisplay();
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
		glutPostRedisplay();
	}

	void init(void){
		/*  select clearing (background) color       */
		glClearColor(0.0, 0.0, 0.0, 0.0);
		glEnable(GL_DEPTH_TEST);
		/*  initialize viewing values  */
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		//glMatrixMode(GL_MODELVIEW);
		//glLoadIdentity();
		glOrtho(VPORTLEFT, VPORTRIGHT, VPORTBOTTOM, VPORTTOP, 0.0, 3.0);
	}
};


#endif