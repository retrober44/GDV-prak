#define _CRT_SECURE_NO_WARNINGS

#include <iostream> 
#include <conio.h>
#include <GL\freeglut.h>         //lädt alles für OpenGL
#include "car.h"
#include "glm/glm.hpp"
#include <vector>
#include <iostream>
#include <list>
#include <cassert>
#include <sstream>
#include <stdexcept>
#include <cmath>
#include <stdio.h>
#include <stdlib.h>

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

float camx = -5;
float camy = 5;
float camz = 30;

GLUquadric* qobj;
car kfz(1);


float deltaAngle = 0.0f;
int xOrigin = -1;

float angle = 0.0;
float lx = 0.0f, lz = .0f;
float x = 10.0f, y, z = 10.0f;

float camX = 10.0f, camXmov = 0.f, camY = 3.f, camZ = 10.0f, camZmov = -1.f;
float camAngle = 0.0f;

bool leftMov = false, rightMov = false;
bool rightClick = false;

float mouseXPos = 0.f;

float originX = 0;



std::vector< unsigned int > vertexIndices, uvIndices, normalIndices;
std::vector< glm::vec3 > temp_vertices;
std::vector< glm::vec2 > temp_uvs;
std::vector< glm::vec3 > temp_normals;

std::vector< glm::vec3 > vertices;
std::vector< glm::vec2 > uvs;
std::vector< glm::vec3 > normals; // Won't be used at the moment.

bool loadOBJ(
	const char* path,
	std::vector < glm::vec3 >& out_vertices,
	std::vector < glm::vec2 >& out_uvs,
	std::vector < glm::vec3 >& out_normals
);












void mousecallback(int button, int state, int x, int y) {
	if (button == GLUT_RIGHT_BUTTON) {
		if (state == GLUT_DOWN) {
			rightClick = true;
			originX = x;
		}
		else {
			rightClick = false;
		}
	}

	if (button == 3) {
		camX = camX * -(.9f);
		camY = camY * -(.9f);
		camZ = camZ * -(.9f);
	}
	if (button == 4) {

		camX = camX * 1.1f;
		camY = camY * 1.1f;
		camZ = camZ * 1.1f;
	}
	mouseXPos = x;
}

void mouseMove(int x, int y) {
	// this will only be true when the left button is down

	if (rightClick) {
		if (originX > x) {
			camAngle -= .01f;

		}
		if (originX < x) {
			camAngle += .01f;
		}

		camXmov = sin(camAngle);

		camZmov = -cos(camAngle);

		cout << camX << endl;
	}

}

void coordinate_system() {
	//x-Achse (rot)
	glColor3f(1, 0, 0);
	glBegin(GL_LINES);
	glVertex3f(-20, 0, 0);
	glVertex3f(20, 0, 0);
	glEnd();

	//y-Achse (grün)
	glColor3f(0, 1, 0);
	glBegin(GL_LINES);
	glVertex3f(0, -20, 0);
	glVertex3f(0, 20, 0);
	glEnd();

	//z-Achse (blau)
	glColor3f(0, 0, 1);
	glBegin(GL_LINES);
	glVertex3f(0, 0, -20);
	glVertex3f(0, 0, 20);
	glEnd();
}


void Init()
{
	bool res = loadOBJ("gtr.obj", vertices, uvs, normals);
	// Hier finden jene Aktionen statt, die zum Programmstart einmalig 
	// durchgeführt werden müssen
	glClearColor(0.5, 0.5, 0.5, 0.0);
	glEnable(GL_DEPTH_TEST);
	glClearDepth(1.0);
	glutMouseFunc(mousecallback);
	glutMotionFunc(mouseMove);

	qobj = gluNewQuadric();
	gluQuadricNormals(qobj, GLU_SMOOTH);
}

