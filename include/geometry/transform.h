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
	virtual const Matrix& invertMatrix() const = 0;

	// The upper-left 3x3 matrix and the (4,4) of matrix.
	virtual const Matrix& remain() const = 0;

	// The upper-left 3x3 matrix and the (4,4) of invert matrix.
	virtual const Matrix& invertRemain() const = 0;
public:
	Transform() {}
	virtual ~Transform() {}

	virtual Maybe<Vector> intersect(const Vector&, const Vector&) = 0;

	virtual Vector normal(const Vector&) = 0;

	virtual Vector joint(const Vector&) = 0;
};


class DefaultTransform : public Transform {
	Matrix m_matrix, m_invertMatrix, m_remain, m_invertRemain;
	const std::function<Geometry&()> m_geometry;
protected:
	virtual Geometry& geometry() const { return m_geometry(); }
	virtual const Matrix& matrix() const { return m_matrix; }
	virtual const Matrix& invertMatrix() const { return m_invertMatrix; }
	virtual const Matrix& remain() const { return m_remain; }
	virtual const Matrix& invertRemain() const { return m_invertRemain; }
public:
	DefaultTransform(const Matrix&, const std::function<Geometry&()>);
	~DefaultTransform() {}
};
