#include "geometry/plane.h"
#include "geometry/transform.h"
#include "common.h"
#include "geomtest.h"
#include "../testing.h"
#include "math.h"

void testNormal() {
	Vector x(2, 0, 0), y(0, 3, 0);
	Plane plane(x, y);

	// d = (0, 0, 1), c = (0, 0, 1).
	expectDisjoint(plane, {0, 0, 1}, {0, 0, 1});

	// d = (0, 0, 1), c = (0, 0, -1).
    expectIntersect(plane, {0, 0, 1}, {0, 0, -1},
		{0, 0, -1}, {0, 0, -1}, {0, 0, 0});

	// d = normalize(1, 1, -1), c = (0, 0, 1).
	expectIntersect(plane, ~Vector({1, 1, -1}), {0, 0, 1},
		{1./2, 1./3, sqrt(3)}, {0, 0, 1}, {1, 1, 0});
}

void testTransform() {
	Vector x(1, 0, 0), y(0, 1, 0), z(0, 0, 1);
	Plane fakePlane(x, y);

	Matrix transform = Matrix::rebase(z, x, y);
	DefaultTransform plane(transform,
		[&] () -> Geometry& {return fakePlane;});

    expectIntersect(plane, {0, -1, 0}, {0, 1, 0},
		{0, 0, 1}, {0, 1, 0}, {0, 0, 0});
}

int main(int argv, char** args) {
	TEST_CASE(testNormal);
	TEST_CASE(testTransform);
	return 2;
}
