#pragma once

#include "vector.h"

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
	// Query for the UV coordinate. The UV coordinate
	// has its own meaning in different geometric body
	// but should be a map to normal and joint.

	// If the geometric body does not intersect
	// with the geometric body, the result will be
	// three not-a-number.

	virtual std::optional<Vector> intersect(Vector vector, Vector origin) = 0;

	// Query for the normal vector.
	virtual Vector normal(Vector uv) = 0;

	// Query for the conjunction point.
	virtual Vector joint(Vector uv) = 0;
};