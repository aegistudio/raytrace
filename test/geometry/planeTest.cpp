#include "geometry/plane.h"
#include "common.h"
#include "geomtest.h"
#include "../testing.h"

void test0() {
	Vector x(2, 0, 0), y(0, 3, 0);
	Plane plane(x, y);

    expectIntersect(plane, {0, 0, 1}, {0, 0, -1},
		{0, 0, -1}, {0, 0, -1}, {0, 0, 0});
}

void test1() {
	// Define the x, y - plane, and cast a ray
	// from (0, 0, 1) with direction (0, 0, -1).
	Vector x(1, 0, 0), z(0, 0, 1);
	Plane plane(z, x);

    expectIntersect(plane, {0, -1, 0}, {0, 1, 0},
		{0, 0, 1}, {0, 1, 0}, {0, 0, 0});
}

int main(int argv, char** args) {
	TEST_CASE(test0);
	TEST_CASE(test1);
	return 2;
}
