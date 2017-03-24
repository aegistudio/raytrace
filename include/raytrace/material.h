#pragma once
#include "../geometry/vector.h"

// The material depicts the light response for a certain surface.
typedef struct material_t {
	Vector ambient;			// The ambient response of this material.
	Vector diffuse;			// The diffuse response of this material.
	Vector specular;		// The specular response of this material.
	Vector refract;			// The refact response of this material.

	double refraction = 1.0;	// The refraction factor, or c0/n = c.
} Material;

// Body shader evaluates the material on a certain point of the surface.
// The calculation will be performed once the geometric shader finishes the
// calculation of intersection. Which provides us with the UV information.
class BodyShader {
public:
	virtual Material material(const Body&, const Vector&);
};
