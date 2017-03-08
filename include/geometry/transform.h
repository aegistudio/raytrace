#pragma once
#include "geometry.h"
#include "matrix.h"

class Transform : public Geometry {
protected:
	virtual Geometry& geometry() const = 0;
	virtual Matrix& matrix() const = 0;
	virtual Matrix& invertMatrix() const = 0;
public:
	Transform() {}
	virtual ~Transform() {}

	virtual Maybe<Vector> intersect(const Vector&) = 0;

	virtual Vector normal(const Vector&) = 0;

	virtual Vector joint(const Vector&) = 0;
};
