#include "geometry/cull.h"

Cull::Cull(GeometricCull cull, GeometryDelegate delegate):
	Delegator(delegate), m_cull(cull){}

Maybe<Vector> Cull::intersect(const Vector& d, const Vector& c) {
	Maybe<Vector> value = m_delegate().intersect(d, c);
	if(!value) return value;
	return m_cull(*value)? value : Maybe<Vector>();
}
