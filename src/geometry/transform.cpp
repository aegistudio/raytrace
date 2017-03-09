#include "geometry/transform.h"

Maybe<Vector> Transform::intersect(const Vector& direction, const Vector& origin) {
    Matrix inverse = invert();
    Vector realOrigin = inverse * origin;
    Vector realBias = (inverse * (direction + origin));
	Vector realDirection = realBias - realOrigin;
	return geometry().intersect(~(realDirection), realOrigin);
}

Vector Transform::tangent0(const Vector& uv) {
	return matrix() * geometry().tangent0(uv);
}

Vector Transform::tangent1(const Vector& uv) {
	return matrix() * geometry().tangent1(uv);
}

Vector Transform::joint(const Vector& uv) {
	return matrix() * geometry().joint(uv);
}

DefaultTransform::DefaultTransform(const Matrix& m, const std::function<Geometry&()> f):
	m_geometry(f), m_matrix(m), m_invert(~m) {}
