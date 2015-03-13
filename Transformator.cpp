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

vector<Point> Transformator::reflectPoligonXAxis(vector<Point> P) {
	for (vector<Point>::iterator it = P.begin(); it != P.end(); ++it) {
		(*it).y *= -1;
		(*it).y = (fabs((*it).y - 0) < 0.000001) ? 0 : (*it).y;
	}
	return P;
}

vector<Point> Transformator::reflectPoligonYAxis(vector<Point> P) {
	for (vector<Point>::iterator it = P.begin(); it != P.end(); ++it) {
		(*it).x *= -1;
		(*it).x = (fabs((*it).x - 0) < 0.000001) ? 0 : (*it).x;
	}
	return P;
}

vector<Point> Transformator::rotatePoligon(vector<Point> P, float degrees) {
	float rad = degrees * PI / 180, cosx, cosy, sinx, siny;
	Point temp(0,0);
	for (vector<Point>::iterator it = P.begin(); it != P.end(); ++it) {
		//fill the variables
		temp.x = (*it).x; temp.y = (*it).y;
		cosx = cos(rad) * temp.x; cosy = cos(rad) * temp.y;
		sinx = sin(rad) * temp.x; siny = sin(rad) * temp.y;
		//set to 0
		cosx = (fabs(cosx - 0) < 0.000001) ? 0 : cosx;
		cosy = (fabs(cosy - 0) < 0.000001) ? 0 : cosy;
		sinx = (fabs(sinx - 0) < 0.000001) ? 0 : sinx;
		siny = (fabs(siny - 0) < 0.000001) ? 0 : siny;
		//rotates the point
		(*it).x = cosx - siny;
		(*it).y = cosy + sinx;
	}
	return P;
}

vector<Point> Transformator::rotatePoligonWithPivot(vector<Point> P, float degrees, Point pivot) {
	float rad = degrees * PI / 180, cosx, cosy, sinx, siny;
	Point temp(0,0);
	for (vector<Point>::iterator it = P.begin(); it != P.end(); ++it) {
		//changes the pivot point
		temp.x = (*it).x - pivot.x; 
		temp.y = (*it).y - pivot.y;
		//fill the variables
		temp.x = (*it).x; temp.y = (*it).y;
		cosx = cos(rad) * temp.x; cosy = cos(rad) * temp.y;
		sinx = sin(rad) * temp.x; siny = sin(rad) * temp.y;
		//set to 0
		cosx = (fabs(cosx - 0) < 0.000001) ? 0 : cosx;
		cosy = (fabs(cosy - 0) < 0.000001) ? 0 : cosy;
		sinx = (fabs(sinx - 0) < 0.000001) ? 0 : sinx;
		siny = (fabs(siny - 0) < 0.000001) ? 0 : siny;
		//rotates the point
		(*it).x = cosx - siny;
		(*it).y = cosy + sinx;
		//returns the pivot point
		(*it).x += pivot.x;
		(*it).y += pivot.y;
	}
	return P;
}

vector<Point> Transformator::resizePoligon(vector<Point> P, float multiplier) {
	//TODO stub
}