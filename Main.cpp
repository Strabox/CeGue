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
#include "PerspectiveCamera.h"
#include "OrthogonalCamera.h"

#define MILISECONDS 7

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

void spawnWorldObjects(){ // Map has 11 width and 13 height 
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
	tronco->setSpeed(-1.25, 0.0, 0.0); 
	man->addGameObject(tronco);
	tronco = new Timberlog();
	tronco->setPosition(-1.0, 8.0, -1.0);
	tronco->setSpeed(-1.0, 0.0, 0.0); 
	man->addGameObject(tronco);

	tronco = new Timberlog();
	tronco->setPosition(3.5, 9.0, -1.0);
	tronco->setSpeed(-1.5, 0.0, 0.0);
	man->addGameObject(tronco);
	tronco = new Timberlog();
	tronco->setPosition(6.5, 11.0, -1.0);
	tronco->setSpeed(-1.25, 0.0, 0.0); 
	man->addGameObject(tronco);
	tronco = new Timberlog();
	tronco->setPosition(-6.5, 8.0, -1.0);
	tronco->setSpeed(-1.0, 0.0, 0.0); 
	man->addGameObject(tronco);
	
	Bus* bus;
	bus = new Bus();
	bus->setPosition(-1.0, 2.0, 0.0);
	bus->setSpeed(-1.75, 0.0, 0.0);
	man->addGameObject(bus);
	bus = new Bus();
	bus->setPosition(4.0, 4.0, 0.0);
	bus->setSpeed(-2.0, 0.0, 0.0);
	man->addGameObject(bus);
	
	Car* car;
	car = new Car();
	car->setPosition(2.0, 3.0, 0.0);
	car->setSpeed(-4.0, 0.0, 0.0);
	man->addGameObject(car);
	man->_cars.push_back(car);
	car = new Car();
	car->setPosition(1.0, 1.0, 0.0);
	car->setSpeed(-3.0, 0.0, 0.0);
	man->addGameObject(car);
	man->_cars.push_back(car);
	car = new Car();
	car->setPosition(7.0, 5.0, 0.0);
	car->setSpeed(-2.5, 0.0, 0.0);
	man->addGameObject(car);
	man->_cars.push_back(car);
	
	Turtle* turtle;
	turtle = new Turtle();
	turtle->setPosition(-2.0, 10.0, -1.0);
	turtle->setSpeed(-1.0, 0.0, 0.0);
	man->addGameObject(turtle);
	turtle = new Turtle();
	turtle->setPosition(-2.0, 7.0, -1.0);
	turtle->setSpeed(-1.25, 0.0, 0.0);
	man->addGameObject(turtle);

	turtle = new Turtle();
	turtle->setPosition(4.5, 10.0, -1.0);
	turtle->setSpeed(-1.0, 0.0, 0.0);
	man->addGameObject(turtle);
	turtle = new Turtle();
	turtle->setPosition(4.5, 7.0, -1.0);
	turtle->setSpeed(-1.25, 0.0, 0.0);
	man->addGameObject(turtle);

	/* First Camera - Orthogonal */
	Camera* cam1 = new OrthogonalCamera(DRAWLEFT, DRAWRIGHT, DRAWBOTTOM, DRAWTOP, DRAWNEAR, DRAWFAR);
	cam1->setPosition(0.0, 0.0, 1.0);
	cam1->setCenter(0.0, 0.0, 0.0);
	cam1->setUp(0.0,1.0,0.0);
	/* Second Camera - Static Prespective */
	Camera* cam2 = new PerspectiveCamera(110, (DRAWLEFT - DRAWRIGHT) / (DRAWTOP - DRAWBOTTOM), 0.1, 20);
	cam2->setPosition(0.0, 0.0, 6.0);
	cam2->setCenter(0.0, 6.0, 0.0);
	cam2->setUp(0.0,1.0,1.0);
	/* Third Camera - Mobile Prespective */
	Camera* cam3 = new PerspectiveCamera(110, (DRAWLEFT - DRAWRIGHT) / (DRAWTOP - DRAWBOTTOM) , 0.1, 20);
	cam3->setPosition(0.0, -2.0, 1.0);
	cam3->setCenter(0.0,0.0,0.0);
	cam3->setUp(0.0,1.0,1.0);

	man->addCamera(cam1);
	man->addCamera(cam2);
	man->addCamera(cam3);

	/* Global Ligth - Global direction illumination. */
	Vector3 vec = Vector3(0.0, 4.5, 12.0);
	LightSource* globalIllumination = new LightSource(GL_LIGHT0);
	globalIllumination->setPosition(vec);

	/*  Spotlights - 6 spotlights */
	LightSource* spotlight1 = new LightSource(GL_LIGHT1);
	vec = Vector3(-2.5, 12.0, 3.0);
	spotlight1->setPosition(vec);

	LightSource* spotlight2 = new LightSource(GL_LIGHT2);
	vec = Vector3(2.5, 12.0, 3.0);
	spotlight2->setPosition(vec);

	LightSource* spotlight3 = new LightSource(GL_LIGHT3);
	vec = Vector3(-2.5, 6.0, 3.0);
	spotlight3->setPosition(vec);

	LightSource* spotlight4 = new LightSource(GL_LIGHT4);
	vec = Vector3(2.5, 6.0, 3.0);
	spotlight4->setPosition(vec);

	LightSource* spotlight5 = new LightSource(GL_LIGHT5);
	vec = Vector3(-2.5, 0.0, 3.0);
	spotlight5->setPosition(vec);

	LightSource* spotlight6 = new LightSource(GL_LIGHT6);
	vec = Vector3(2.5, 0.0, 3.0);
	spotlight6->setPosition(vec);

	man->addLightSource(globalIllumination);
	man->addLightSource(spotlight1);
	man->addLightSource(spotlight2);
	man->addLightSource(spotlight3);
	man->addLightSource(spotlight4);
	man->addLightSource(spotlight5);
	man->addLightSource(spotlight6);
}

int main(int argc, char** argv){
	man = new GameManager();
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(440, 520);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("CG Frogger - grupo 18");
	// GL functions binding.
	glutDisplayFunc(displayForward);
	glutReshapeFunc(reshapeForward);
	glutKeyboardFunc(regularKeys);
	glutKeyboardUpFunc(regularUpKeys);
	glutSpecialFunc(specialKeys);
	man->init();
	spawnWorldObjects();				 // Initializes the World, creating necessary objects. 
	glutTimerFunc(17, updateForward, 0); // Start the Update Cycle.
	glutMainLoop();
	return 0;
}
