#pragma once

#include "vector.h"

// All transform are described in a homogenous matrix.
// As we are using 3-d vectors, the matrix should be of 4-d.
// The transform would perform like:
// | M t || v | - | Mv + t | - Clip - | (Mv + t) / (vq + r) |
// | q r || 1 | - | vq + 1 | -------- |          1          |

class Matrix {
public:
	double m[4][4];
	Matrix(const double _[4][4]);
	~Matrix() {}

	// Retrieve the discriminant of this matrix.
	double discriminant3(int, int) const;
	double discriminant() const;
	inline double operator*() const {
		return discriminant();
	}

	// Multiplex a transform by a former transform.
	Matrix multiply(const Matrix&) const;
	inline Matrix operator*(const Matrix& _) const {
		return multiply(_);
	}

	// Apply the transform matrix to a vector.
	Vector apply(const Vector&) const;
	inline Vector operator*(const Vector& _) const {
		return apply(_);
	}

	// Retrieve the invert transformation.
	Matrix invert() const;
	inline Matrix operator~() const {
		return invert();
	}

	// Load the identity matrix.
	static Matrix identity();

	// Translating a vector.
	static Matrix translate(const Vector& _);

	// Scale on the three axis at once.
	static Matrix scale(double factor);

	// Scaling the three components one by one.
	static Matrix scale(const Vector& _);

	// Rotation on each axis.
	static Matrix xRotate(double x);
	static Matrix yRotate(double y);
	static Matrix zRotate(double z);
};
