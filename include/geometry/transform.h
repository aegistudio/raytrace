#pragma once
#include "geometry.h"
#include "matrix.h"

class Transform : public Delegator {
protected:
	// The transformation matrix.
	virtual const Matrix& matrix() const = 0;

	// The invert of transformation matrix.
	virtual const Matrix& invert() const = 0;
public:
	Transform(GeometryDelegate _) : Delegator(_) {}
	virtual ~Transform() {}

	virtual Maybe<Vector> intersect(const Vector&, const Vector&);

	virtual Vector tangent0(const Vector&);

	virtual Vector tangent1(const Vector&);

	virtual Vector joint(const Vector&);
};


class DefaultTransform : public Transform {
	Matrix m_matrix, m_invert;
protected:
	virtual const Matrix& matrix() const { return m_matrix; }
	virtual const Matrix& invert() const { return m_invert; }
public:
	DefaultTransform(const Matrix&, GeometryDelegate);
	virtual ~DefaultTransform() {}
};
