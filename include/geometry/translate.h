#pragma once
#include "geometry.h"

// Move the geometric body inside by the 
// vector specified by translate.

class Translate : public Geometry {
protected:
	virtual Vector& translate() const = 0;
	virtual Geometry& geometry() const = 0;
public:
	Translate() {}
	virtual ~Translate() {}

	virtual Vector intersect(const Vector&) = 0;

	virtual Vector normal(const Vector&) = 0;

	virtual Vector joint(const Vector&) = 0;
};
