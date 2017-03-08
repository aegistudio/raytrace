#include "geometry/vector.h"
#include <math.h>

#define vectorMake(x, y, z)\
	Vector((x), (y), (z))

Vector Vector::add(const Vector& _) const {
    return vectorMake(x + _.x, y + _.y, z + _.z);
}

Vector Vector::subtract(const Vector& _) const {
    return vectorMake(x - _.x, y - _.y, z - _.z);
}

Vector Vector::multiply(double k) const {
	return vectorMake(x * k, y * k, z * k);
}

double Vector::squareModulus() const {
	return dot(*this);
}

double Vector::modulus() const {
    return sqrt(squareModulus());
}

double Vector::dot(const Vector& _) const {
	return x * _.x + y *_.y + z * _.z;
}

Vector Vector::cross(const Vector&_) const {
    double x1 = x,		y1 = y,		z1 = z;
    double x2 = _.x,	y2 = _.y,	z2 = _.z;
    return vectorMake(
			y1 * z2 - y2 * z1,
			z1 * x2 - x1 * z2,
			x1 * y2 - x2 * y1);
}

Vector Vector::direction() const {
	return operator/(modulus());
}

// A & B = !A !B cos <A, B>
// A | B = !A cos <A, B> * ~B
//		= A & B / (!B) ^ 2 * B
//		= A & B / B.squareModulus() * B
//
Vector Vector::project(const Vector& _) const {
	return (operator&(_) / _.squareModulus()) * _;
}

double Vector::span(const Vector& _) const {
    double cosine = operator&(_) / modulus() / !_;
    return acos(cosine);
}
