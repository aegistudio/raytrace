#include "geometry.h"

// A plane is rooted at (0, 0, 0) and defined by two eigen vectors.
// Please notice the eigen vectors should never be parallel in order
// to define a valid plane.

// The normal is calculated from the eigen vectors. And the w component of
// the UV coordinate should positive when the incoming vector is at
// different direction of the normal while is negative when the incoming
// vector is the same.

class Plane : public Geometry {
	Vector x, y, z;
public:
	Plane(const Vector&, const Vector&);
	virtual ~Plane() {}

	virtual Maybe<Vector> intersect(const Vector&, const Vector&);

	virtual Vector normal(const Vector&);

	virtual Vector joint(const Vector&);
};
