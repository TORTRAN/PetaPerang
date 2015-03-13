/*
 * Author: Try Ajitiono 13512052
 * Module: Transformation implementation for IF3260 Computer Graphics
 *
 */

#include "Transformator.h"

Transformator::Transformator() {
	//TODO stub
}

Transformator::~Transformator() {
	//TODO stub
}

vector<Point> Transformator::translatePoligon(vector<Point> P, float xMovement, float yMovement) {
	for (vector<Point>::iterator it = P.begin(); it != P.end(); ++it) {
		//iterate through whole vectors and adds some value to them (might be negative)
		(*it).x += xMovement;
		(*it).y += yMovement;
	}
	return P;
}

vector<Point> Transformator::reflectPoligon(vector<Point> P, Point reflectionPoint) {
	//TODO stub
}

vector<Point> Transformator::rotatePoligon(vector<Point> P, float degrees) {
	float rad = degrees * PI / 180;
	Point temp(0,0);
	for (vector<Point>::iterator it = P.begin(); it != P.end(); ++it) {
		//rotates the point
		temp.x = (*it).x; temp.y = (*it).y;
		(*it).x = (cos(rad) * temp.x) - (sin(rad) * temp.y);
		cout << "cos rad: " << (cos(rad)) << " sin rad: " << (sin(rad)) << endl;
		(*it).y = (cos(rad) * temp.y) + (sin(rad) * temp.x);
	}
	return P;
}

vector<Point> Transformator::rotatePoligonWithPivot(vector<Point> P, float degrees, Point pivot) {
	float rad = degrees * PI / 180;
	Point temp(0,0);
	for (vector<Point>::iterator it = P.begin(); it != P.end(); ++it) {
		//changes the pivot point
		temp.x = (*it).x - pivot.x; 
		temp.y = (*it).y - pivot.y;
		//rotates the point
		(*it).x = (cos(rad) * temp.x) - (sin(rad) * temp.y);
		(*it).y = (cos(rad) * temp.y) + (sin(rad) * temp.x);
		//returns the pivot point
		(*it).x += pivot.x;
		(*it).y += pivot.y;
	}
	return P;
}

vector<Point> Transformator::resizePoligon(vector<Point> P, float multiplier) {
	//TODO stub
}