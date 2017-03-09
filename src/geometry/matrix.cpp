#include "geometry/matrix.h"
#include "math.h"

Matrix::Matrix(const double _[4][4]) {
	for(int i = 0; i < 4; i ++)
		for(int j = 0; j < 4; j ++)
			m[i][j] = _[i][j];
}

static int matrixBias[4][4] = {
	{1, 2, 3},	// Remove 0 from the rotation.
	{0, 2, 3},	// Remove 1 from the rotation.
	{0, 1, 3},	// Remove 2 from the rotation.
	{0, 1, 2},	// Remove 3 from the rotation
};

double Matrix::determinant3(int dx, int dy) const {
	// Initialize the pick-up.
	int* ip = matrixBias[dx];
	int* jp = matrixBias[dy];

	// Perform the calculation and return the value.
	#pragma push(_M)
	#pragma push(_MX)
	#define _M(i, j) m[ip[i]][jp[j]]
	#define _MX(i, j, k) _M(0, i)\
		* (_M(1, j) * _M(2, k) - _M(1, k) * _M(2, j))

	return _MX(0, 1, 2) + _MX(1, 2, 0) + _MX(2, 0, 1);
	#pragma pop(_MX)
	#pragma pop(_M)
}

double Matrix::determinant() const {
	#pragma push(_DM)
	#define _DM(x)\
		m[0][x] * determinant3(0, x)
	return _DM(0) - _DM(1) + _DM(2) - _DM(3);
	#pragma pop(_DM)
}

Matrix Matrix::invert() const {
	double dall = determinant();
	double result[4][4];
	for(int i = 0; i < 4; i ++)
		for(int j = 0; j < 4; j ++) {
			int sign = ((i + j) % 2)? -1 : 1;
			result[j][i] = sign * determinant3(i, j) / dall;
		}
	return Matrix(result);
}

Vector Matrix::apply(const Vector& _) const {
	#pragma push(_V)
	#define _V(x) (Vector(m[x][0], m[x][1], m[x][2]))
	double qv$t = (_V(3) & _) + m[3][3];
	double res0 = (_V(0) & _) + m[0][3];
	double res1 = (_V(1) & _) + m[1][3];
	double res2 = (_V(2) & _) + m[2][3];
	return Vector(res0, res1, res2) / qv$t;
	#pragma pop(_V)
}

Matrix Matrix::multiply(const Matrix& _) const {
	double result[4][4];
	for(int i = 0; i < 4; i ++)
		for(int j = 0; j < 4; j ++) {
			result[i][j] = 0;
			for(int k = 0; k < 4; k ++)
				result[i][j] += m[i][k] * _.m[k][j];
	}
	return Matrix(result);
}

Matrix Matrix::identity() {
	double id[4][4] = {
		{1, 0, 0, 0},
		{0, 1, 0, 0},
		{0, 0, 1, 0},
		{0, 0, 0, 1}
	};
	return Matrix(id);
}

Matrix Matrix::translate(const Vector& _) {
	Matrix result = identity();
	result.m[0][3] = _.x;
	result.m[1][3] = _.y;
	result.m[2][3] = _.z;
	return result;
}

Matrix Matrix::scale(double f) {
	Matrix result = identity();
	result.m[3][3] = 1./f;
	return result;
}

Matrix Matrix::scale(const Vector& _) {
	Matrix result = identity();
	result.m[0][0] = _.x;
	result.m[1][1] = _.y;
	result.m[2][2] = _.z;
	return result;
}

Matrix Matrix::xRotate(double _) {
	double result[4][4] = {
		{1, 0,	   0,	   0},
		{0, +cos(_), -sin(_), 0},
		{0, +sin(_), +cos(_), 0},
		{0, 0,	   0,	   1},
	};
	return Matrix(result);
}

Matrix Matrix::zRotate(double _) {
	double result[4][4] = {
		{+cos(_), -sin(_), 0, 0},
		{+sin(_), +cos(_), 0, 0},
		{0,	   0,	   1, 0},
		{0,	   0,	   0, 1},
	};
	return Matrix(result);
}

Matrix Matrix::yRotate(double _) {
	double result[4][4] = {
		{+cos(_), 0, +sin(_), 0},
		{0,	   1, 0,	   0},
		{-sin(_), 0, +cos(_), 0},
		{0,	   0,	   0, 1},
	};
	return Matrix(result);
}

Matrix Matrix::rebase(const Vector& x, const Vector& y, const Vector& z) {
    double result[4][4] = {
		{x.x, x.y, x.z, 0},
		{y.x, y.y, y.z, 0},
		{z.x, z.y, z.z, 0},
		{0,   0,   0,   1}
    };
    return Matrix(result).invert();
}
