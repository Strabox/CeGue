#include <stdlib.h>
#include <time.h>
#include "glut.h"
#include "GameManager.h"
#include "Frog.h"
#include "Roadside.h"
#include "Road.h"
#include "Riverside.h"
#include "River.h"
#include "Timberlog.h"
#include "Bus.h"
#include "Car.h"
#include "Turtle.h"

#define MILISECONDS 17

GameManager* man;

void regularKeys(unsigned char key, int x, int y){
	man->keyPressed(key, x, y);
}

void specialKeys(int key, int x, int y) {
	man->specialKeyPressed(key, x, y);
}

void displayForward(){ man->display(); }

void reshapeForward(int w, int h){ man->reshape(w, h); }

void updateForward(int useless){
	man->update(useless);
	glutTimerFunc(MILISECONDS, updateForward, 0);
}

void spawnWorldObjects(){
	double i = 0, j = 0;
	Roadside* estradaborda;
	for (i = 0.0; i < 11.0; i++){
		estradaborda = new Roadside();
		estradaborda->setPosition(-5.0 + i, 0.0, -1.0);
		man->addGameObject(estradaborda);
	}
	Road* estrada;
	for (i = 0.0; i < 11.0; i++){
		for (j = 0.0; j < 5.0; j++){
			estrada = new Road();
			estrada->setPosition(-5.0 + i, 1.0 + j, -1.0);
			man->addGameObject(estrada);
		}
	}
	for (i = 0.0; i < 11.0; i++){
		estradaborda = new Roadside();
		estradaborda->setPosition(-5.0 + i, 6.0, -1.0);
		man->addGameObject(estradaborda);
	}
	River* rio;
	for (i = 0.0; i < 11.0; i++){
		for (j = 0.0; j < 5.0; j++){
			rio = new River(rand() );						// RANDOM
			rio->setPosition(-5.0 + i, 7.0 + j, -1.0);
			man->addGameObject(rio);
		}
	}
	Riverside* rioborda;
	for (i = 0.0; i < 11.0; i++){
		rioborda = new Riverside();
		rioborda->setPosition(-5.0 + i, 12.0, -1.0);
		man->addGameObject(rioborda);
	}
	Timberlog* tronco;
	tronco = new Timberlog();
	tronco->setPosition(-4.0, 9.0, -1.0);
	man->addGameObject(tronco);
	tronco = new Timberlog();
	tronco->setPosition(-1.0, 11.0, -1.0);
	man->addGameObject(tronco);
	Bus* bus;
	bus = new Bus();
	bus->setPosition(-1.0, 2.0, 0.0);
	man->addGameObject(bus);
	bus = new Bus();
	bus->setPosition(4.0, 4.0, 0.0);
	man->addGameObject(bus);
	Car* car;
	car = new Car();
	car->setPosition(2.0, 2.0, 0.0);
	man->addGameObject(car);
	Turtle* turtle;
	turtle = new Turtle();
	turtle->setPosition(-2.0, 10.0, -1.0);
	man->addGameObject(turtle);
}

int main(int argc, char** argv){
	srand(time(NULL));
	man = new GameManager();
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(400, 560);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("CG Frogger - grupo 18");
	man->init();
	// "binding" de funções ao GL
	glutDisplayFunc(displayForward);
	glutReshapeFunc(reshapeForward);
	glutKeyboardFunc(regularKeys);
	glutSpecialFunc(specialKeys);
	/* Adicionar alguns objectos */
	spawnWorldObjects();
	//sapo
	Frog* frog = new Frog();
	frog->setPosition(0.0, 0.0, 0.0);
	frog->setZRotation(0.0);
	man->setFrog(frog);
	man->addGameObject(frog);
	//borda da estrada
	/*Roadside* estradaborda = new Roadside();
	estradaborda->setPosition(0.0, 0.0, -1.0);
	man->addGameObject(estradaborda);*/
	//estrada
	/*Road* estrada = new Road();
	estrada->setPosition(0.0, 1.0, -1.0);
	man->addGameObject(estrada);*/
	//rio
	/*River* rio = new River();
	rio->setPosition(1.0, 0.0, -1.0);
	man->addGameObject(rio);*/
	//borda do rio
	/*Riverside* rioborda = new Riverside();
	rioborda->setPosition(1.0, 1.0, -1.0);
	man->addGameObject(rioborda);*/
	//tronco
	/*Timberlog* tronco = new Timberlog();
	tronco->setPosition(0.0, -1.0, -1.0);
	man->addGameObject(tronco);*/
	//autocarro
	/*Bus* bus = new Bus();
	bus->setPosition(0.0, -1.0, 0.0);
	man->addGameObject(bus);*/
	glutTimerFunc(17, updateForward, 0);
	glutMainLoop();
	return 0;
}
