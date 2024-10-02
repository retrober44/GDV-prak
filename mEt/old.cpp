// GD-Praktikum:   teil_1.cpp  (Teil 1: Start-Programm)
// Hergenroether / Groch    Last Update: 05.07.2014

/*
#include <iostream> 
#include <conio.h>
#include <GL\freeglut.h>         //lädt alles für OpenGL

float fRotation = 315.0;
float rotX = 0;
float rotY = 0;

float TraX = 0;
float TraY = 0;
float TraZ = 0;

float leftTurn = 0;

float tieferlegung = 0;

using namespace std;


int counter = 0;


GLUquadric* qobj;

void Init()
{
	// Hier finden jene Aktionen statt, die zum Programmstart einmalig 
	// durchgeführt werden müssen
	glClearColor(0.5, 0.5, 0.5, 0.0);
	glEnable(GL_DEPTH_TEST);
	glClearDepth(1.0);

	qobj = gluNewQuadric();
	gluQuadricNormals(qobj, GLU_SMOOTH);



}

void RenderScene() //Zeichenfunktion
{

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);


	// Hier befindet sich der Code der in jedem Frame ausgefuehrt werden muss
	glLoadIdentity();   // Aktuelle Model-/View-Transformations-Matrix zuruecksetzen



	gluLookAt(-5., 5., 30, 0., 0., 0., 0., 1., 0.);

	glPushMatrix();
	glColor3f(0.1, 0.1, 0.1);
	glScalef(11, 0.1, 13);
	glTranslatef(-0.35, -10.5, +0.3);
	glutSolidCube(1);
	glPopMatrix();

	//ampel
	glColor3f(0.75, 0.75, 0.75);
	glPushMatrix();
	glTranslatef(2, 5, 2);
	glRotatef(90, 1, 0, 0);
	glutSolidCylinder(0.2, 7, 100, 100);
	glPopMatrix();

	glPushMatrix();
	glScalef(1, 1.5, 1);
	glTranslatef(2, 4, 2);
	glutSolidCube(1.5);
	glPopMatrix();

	glPushMatrix();
	glColor3f(1, 0, 0);
	glTranslatef(2, 6.5, 2.7);
	glutSolidSphere(0.3, 100, 100);
	glPopMatrix();

	glPushMatrix();
	glColor3f(1, 1, 0);
	glTranslatef(2, 6, 2.7);
	glutSolidSphere(0.3, 100, 100);
	glPopMatrix();

	glPushMatrix();
	glColor3f(0, 1, 0);
	glTranslatef(2, 5.5, 2.7);
	glutSolidSphere(0.3, 100, 100);
	glPopMatrix();





	glRotatef(rotX, 1.0, 0.0, 0.0);  // Rotation um die x-Achse 
	glRotatef(rotY, 0.0, 1.0, 0.0);  // Rotation um die y-Achse

	//glScalef(1, TraY, 1);
	glColor3f(0.9, 0.91, 0.98);


	glTranslatef(TraX, TraY, TraZ);
	glRotatef(leftTurn, 0, 1, 0);

	glPushMatrix();


	glTranslatef(0, tieferlegung, 0);

	//windschutzscheibe
	glPushMatrix();
	glRotatef(60, 0, 0, 1);
	glTranslatef(0.5, 0.43, 0);
	glScalef(1.1, 1.2, 2);
	glutSolidCube(1.0);
	glPopMatrix();

	//Chassi
	glPushMatrix();
	glScalef(3.5, 1, 2);
	glutSolidCube(1.0);
	glPopMatrix();

	glPushMatrix();
	glScalef(2.1, 1.2, 2);
	glTranslatef(0.33, 0.8, 0);
	glutSolidCube(1.0);
	glPopMatrix();

	glColor3f(0, 0, 0);
	glPushMatrix();
	glRotatef(90, 0, 1, 0);
	glTranslatef(0.1, 0.7, 1.9);
	glutSolidCylinder(0.5, 0.3, 10, 100);
	glPopMatrix();


	glColor3f(0.8, 0.3, 0.1);
	glPushMatrix();
	glTranslatef(-1.65, 0.5, 0.85);
	glutSolidCube(0.1);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-1.65, 0.5, -0.85);
	glutSolidCube(0.1);
	glPopMatrix();


	glColor3f(1, 1, 0);
	glRotatef(-90, 0, 1, 0);
	glPushMatrix();
	glTranslatef(0.5, 0, 1.5);
	gluCylinder(qobj, 0.1, 1, 5, 100, 100);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-0.5, 0, 1.5);
	gluCylinder(qobj, 0.1, 1, 5, 100, 100);
	glPopMatrix();


	glPopMatrix();

	glColor3f(1, 0, 0);

	//reifen
	glPushMatrix();
	glTranslatef(-1., -0.5, 0.8);
	glRotatef(-fRotation, 0, 0, 1);
	glColor4f(0, 0, 0, 1);
	glutSolidCylinder(0.55, 0.3, 8, 100);
	//glColor3f(1, 1, 1);
	//glutSolidCylinder(0.4, 0.3, 10 , 100);
	glPopMatrix();


	glPushMatrix();
	glTranslatef(1., -0.5, 0.8);
	glColor4f(0, 0, 0, 1);
	glRotatef(-fRotation, 0, 0, 1);
	glutSolidCylinder(0.55, 0.3, 8, 100);
	//glColor3f(1, 1, 1);
	//glutSolidCylinder(0.4, 0.3, 10, 100);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(1., -0.5, -1.1);
	glColor4f(0, 0, 0, 1);
	glRotatef(-fRotation, 0, 0, 1);
	glutSolidCylinder(0.55, 0.3, 8, 100);
	//glColor3f(1, 1, 1);
	 //glutSolidCylinder(0.4, 0.3, 10, 100);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-1., -0.5, -1.1);
	glColor4f(0, 0, 0, 1);
	glRotatef(-fRotation, 0, 0, 1);
	glutSolidCylinder(0.55, 0.3, 8, 100);
	//glColor3f(1, 1, 1);
	//glutSolidCylinder(0.4, 0.3, 10, 100);
	glPopMatrix();
	glPopMatrix();


	glColor3f(1, 0, 0);



	//felgen 
	glPushMatrix();
	glTranslatef(-1, -0.15, 1.1);
	glRotatef(90, 1, 0, 0);
	glRotatef(-fRotation, 0, 0, 1);
	glutSolidCylinder(0.05, 0.7, 100, 100);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(1, -0.15, 1.1);
	glRotatef(90, 1, 0, 0);
	glRotatef(-fRotation, 0, 0, 1);
	glutSolidCylinder(0.05, 0.7, 100, 100);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(1, -0.15, -1.1);
	glRotatef(90, 1, 0, 0);
	glRotatef(-fRotation, 0, 0, 1);
	glutSolidCylinder(0.05, 0.7, 100, 100);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-1, -0.15, -1.1);
	glRotatef(90, 1, 0, 0);
	glRotatef(-fRotation, 0, 0, 1);
	glutSolidCylinder(0.05, 0.7, 100, 100);
	glPopMatrix();





	glFlush();
	glutSwapBuffers();
}

void Reshape(int width, int height)
{
	// Matrix für Transformation: Frustum->viewport
	glMatrixMode(GL_PROJECTION);
	// Aktuelle Transformations-Matrix zuruecksetzen
	glLoadIdentity();
	// Viewport definieren
	glViewport(0, 0, width, height);
	// Frustum definieren (siehe unten)
	gluPerspective(45., 1., 0.1, 100);
	// Matrix für Modellierung/Viewing
	glMatrixMode(GL_MODELVIEW);
	// Hier finden die Reaktionen auf eine Veränderung der Größe des 
	// Graphikfensters statt
}

void Animate(int value)
{
	// Hier werden Berechnungen durchgeführt, die zu einer Animation der Szene  
	// erforderlich sind. Dieser Prozess läuft im Hintergrund und wird alle 
	// 1000 msec aufgerufen. Der Parameter "value" wird einfach nur um eins 
	// inkrementiert und dem Callback wieder uebergeben. 
	//std::cout << "value=" << value << std::endl;
	// RenderScene aufrufen

	fRotation = fRotation - 1; // Rotationswinkel aendern
	if (fRotation <= 0.0) {
		fRotation = fRotation + 360.0;
	}

	counter += 5;

	float speed = 0.05; //ein Hundertstel vom Counter um auf der Fläche zu fahren




	if (counter <= 800) {
		TraX -= speed;
		if (counter == 800) {
			leftTurn = 90;
		}
	}
	if (counter <= 1600 && counter > 800) {
		TraZ += speed;
		if (counter == 1600) {
			leftTurn = 180;
		}
	}
	if (counter <= 2400 && counter > 1600) {
		TraX += speed;
		if (counter == 2400) {
			leftTurn = 270;
		}
	}
	if (counter <= 3200 && counter > 2400) {
		TraZ -= speed;
		if (counter == 3200) {
			leftTurn = 360;
			counter = 0;
		}
	}













	glutPostRedisplay();
	// Timer wieder registrieren - Animate wird so nach 10 msec mit value+=1 aufgerufen.
	int wait_msec = 10;
	glutTimerFunc(wait_msec, Animate, ++value);



}

void KeyHandler(int key, int x, int y) {

	switch (key) {
	case GLUT_KEY_UP:
		if (tieferlegung < 0.4) {
			tieferlegung += 0.05;
		}
		break;
	case GLUT_KEY_DOWN:
		if (tieferlegung > -0.4) {
			tieferlegung -= 0.05;
		}
		break;
	case GLUT_KEY_LEFT:
		rotX -= 5;
		break;
	case GLUT_KEY_RIGHT:
		rotX += 5;

		break;
	}
	glutPostRedisplay();

}




int main(int argc, char** argv)
{
	glutInit(&argc, argv);                // GLUT initialisieren
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(600, 600);
	// Fenster-Konfiguration
	glutCreateWindow("Albin; Rober");   // Fenster-Erzeugung
	glutDisplayFunc(RenderScene);         // Zeichenfunktion bekannt machen
	glutReshapeFunc(Reshape);
	glutSpecialFunc(KeyHandler);
	// TimerCallback registrieren; wird nach 10 msec aufgerufen mit Parameter 0  
	glutTimerFunc(10, Animate, 0);

	cout << "Pfeiltaste Oben und Unten um die G-Klasse tieferzulegen." << endl;
	Init();
	glutMainLoop();
	return 0;
}*/
