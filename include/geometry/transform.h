#pragma once
#include "geometry.h"
#include "matrix.h"
#include <functional>

class Transform : public Geometry {
protected:
	virtual Geometry& geometry() const = 0;

	// The transformation matrix.
	virtual const Matrix& matrix() const = 0;

	// The invert of transformation matrix.
	virtual const Matrix& invert() const = 0;
public:
	Transform() {}
	virtual ~Transform() {}

	virtual Maybe<Vector> intersect(const Vector&, const Vector&);

	virtual Vector tangent0(const Vector&);

	virtual Vector tangent1(const Vector&);

	virtual Vector joint(const Vector&);
};


class DefaultTransform : public Transform {
	Matrix m_matrix, m_invert;
	const std::function<Geometry&()> m_geometry;
protected:
	virtual Geometry& geometry() const { return m_geometry(); }
	virtual const Matrix& matrix() const { return m_matrix; }
	virtual const Matrix& invert() const { return m_invert; }
public:
	DefaultTransform(const Matrix&, const std::function<Geometry&()>);
	virtual ~DefaultTransform() {}
};
