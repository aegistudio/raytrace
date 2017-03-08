#pragma once

class Vector {
public:
	const double x, y, z;

	Vector(double _x, double _y, double _z):
		x(_x), y(_y), z(_z) {}

	~Vector(){}

	// Add this vector to another vector.
	Vector add(const Vector&) const;
	inline Vector operator+(const Vector& _) const {
		return add(_);
	}

	// Subtract another vector from this vector.
	Vector subtract(const Vector&) const;
	inline Vector operator-(const Vector& _) const {
		return subtract(_);
	}

	// Multiply this vector by a value.
	Vector multiply(double) const;
	inline Vector operator*(double _) const {
		return multiply(_);
	}

	inline Vector operator-() const {
		return multiply(-1.);
	}

	inline Vector operator/(double _) const {
		return multiply(1./_);
	}

	double squareModulus() const;
	double modulus() const;
	inline double operator!() const {
		return modulus();
	}

	// Return the direction of this vector.
	// Please notice that when you use ~vectorInstance
	// you are actually querying for its direction.
	Vector direction() const;
	inline Vector operator~() const {
		return direction();
	}

	// Return the cross (cartesian) product
	// between this vector and another vector.
	Vector cross(const Vector&) const;
	inline Vector operator*(const Vector& _) const {
		return cross(_);
	}

	// Return the dot product between this
	// vector and anothe rvector.
	// Please notice when you call aVec & bVec,
	// you are actually querying for their dot
	// product.
	double dot(const Vector&) const;
	inline double operator&(const Vector& _) const {
		return dot(_);
	}

	// Project this vector onto another vector.
	// Please notice that when you call aVec| bVec,
	// you are actually querying for the projection
	// of aVec onto bVec.
	Vector project(const Vector&) const;
	inline Vector operator|(const Vector& _) const {
		return project(_);
	}

	double span(const Vector&) const;
	inline double operator^(const Vector& _) const {
		return span(_);
	}
};

// The value multiply should be commutative.
inline Vector operator*(double k, const Vector& v) {
	return v * k;
}
