// Declares the common test utilities. So that it could be used
// in different test drivers.

#include "geometry/vector.h"
#include "geometry/matrix.h"
#include <iostream>

bool dblCompare(double l, double r);

bool expect(double l, double r);

bool vecCompare(const Vector& l, const Vector& r);

bool expect(Vector l, Vector r);

Vector vectorize(const char* arg);

std::ostream& operator<<(std::ostream& o, const Vector& _);
std::ostream& operator<<(std::ostream& o, const Matrix& _);
