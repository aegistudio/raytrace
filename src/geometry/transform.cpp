#include "geometry/transform.h"

Maybe<Vector> Transform::intersect(const Vector& direction, const Vector& origin) {
	return geometry().intersect(~(invertRemain() * direction), invertMatrix() * origin);
}

Vector Transform::normal(const Vector& uv) {
	return remain() * geometry().normal(uv);
}

Vector Transform::joint(const Vector& uv) {
	return matrix() * geometry().joint(uv);
}

DefaultTransform::DefaultTransform(const Matrix& m, const std::function<Geometry&()> f): 
	m_geometry(f), m_matrix(m), m_remain(m), 
	m_invertRemain(m.invert()), m_invertMatrix(m.invert()) {

	for(int i = 0; i < 3; i ++)
		m_remain.m[i][3] = m_remain.m[3][i]
			= m_invertRemain.m[i][3]
			= m_invertRemain.m[3][i] = 0;
}
