#pragma once

#include "vector.h"
#include "../maybe.h"

#include <functional>

/**
 * Defines a geometric body in the space. Which we
 * only concern, when a ray originate from a point
 * in the space, will it intersect with the body,
 * and which point will it intersect with.
 *
 * The point is always depicted in uv coordinate,
 * and you have to query with the geometry body
 * again for normal and intersection point.
 */

class Geometry {
public:
	virtual ~Geometry() {}
	// Query for the UV coordinate. The UV coordinate
	// has its own meaning in different geometric body
	// but should be a map to normal and joint.
	virtual Maybe<Vector> intersect(const Vector&, const Vector& = {0,0,0}) = 0;

	// The normal will be calculated from the outer product
	// of tangent vectors. Which means N = t0 * t1.
	virtual Vector tangent0(const Vector& uv) = 0;

	virtual Vector tangent1(const Vector& uv) = 0;

	// Query for the normal vector.
	inline Vector normal(const Vector& uv) {
		return ~(tangent0(uv) * tangent1(uv));
	};

	// Query for the conjunction point.
	virtual Vector joint(const Vector& uv) = 0;
};

/**
 * When the geometry object takes the role of controlling
 * calculation for other geometric objects, we shall call
 * it a delegator.
 */

typedef std::function<Geometry&()> GeometryDelegate;

class Delegator : public Geometry {
protected:
	GeometryDelegate m_delegate;
public:
	Delegator(GeometryDelegate delegate)
		: m_delegate(delegate) {}

	virtual ~Delegator() {}

	virtual Maybe<Vector> intersect(const Vector& d, const Vector& c) {
		return m_delegate().intersect(d, c);
	}

	virtual Vector tangent0(const Vector& _) {
		m_delegate().tangent0(_);
	}

	virtual Vector tangent1(const Vector& _) {
		m_delegate().tangent1(_);
	}

	virtual Vector joint(const Vector& _) {
		m_delegate().joint(_);
	}
};
