#pragma once
#include <iostream> 
#include <conio.h>
#include <GL\freeglut.h>         //l�dt alles f�r OpenGL
#include <string>

class car {

public:

	car(int);
	void showCar(float, float, float, float, float, float, float, float);
private:
	int kennnummer;
};