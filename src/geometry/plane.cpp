#include "geometry/plane.h"
#include "geometry/matrix.h"

#include <iostream>

Plane::Plane(const Vector& _x, const Vector& _y):
	x(_x), y(_y), z(~(_x * _y)) {}

Maybe<Vector> Plane::intersect(Vector d, Vector c) {
	double coefficient = d & z;
	if(coefficient != 0) {
		double formulaArray[4][4] = {
			{x.x, y.x, d.x, 0},
			{x.y, y.y, d.y, 0},
			{x.z, y.z, d.z, 0},
			{0,   0,   0,   1},
		};
		Matrix formula(formulaArray);
		Vector v = (~formula) * c;
		if(v.z > 0) return Maybe<Vector>();
		else return Vector(v.x, v.y,
			coefficient > 0? v.z : -v.z);
	}
	else return Maybe<Vector>();
}

Vector Plane::normal(Vector uv) {
	if(uv.z == 0) return Vector(0, 0, 0);
	else return uv.z > 0? z : -z;
}

Vector Plane::joint(Vector uv) {
	return uv.x * x + uv.y * y;
}
