#include "geometry/transform.h"

Maybe<Vector> Transform::intersect(const Vector& direction, const Vector& origin) {
	Matrix inverse = invert();
	Vector realOrigin = inverse * origin;
	Vector realDirection = inverse & direction;
	return m_delegate().intersect(realDirection, realOrigin);
}

Vector Transform::tangent0(const Vector& uv) {
	return matrix() & m_delegate().tangent0(uv);
}

Vector Transform::tangent1(const Vector& uv) {
	return matrix() & m_delegate().tangent1(uv);
}

Vector Transform::joint(const Vector& uv) {
	return matrix() * m_delegate().joint(uv);
}

DefaultTransform::DefaultTransform(const Matrix& m, GeometryDelegate f):
	Transform(f), m_matrix(m), m_invert(~m) {}
