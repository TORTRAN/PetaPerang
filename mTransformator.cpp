#include "Transformator.h"

int main() {
	Transformator t;
	vector<Point> v,w;
	Point pivot(1.5,1.5);
	
	cout << cos(2 * PI) << endl;
	cout << "----" << endl;
	
	Point p0(0,0);
	Point p1(0,3);
	Point p2(3,0);
	Point p3(3,3);
	
	Point q0(0,0);
	Point q1(0,3);
	Point q2(3,0);
	Point q3(3,3);
	
	v.push_back(p0);
	v.push_back(p1);
	v.push_back(p2);
	v.push_back(p3);
	
	w.push_back(q0);
	w.push_back(q1);
	w.push_back(q2);
	w.push_back(q3);
	
	cout << "Vector v:" << endl;
	for (vector<Point>::iterator it = v.begin(); it != v.end(); ++it) {
		cout << "X: " << (*it).x << " Y: " << (*it).y << endl;
	}
	
	v = t.rotatePoligon(v,360.0);
	cout << "Vector v:" << endl;
	for (vector<Point>::iterator it = v.begin(); it != v.end(); ++it) {
		cout << "X: " << (*it).x << " Y: " << (*it).y << endl;
	}
	cout << endl;
	return 0;
}