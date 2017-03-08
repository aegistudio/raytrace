#include "common.h"

#include <stdio.h>
#include <stdlib.h>
#define EPSILON 1e-7

bool dblCompare(double l, double r) {
	return (l - r) * (l - r) <= EPSILON * EPSILON;
}

bool expect(double l, double r) {
	if(dblCompare(l, r)) return true;
	std::cout << "Expected " << l << ", Got " << r << std::endl;
	return false;
}

bool vecCompare(const Vector& l, const Vector& r) {
	if(!dblCompare(l.x, r.x)) return false;
	if(!dblCompare(l.y, r.y)) return false;
	if(!dblCompare(l.z, r.z)) return false;
	return true;
}

bool expect(Vector l, Vector r) {
	if(vecCompare(l, r)) return true;
	std::cout << "Expected " << l
		<< ", Got " << r
		<< std::endl;
	return false;
}

Vector vectorize(const char* arg) {
	double vx, vy, vz;
	sscanf(arg, "(%lf,%lf,%lf)", &vx, &vy, &vz);
	return Vector(vx, vy, vz);
}

std::ostream& operator<<(std::ostream& o, const Vector& _) {
	return o << "(" << _.x << "," << _.y << "," << _.z << ")";
}

std::ostream& operator<<(std::ostream& o, const Matrix& _) {
	o << "[" << std::endl;
	for(int i = 0; i < 4; i ++) {
		o << "  [";
		o << _.m[i][0];
		for(int j = 1; j < 4; j ++) {
			o << "," << _.m[i][j];
		}
		o << "]" << std::endl;
	}
	return o << "]";
}