void RenderScene() //Zeichenfunktion
{

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	// Hier befindet sich der Code der in jedem Frame ausgefuehrt werden muss
	glLoadIdentity();   // Aktuelle Model-/View-Transformations-Matrix zuruecksetzen
	
	//Wo schaut die Kamera an
	//gluLookAt(camx, camy, camz, -3., 0., 0., 0., 1., 0.);
	//gluLookAt(camX * camXmov, camY, camZ * camZmov,0, 0, 0,0.0f, 4.0f, 0.0f);
	gluLookAt(camX * camXmov, camY, camZ * camZmov,TraX, TraY, TraZ,0.0f, 4.0f, 0.0f);
	//gluLookAt(TraX-4, TraY+10, TraZ-4, TraX+3, TraY-1, TraZ+3, 0.0f, 4.0f, 0.0f);

	//Koordinanten System Aufruf
	coordinate_system();

	//Asphalt
	glPushMatrix();
	glColor3f(0.3, 0.3, 0.3);
	glScalef(21, 0.1, 22);
	glTranslatef(-0.35, -10.5, +0.3);
	glutSolidCube(1);
	glPopMatrix();

	//Ampelstange
	glColor3f(0.75, 0.75, 0.75);
	glPushMatrix();
	glTranslatef(2, 5, 2);
	glRotatef(90, 1, 0, 0);
	glutSolidCylinder(0.2, 7, 100, 100);
	glPopMatrix();

	//Ampelkasten
	glPushMatrix();
	glScalef(1, 1.5, 1);
	glTranslatef(2, 4, 2);
	glutSolidCube(1.5);
	glPopMatrix();

	//Rotes Lampe
	glPushMatrix();
	glColor3f(1, 0, 0);
	glTranslatef(2, 6.5, 2.7);
	glutSolidSphere(0.3, 100, 100);
	glPopMatrix();

	//Gelbe Lampe
	glPushMatrix();
	glColor3f(1, 1, 0);
	glTranslatef(2, 6, 2.7);
	glutSolidSphere(0.3, 100, 100);
	glPopMatrix();

	//Grüne Lampe
	glPushMatrix();
	glColor3f(0, 1, 0);
	glTranslatef(2, 5.5, 2.7);
	glutSolidSphere(0.3, 100, 100);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-2, 1, 2);
	glScalef(10, 10,10);
	glRotatef(90, 1, 0, 0);
	glBegin(GL_TRIANGLES);
	for (int j = 0; j < normalIndices.size(); j++) {

		unsigned int normalIndex = normalIndices[j];

		glm::vec3 nv = temp_normals[normalIndex - 1];
		glNormal3f(nv.x, nv.y, nv.z);


	}
	glEnd();

	glBegin(GL_TRIANGLES);
	for (int i = 0; i < vertexIndices.size(); i++)
	{
			unsigned int vertexIndex = vertexIndices[i];
			glm::vec3 fv = temp_vertices[vertexIndex - 1];
			glVertex3f(fv.x, fv.y, fv.z);

		
	}
	glEnd();
	glPopMatrix();
	


	kfz.showCar(fRotation, rotX, rotY, TraX, TraY, TraZ, leftTurn, tieferlegung);

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

	float speed = 0.1; //ein Hundertstel vom Counter um auf der Fläche zu fahren


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
	case GLUT_KEY_F1:
		//2te Cam:
		camx = -5;
		camy = 5;
		camz = 30;
 		break;
	case GLUT_KEY_F2:
		//Standarcam:
		camx = -5;
		camy = 10;
		camz = 50;
		break;
	case GLUT_KEY_F3:
		camY = camY + 1;
		break;
	case GLUT_KEY_F4:
		camY = camY - 1;
		break;
	}
	glutPostRedisplay();

}




int main(int argc, char** argv)
{
	glutInit(&argc, argv);                // GLUT initialisieren
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(1000, 600);
	// Fenster-Konfiguration
	glutCreateWindow("Rober");   // Fenster-Erzeugung
	glutDisplayFunc(RenderScene);         // Zeichenfunktion bekannt machen
	glutReshapeFunc(Reshape);
	glutSpecialFunc(KeyHandler);
	// TimerCallback registrieren; wird nach 10 msec aufgerufen mit Parameter 0  
	glutTimerFunc(10, Animate, 0);

	cout << "Pfeiltaste Oben und Unten um die G-Klasse tieferzulegen." << endl;
	Init();
	glutMainLoop();
	return 0;
}

bool loadOBJ(const char* path, std::vector<glm::vec3>& out_vertices, std::vector<glm::vec2>& out_uvs, std::vector<glm::vec3>& out_normals)
{

	FILE* file = fopen(path, "r");
	if (file == NULL) {
		printf("Impossible to open the file !\n");
		return false;
	}

	while (1) {

		char lineHeader[128];
		// read the first word of the line
		int res = fscanf(file, "%s", lineHeader);
		if (res == EOF)
			break; // EOF = End Of File. Quit the loop.

		// else : parse lineHeader

		if (strcmp(lineHeader, "v") == 0) {
			glm::vec3 vertex;
			fscanf(file, "%f %f %f\n", &vertex.x, &vertex.y, &vertex.z);
			temp_vertices.push_back(vertex);

		}
		else if (strcmp(lineHeader, "vt") == 0) {
			glm::vec2 uv;
			fscanf(file, "%f %f\n", &uv.x, &uv.y);
			temp_uvs.push_back(uv);
		}
		else if (strcmp(lineHeader, "vn") == 0) {
			glm::vec3 normal;
			fscanf(file, "%f %f %f\n", &normal.x, &normal.y, &normal.z);
			temp_normals.push_back(normal);
		}
		else if (strcmp(lineHeader, "f") == 0) {
			std::string vertex1, vertex2, vertex3;
			unsigned int vertexIndex[3], uvIndex[3], normalIndex[3];
			int matches = fscanf(file, "%d/%d/%d %d/%d/%d %d/%d/%d\n", &vertexIndex[0], &uvIndex[0], &normalIndex[0], &vertexIndex[1], &uvIndex[1], &normalIndex[1], &vertexIndex[2], &uvIndex[2], &normalIndex[2]);
			if (matches != 9) {
				printf("File can't be read by our simple parser : ( Try exporting with other options\n");
				return false;
			}


			vertexIndices.push_back(vertexIndex[0]);
			vertexIndices.push_back(vertexIndex[1]);
			vertexIndices.push_back(vertexIndex[2]);
			uvIndices.push_back(uvIndex[0]);
			uvIndices.push_back(uvIndex[1]);
			uvIndices.push_back(uvIndex[2]);
			normalIndices.push_back(normalIndex[0]);
			normalIndices.push_back(normalIndex[1]);
			normalIndices.push_back(normalIndex[2]);

		}

		for (unsigned int i = 0; i < vertexIndices.size(); i++) {
			unsigned int vertexIndex = vertexIndices[i];
			glm::vec3 vertex = temp_vertices[vertexIndex - 1];
			out_vertices.push_back(vertex);
		}

	}

	return false;
}
