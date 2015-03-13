#include "Transformator.h"

int main() {
	Transformator t;
	vector<Point> v;
	//
	Point p0(2,2);
	Point p1(2,5);
	Point p2(5,2);
	Point p3(5,5);
	//
	v.push_back(p0);
	v.push_back(p1);
	v.push_back(p2);
	v.push_back(p3);
	//
	cout << "Vector v (before):" << endl;
	for (vector<Point>::iterator it = v.begin(); it != v.end(); ++it) {
		cout << "X: " << (*it).x << " Y: " << (*it).y << endl;
	}
	//
	v = t.reflectPoligonYAxis(v);
	cout << "--------------" << endl;
	//
	cout << "Vector v (after):" << endl;
	for (vector<Point>::iterator it = v.begin(); it != v.end(); ++it) {
		cout << "X: " << (*it).x << " Y: " << (*it).y << endl;
	}
	cout << endl;
	return 0;
}