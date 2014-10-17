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
	man->keyPressed(key, x, y, true);
}

void regularUpKeys(unsigned char key, int x, int y){
	man->keyPressed(key, x, y, false);
}

void specialKeys(int key, int x, int y) {
	man->specialKeyPressed(key, x, y);
}

void displayForward(){ man->display(); }	// openGL + OOP = trouble. esta funcao reencaminha a chamada à display tornado possível a sua chamada.

void reshapeForward(int w, int h){ man->reshape(w, h); }	// openGL + OOP = trouble. esta funcao reencaminha a chamada à reshape tornado possível a sua chamada.

void updateForward(int useless){	// chama o update do gamemanager a cada 17ms (quase 60fps) idealmente.
	man->update(useless);			// o argumento useless é inuntil, so serve para se conseguir invocar a update.
	man->display();					// chama a display depois da update
	glutTimerFunc(MILISECONDS, updateForward, 0);
}

void spawnWorldObjects(){ // o mapa é 11 de largura por 13 de altura
	double i = 0, j = 0;
	
	Frog* frog = new Frog();
	frog->setPosition(0.0, 0.0, 0.0);
	frog->setZRotation(0.0);
	frog->setSpeed(0.0, 0.0, 0.0);
	man->setFrog(frog);
	man->addGameObject(frog);

	Roadside* estradaborda;
	estradaborda = new Roadside();
	estradaborda->setPosition(0.0, 0.0, -1.0);
	man->addGameObject(estradaborda);
	// ^passeio de baixo, v passeio de cima
	estradaborda = new Roadside();
	estradaborda->setPosition(0.0, 6.0, -1.0);
	man->addGameObject(estradaborda);

	Road* estrada;
	estrada = new Road();
	estrada->setPosition(0.0, 3.0, -1.0);
	man->addGameObject(estrada);
	
	River* rio;
	rio = new River();
	rio->setPosition(0.0, 9.0, -1.0);
	man->addGameObject(rio);
	
	Riverside* rioborda;
	rioborda = new Riverside();
	rioborda->setPosition(0.0, 12.0, -1.0);
	man->addGameObject(rioborda);
	
	Timberlog* tronco;
	tronco = new Timberlog();
	tronco->setPosition(-4.0, 9.0, -1.0);
	tronco->setSpeed(-1.5, 0.0, 0.0);
	man->addGameObject(tronco);
	tronco = new Timberlog();
	tronco->setPosition(-1.0, 11.0, -1.0);
	tronco->setSpeed(-1.5, 0.0, 0.0); 
	man->addGameObject(tronco);
	
	Bus* bus;
	bus = new Bus();
	bus->setPosition(-1.0, 2.0, 0.0);
	bus->setSpeed(-2.00, 0.0, 0.0);
	man->addGameObject(bus);
	bus = new Bus();
	bus->setPosition(4.0, 4.0, 0.0);
	bus->setSpeed(-2.0, 0.0, 0.0);
	man->addGameObject(bus);
	
	Car* car;
	car = new Car();
	car->setPosition(2.0, 3.0, 0.0);
	car->setSpeed(-3.0, 0.0, 0.0);
	man->addGameObject(car);
	
	Turtle* turtle;
	turtle = new Turtle();
	turtle->setPosition(-2.0, 10.0, -1.0);
	turtle->setSpeed(-2.0, 0.0, 0.0);
	man->addGameObject(turtle);


}

int main(int argc, char** argv){
	man = new GameManager();
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(440, 520);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("CG Frogger - grupo 18");
	man->init();
	// "binding" de funções ao GL
	glutDisplayFunc(displayForward);
	glutReshapeFunc(reshapeForward);
	glutKeyboardFunc(regularKeys);
	glutKeyboardUpFunc(regularUpKeys);
	glutSpecialFunc(specialKeys);
	/* Adicionar alguns objectos */
	spawnWorldObjects();
	glutTimerFunc(17, updateForward, 0); // inicia o ciclo de chamada da update
	glutMainLoop();
	return 0;
}
