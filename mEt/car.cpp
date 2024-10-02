#include "car.h"

using namespace std;

car::car(int k){
	kennnummer = k;
}

void car::showCar(float rota, float rotX, float rotY, float TraX, float TraY, float TraZ, float leftTurn, float tieferlegung) {

	if (this->kennnummer == 1) {

	// Rotation des Autos
	glRotatef(rotX, 1.0, 0.0, 0.0);  // Rotation um die x-Achse 
	glRotatef(rotY, 0.0, 1.0, 0.0);  // Rotation um die y-Achse

	glColor3f(0.9, 0.91, 0.98);		//glScalef(1, TraY, 1);

	glTranslatef(TraX, TraY, TraZ);	//Autobewegung
	glRotatef(leftTurn, 0, 1, 0); //Auto um die Kurven abbiegen
	glPushMatrix();
	glTranslatef(0, tieferlegung, 0); //Tieferlegung mit Input

	//Windschutzscheibe
	glColor3f(0, 0, 0);
	glPushMatrix();
	glRotatef(60, 0, 0, 1);
	glTranslatef(0.5, 0.43, 0);
	glScalef(1.1, 1.2, 2);
	glutSolidCube(1.0);
	glPopMatrix();

	//Rechter Außenspiegel
	glColor3f(0, 0, 0);
	glPushMatrix();
	glTranslatef(-0.2, 0.7, 1.1);
	glRotatef(90, 0, 0, 1);
	glRotatef(180, 1, 0, 0);
	glScalef(1.1, 1.2, 2);
	glutSolidTeaspoon(0.4);
	glPopMatrix();

	//Linker Außenspiegel
	glColor3f(0, 0, 0);
	glPushMatrix();
	glTranslatef(-0.2, 0.7, -1.1);
	glRotatef(270, 0, 0, 1);
	glScalef(1.1, 1.2, 2);
	glutSolidTeaspoon(0.4);
	glPopMatrix();

	//Unterboden
	glColor3f(0, 0, 0);
	glPushMatrix();
	glScalef(3.5, 1, 2);
	glutSolidCube(1.0);
	glPopMatrix();

	//Führerhaus
	glColor3f(0, 0, 0);
	glPushMatrix();
	glScalef(2.1, 1.2, 2);
	glTranslatef(0.33, 0.8, 0);
	glutSolidCube(1.0);
	glPopMatrix();

	//Ersatzreifen
	glColor3f(0, 0, 0);
	glPushMatrix();
	glRotatef(90, 0, 1, 0);
	glTranslatef(0.1, 0.7, 1.7);
	glutSolidCylinder(0.5, 0.3, 10, 100);
	glPopMatrix();

	//Linker Blinker
	glColor3f(0.8, 0.3, 0.1);
	glPushMatrix();
	glTranslatef(-1.65, 0.5, 0.85);
	glutSolidCube(0.1);
	glPopMatrix();

	//Rechter Blinker
	glColor3f(0.8, 0.3, 0.1);
	glPushMatrix();
	glTranslatef(-1.65, 0.5, -0.85);
	glutSolidCube(0.1);
	glPopMatrix();

	/*
	//Lichtkegel rechts
	glColor3f(1, 1, 0);
	glRotatef(-90, 0, 1, 0);
	glPushMatrix();
	glTranslatef(0.5, 0, 1.5);
	gluCylinder(qobj, 0.1, 1, 5, 100, 100);
	glPopMatrix();

	//Lichtkegel links
	glColor3f(1, 1, 0);
	glPushMatrix();
	glTranslatef(-0.5, 0, 1.5);
	gluCylinder(qobj, 0.1, 1, 5, 100, 100);
	glPopMatrix();
	*/
	glPopMatrix();

	//Alle Reifenfarben, außer Color wurde bereits gesetzt
	glColor3f(0.1, 0.1, 0.1);

	//Reifen 1
	glPushMatrix();
	glTranslatef(-1., -0.5, 0.8);
	glRotatef(-rota, 0, 0, 1);
	//glColor4f(0, 0, 0, 1);
	glutSolidCylinder(0.55, 0.3, 8, 100);
	//glColor3f(1, 1, 1);
	//glutSolidCylinder(0.4, 0.3, 10 , 100);
	glPopMatrix();

	//Reifen 2
	glPushMatrix();
	glTranslatef(1., -0.5, 0.8);
	//glColor4f(0, 0, 0, 1);
	glRotatef(-rota, 0, 0, 1);
	glutSolidCylinder(0.55, 0.3, 8, 100);
	//glColor3f(1, 1, 1);
	//glutSolidCylinder(0.4, 0.3, 10, 100);
	glPopMatrix();

	//Reifen 3
	glPushMatrix();
	glTranslatef(1., -0.5, -1.1);
	//glColor4f(0, 0, 0, 1);
	glRotatef(-rota, 0, 0, 1);
	glutSolidCylinder(0.55, 0.3, 8, 100);
	//glColor3f(1, 1, 1);
	//glutSolidCylinder(0.4, 0.3, 10, 100);
	glPopMatrix();

	//Reifen 4
	glPushMatrix();
	glTranslatef(-1., -0.5, -1.1);
	//glColor4f(0, 0, 0, 1);
	glRotatef(-rota, 0, 0, 1);
	glutSolidCylinder(0.55, 0.3, 8, 100);
	//glColor3f(1, 1, 1);
	//glutSolidCylinder(0.4, 0.3, 10, 100);
	glPopMatrix();
	glPopMatrix();

	/*
	//Felgenfarbe
	glColor3f(1, 0, 0);

	//Felge 1 
	glPushMatrix();
	glTranslatef(-1, -0.15, 1.1);
	glRotatef(90, 1, 0, 0);
	glRotatef(-rota, 0, 0, 1);
	glutSolidCylinder(0.05, 0.7, 100, 100);
	glPopMatrix();

	//Felge 2
	glPushMatrix();
	glTranslatef(1, -0.15, 1.1);
	glRotatef(90, 1, 0, 0);
	glRotatef(-rota, 0, 0, 1);
	glutSolidCylinder(0.05, 0.7, 100, 100);
	glPopMatrix();

	//Felge 3 
	glPushMatrix();
	glTranslatef(1, -0.15, -1.1);
	glRotatef(90, 1, 0, 0);
	glRotatef(-rota, 0, 0, 1);
	glutSolidCylinder(0.05, 0.7, 100, 100);
	glPopMatrix();

	//Felge 4 
	glPushMatrix();
	glTranslatef(-1, -0.15, -1.1);
	glRotatef(90, 1, 0, 0);
	glRotatef(-rota, 0, 0, 1);
	glutSolidCylinder(0.05, 0.7, 100, 100);
	glPopMatrix();
	*/

	}else if (this->kennnummer == 2) {


		// Rotation des Autos
		glRotatef(rotX, 1.0, 0.0, 0.0);  // Rotation um die x-Achse 
		glRotatef(rotY, 0.0, 1.0, 0.0);  // Rotation um die y-Achse

		glColor3f(0.9, 0.91, 0.98);		//glScalef(1, TraY, 1);

		glTranslatef(TraX, TraY, TraZ);	//Autobewegung
		glRotatef(leftTurn, 0, 1, 0); //Auto um die Kurven abbiegen
		glPushMatrix();
		glTranslatef(0, tieferlegung, 0); //Tieferlegung mit Input

		glColor3f(0.1, 0.1, 0.1);
		
		//Reifen 1
		glPushMatrix();
		glTranslatef(-1., -0.5, 0.8);
		glRotatef(-rota, 0, 0, 1);
		glutSolidCylinder(0.55, 0.3, 8, 100);
		glPopMatrix();

		//Reifen 2
		glPushMatrix();
		glTranslatef(1., -0.5, 0.8);
		glRotatef(-rota, 0, 0, 1);
		glutSolidCylinder(0.55, 0.3, 8, 100);
		glPopMatrix();

		//Reifen 3
		glPushMatrix();
		glTranslatef(1., -0.5, -1.1);
		glRotatef(-rota, 0, 0, 1);
		glutSolidCylinder(0.55, 0.3, 8, 100);
		glPopMatrix();

		//Reifen 4
		glPushMatrix();
		glTranslatef(-1., -0.5, -1.1);
		glRotatef(-rota, 0, 0, 1);
		glutSolidCylinder(0.55, 0.3, 8, 100);
		glPopMatrix();
		glPopMatrix();
		
		//Chassis
		glColor3f(1, 1, 1);
		glPushMatrix();
		glScalef(3.5, 1, 2);
		glutSolidCube(1.0);
		glPopMatrix();

		//Chassis
		glColor3f(0, 0, 0);
		glPushMatrix();
		glTranslatef(0, 1, 0);
		glScalef(2, 0.3, 2);
		glutSolidCube(1.0);
		glPopMatrix();

		//r1
		glColor3f(1, 0, 0);
		glPushMatrix();
		glTranslatef(1.6, 0, -0.3);
		glScalef(0.4, 0.5, 0.5);
		glutSolidCube(1.0);
		glPopMatrix();
		
		/*
		glPushMatrix();
		glColor3f(1, 0, 0);
		glBegin(GL_POLYGON);
		glTranslatef(4, 2, 0);
		glVertex2f(0, 0);
		glVertex2f(0, 1);
		glVertex2f(1, 1);
		glVertex2f(1, 1);
		glEnd();
		glPopMatrix();

		glPushMatrix();
		glColor3f(1, 1, 0);
		glBegin(GL_POLYGON);
		
		glVertex2f(1, 1);
		glVertex2f(1, 0);
		glVertex2f(0.6, 0.4);
		glVertex2f(0.4, 0.4);
		glTranslatef(4, 2, 0);
		glEnd();
		glPopMatrix();
		*/



	}
}
