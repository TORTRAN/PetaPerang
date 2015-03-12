/*
 * Author: Try Ajitiono 13512052
 * Module: Transformation implementation for IF3260 Computer Graphics
 *
 */

#include "Transformater.h"

Transformater::Transformater() {
	//TODO stub
}

Transformater::~Transformater() {
	//TODO stub
}

vector<Point> Transformater::translatePoligon(vector<Point> P, float xMovement, float yMovement) {
	for (vector<Point>::iterator it = P.begin(); it != P.end(); ++it) {
		//iterate through whole vectors and adds some value to them (might be negative)
		(*it).x += xMovement;
		(*it).y += yMovement;
	}
	return P;
}

vector<Point> Transformater::reflectPoligon(vector<Point> P, Point reflectionPoint) {
	//TODO stub
}

vector<Point> Transformater::rotatePoligon(vector<Point> P, float degrees) {
	float rad = degrees * PI / 180;
	float tempx = 0;
	float tempy = 0;
	for (vector<Point>::iterator it = P.begin(); it != P.end(); ++it) {
		//rotates the point
		tempx = (*it).x; tempy = (*it).y;
		(*it).x = (cos(rad) * tempx) - (sin(rad) * tempy);
		(*it).y = (cos(rad) * tempy) + (sin(rad) * tempx);
	}
	return P;
}

vector<Point> Transformater::resizePoligon(vector<Point> P, float multiplier) {
	//TODO stub
}\