#include <stdlib.h>
#include "glut.h"
#include "GameManager.h"
#include "Frog.h"
#include "Roadside.h"
#include "Road.h"
#include "Riverside.h"
#include "River.h"
#include "Timberlog.h"
#include "Bus.h"

GameManager* man;

void regularKeys(unsigned char key, int x, int y){
	man->keyPressed(key, x, y);
}

void specialKeys(int key, int x, int y) {
	man->specialKeyPressed(key, x, y);
}

void displayForward(){ man->display(); }

void reshapeForward(int w, int h){ man->reshape(w, h); }

int main(int argc, char** argv){
	man = new GameManager();
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(400, 560);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("CG Frogger - grupo 18");
	man->init();
	// "binding" de funções ao GL
	glutDisplayFunc(displayForward);
	//glutReshapeFunc(reshapeForward);
	glutKeyboardFunc(regularKeys);
	glutSpecialFunc(specialKeys);
	/* Adicionar alguns objectos */
	//sapo
	Frog* frog = new Frog();
	frog->setPosition(0.0, 0.0, 0.0);
	frog->setZRotation(0.0);
	man->setFrog(frog);
	man->addGameObject(frog);
	//borda da estrada
	Roadside* estradaborda = new Roadside();
	estradaborda->setPosition(0.0, 0.0, -1.0);
	man->addGameObject(estradaborda);
	//estrada
	Road* estrada = new Road();
	estrada->setPosition(0.0, 1.0, -1.0);
	man->addGameObject(estrada);
	//rio
	River* rio = new River();
	rio->setPosition(1.0, 0.0, -1.0);
	man->addGameObject(rio);
	//borda do rio
	Riverside* rioborda = new Riverside();
	rioborda->setPosition(1.0, 1.0, -1.0);
	man->addGameObject(rioborda);
	//tronco
	Timberlog* tronco = new Timberlog();
	tronco->setPosition(0.0, -1.0, -1.0);
	man->addGameObject(tronco);
	//autocarro
	Bus* bus = new Bus();
	bus->setPosition(0.0, -1.0, 0.0);
	man->addGameObject(bus);

	glutMainLoop();
	return 0;
}
