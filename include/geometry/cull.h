#pragma once
#include "geometry.h"
#include <functional>

// Cull face according to the uv coordinate. When the fragment is culled,
// we regard as there's no intersection point, even if the underlying
// geometry do calculated some intersection point.

typedef std::function<bool(const Vector)> GeometricCull;

class Cull : public Delegator {
	GeometricCull m_cull;
public:
	Cull(GeometricCull, GeometryDelegate);
	virtual ~Cull() {}

	virtual Maybe<Vector> intersect(const Vector&, const Vector&);
};
