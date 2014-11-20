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


#define MILISECONDS 0					

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

void displayForward(){ man->display(); }					// openGL + OOP = trouble. esta funcao reencaminha a chamada à display tornado possível a sua chamada.

void reshapeForward(int w, int h){ man->reshape(w, h); }	// openGL + OOP = trouble. esta funcao reencaminha a chamada à reshape tornado possível a sua chamada.

void updateForward(int useless){							// chama o update do gamemanager a cada 17ms (quase 60fps) idealmente.
	glutTimerFunc(MILISECONDS, updateForward, 0);
	man->update(useless);									// o argumento useless é inuntil, so serve para se conseguir invocar a update.
	man->display();											// chama a display depois da update
}

void spawnWorldObjects(){									// Map has 11 width and 13 height 
	double i = 0, j = 0;
	Frog* frog = new Frog();
	frog->setPosition(0.0, 0.0, 0.0);
	frog->setZRotation(0.0);
	frog->setSpeed(0.0, 0.0, 0.0);
	man->setFrog(frog);
	man->addGameObject(frog);
	man->addDynamicObject(frog);

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
	tronco->setPosition(-1.0, 11.0, -1.0);
	tronco->setSpeed(1.25, 0.0, 0.0);
	man->addGameObject(tronco);
	man->addDynamicObject(tronco);
	tronco = new Timberlog();
	tronco->setPosition(-4.0, 9.0, -1.0);
	tronco->setSpeed(1.5, 0.0, 0.0);
	man->addGameObject(tronco);
	man->addDynamicObject(tronco);
	tronco = new Timberlog();
	tronco->setPosition(-1.0, 8.0, -1.0);
	tronco->setSpeed(1.0, 0.0, 0.0); 
	man->addGameObject(tronco);
	man->addDynamicObject(tronco);

	tronco = new Timberlog();
	tronco->setPosition(6.5, 11.0, -1.0);
	tronco->setSpeed(1.25, 0.0, 0.0);
	man->addGameObject(tronco);
	man->addDynamicObject(tronco);
	tronco = new Timberlog();
	tronco->setPosition(3.5, 9.0, -1.0);
	tronco->setSpeed(1.5, 0.0, 0.0);
	man->addGameObject(tronco);
	man->addDynamicObject(tronco);
	tronco = new Timberlog();
	tronco->setPosition(-6.5, 8.0, -1.0);
	tronco->setSpeed(1.0, 0.0, 0.0); 
	man->addGameObject(tronco);
	man->addDynamicObject(tronco);
	
	Bus* bus;
	bus = new Bus();
	bus->setPosition(-1.0, 2.0, 0.0);
	bus->setSpeed(-1.75, 0.0, 0.0);
	man->addGameObject(bus);
	man->addDynamicObject(bus);
	bus = new Bus();
	bus->setPosition(4.0, 4.0, 0.0);
	bus->setSpeed(-2.0, 0.0, 0.0);
	man->addGameObject(bus);
	man->addDynamicObject(bus);

	Car* car;
	car = new Car();
	car->setPosition(2.0, 3.0, 0.0);
	car->setSpeed(-4.0, 0.0, 0.0);
	man->addGameObject(car);
	man->addDynamicObject(car);
	man->addCarsObject(car);
	car = new Car();
	car->setPosition(1.0, 1.0, 0.0);
	car->setSpeed(-3.0, 0.0, 0.0);
	man->addGameObject(car);
	man->addDynamicObject(car);
	man->addCarsObject(car);
	car = new Car();
	car->setPosition(7.0, 5.0, 0.0);
	car->setSpeed(-2.5, 0.0, 0.0);
	man->addGameObject(car);
	man->addDynamicObject(car);
	man->addCarsObject(car);
	
	Turtle* turtle = new Turtle();
	turtle->setPosition(-2.0, 10.0, -1.0);
	turtle->setSpeed(-1.0, 0.0, 0.0);
	man->addGameObject(turtle);
	man->addDynamicObject(turtle);
	turtle = new Turtle();
	turtle->setPosition(-2.0, 7.0, -1.0);
	turtle->setSpeed(-1.25, 0.0, 0.0);
	man->addGameObject(turtle);
	man->addDynamicObject(turtle);

	turtle = new Turtle();
	turtle->setPosition(4.5, 10.0, -1.0);
	turtle->setSpeed(-1.0, 0.0, 0.0);
	man->addGameObject(turtle);
	man->addDynamicObject(turtle);
	turtle = new Turtle();
	turtle->setPosition(4.5, 7.0, -1.0);
	turtle->setSpeed(-1.25, 0.0, 0.0);
	man->addGameObject(turtle);
	man->addDynamicObject(turtle);

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
	Vector4 vec = Vector4(0.0, 4.5, 10.0,0.0);
	Vector4 vec2 = Vector4(0.4, 0.4, 0.4, 1.0);
	Vector4 vec3 = Vector4(0.5, 0.5, 0.3, 1.0);
	
	LightSource* globalIllumination = new LightSource(GL_LIGHT0);
	globalIllumination->setPosition(vec);
	globalIllumination->setSpecular(vec2);
	globalIllumination->setCutOff(180);
	globalIllumination->setDiffuse(Vector4(0.5, 0.5, 0.5, 1.0));
	globalIllumination->setAmbient(Vector4(0.5, 0.5, 0.5, 1.0));
	globalIllumination->setDirection(Vector3(0.0, 0.0, -1.0));
	globalIllumination->setState(true);							//Day Mode.

	/*  Spotlights - 6 spotlights */
	LightSource* spotlight1 = new LightSource(GL_LIGHT1);
	spotlight1->setCutOff(30.0);
	spotlight1->setPosition(Vector4(-2.5, 12.0, 4.0, 1.0));
	spotlight1->setSpecular(vec2);
	spotlight1->setDiffuse(Vector4(0.6, 0.6, 0.6, 1.0));
	spotlight1->setExponent(20);
	spotlight1->setAmbient(Vector4(0.1, 0.1, 0.1, 1.0));
	spotlight1->setDirection(Vector3(0.0, -0, -1.0));

	LightSource* spotlight2 = new LightSource(GL_LIGHT2);
	spotlight2->setCutOff(30.0);
	spotlight2->setPosition(Vector4(-2.5, 6.0, 4.0, 1.0));
	spotlight2->setSpecular(vec2);
	spotlight2->setDiffuse(Vector4(0.6, 0.6, 0.6, 1.0));
	spotlight2->setExponent(20);
	spotlight2->setAmbient(Vector4(0.1, 0.1, 0.1, 1.0));
	spotlight2->setDirection(Vector3(0.0, -0, -1.0));

	LightSource* spotlight3 = new LightSource(GL_LIGHT3);
	spotlight3->setCutOff(30.0);
	spotlight3->setPosition(Vector4(-2.5, 1.0, 4.0, 1.0));
	spotlight3->setSpecular(vec2);
	spotlight3->setDiffuse(Vector4(0.6, 0.6, 0.6, 1.0));
	spotlight3->setExponent(20);
	spotlight3->setAmbient(Vector4(0.1, 0.1, 0.1, 1.0));
	spotlight3->setDirection(Vector3(0.0, 0, -1.0));

	LightSource* spotlight4 = new LightSource(GL_LIGHT4);
	spotlight4->setPosition(Vector4(2.5, 12.0, 4.0, 1.0));
	spotlight4->setSpecular(vec2);
	spotlight4->setCutOff(30.0);
	spotlight4->setDiffuse(Vector4(0.6, 0.6, 0.6, 1.0));
	spotlight4->setExponent(20);
	spotlight4->setAmbient(Vector4(0.1, 0.1, 0.1, 1.0));
	spotlight4->setDirection(Vector3(0.0, -0, -1.0));

	LightSource* spotlight5 = new LightSource(GL_LIGHT5);
	spotlight5->setPosition(Vector4(2.5, 6.0, 4.0, 1.0));
	spotlight5->setSpecular(vec2);
	spotlight5->setCutOff(30.0);
	spotlight5->setDiffuse(Vector4(0.6, 0.6, 0.6, 1.0));
	spotlight5->setExponent(20);
	spotlight5->setAmbient(Vector4(0.1, 0.1, 0.1, 1.0));
	spotlight5->setDirection(Vector3(0.0, -0, -1.0));

	LightSource* spotlight6 = new LightSource(GL_LIGHT6);
	spotlight6->setPosition(Vector4(2.5, 1.0, 4.0, 1.0));
	spotlight6->setSpecular(vec2);
	spotlight6->setCutOff(30.0);
	spotlight6->setDiffuse(Vector4(0.6, 0.6, 0.6, 1.0));
	spotlight6->setExponent(20);
	spotlight6->setAmbient(Vector4(0.1, 0.1, 0.1, 1.0));
	spotlight6->setDirection(Vector3(0.0, 0, -1.0));

	//Frog headlight
	LightSource* spotlight7 = new LightSource(GL_LIGHT7);
	spotlight7->setPosition( Vector4( frog->getPosition().getX(), frog->getPosition().getY(), frog->getPosition().getZ(), 0.0) );
	spotlight7->setSpecular(Vector4(0.95, 0.95, 0.95, 1.0));
	spotlight7->setCutOff(30.0);
	spotlight7->setDiffuse(Vector4(0.95, 0.95, 0.95, 1.0));
	spotlight7->setExponent(10);
	spotlight7->setAttenuation(Vector3(4.0, 2.0, 0.0));
	spotlight7->setAmbient(Vector4(0.5, 0.5, 0.5, 1.0));
	spotlight7->setDirection(Vector3(0.0, 1.0, -1.0));
	

	man->addLightSource(globalIllumination);
	man->addLightSource(spotlight1);
	man->addLightSource(spotlight2);
	man->addLightSource(spotlight3);
	man->addLightSource(spotlight4);
	man->addLightSource(spotlight5);
	man->addLightSource(spotlight6);
	man->addLightSource(spotlight7);
	man->setFrogLight(spotlight7);
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
	spawnWorldObjects();										// Initializes the World, creating necessary objects. 
	glutTimerFunc(17, updateForward, 0);						// Start the Update Cycle.
	glutMainLoop();
	return 0;
}
