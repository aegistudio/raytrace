// This class test for the functionality of vector class under the geometry package.
#include "common.h"
#include <iostream>
#include <functional>

// <cmd> <Vector0> <Op> <Result>
std::function<bool(char**)> unaryValue(std::function<double(Vector&)> _) {
	return [&] (char** argv) {
		Vector v0 = vectorize(argv[1]);
		return expect(atof(argv[3]), _(v0));
	};
}

// <cmd> <Vector0> <Op> <Result>
std::function<bool(char**)> unaryVector(std::function<Vector (Vector&)> _) {
	return [&] (char** argv) {
		Vector v0 = vectorize(argv[1]);
		return expect(vectorize(argv[3]), _(v0));
	};
}

std::function<bool(char**)> binaryValue(std::function<double (Vector&, Vector&)> _) {
	return [&] (char** argv) {
		Vector v0 = vectorize(argv[1]);
		Vector v1 = vectorize(argv[3]);
		return expect(atof(argv[4]), _(v0, v1));
	};
}

std::function<bool(char**)> binaryVector(std::function<Vector (Vector&, Vector&)> _) {
	return [&] (char** argv) {
		Vector v0 = vectorize(argv[1]);
		Vector v1 = vectorize(argv[3]);
		return expect(vectorize(argv[4]), _(v0, v1));
	};
}

#define _VECL(vec, operation) [&](Vector& vec) { return (operation); }
#define _VECL2(vec1, vec2, operation)\
	[&](Vector& vec1, Vector& vec2) {return (operation); }

// Parameter1: the left operand, vector0.
// Parameter2: the operation to perform. should be a char.
// Parameter3: for unary operation, should be the result.
//		for binary operation, should be another vector1.
// Parameter4: for binary operation, should be the result.

int main(int args, char** argv) {
	// Initialize optables.
	std::function<bool(char**)> optables[256];
	for(int i = 0; i < 256; i ++) optables[i] = [] (char** param) {
		std::cout << "Undefined operation" << std::endl;
		return false;
	};

	optables['!'] = unaryValue(_VECL(vec, !vec));
	optables['~'] = unaryVector(_VECL(vec, ~vec));

	optables['^'] = binaryValue(_VECL2(a, b, a ^ b));
	optables['&'] = binaryValue(_VECL2(a, b, a & b));
	optables['+'] = binaryVector(_VECL2(a, b, a + b));
	optables['-'] = binaryVector(_VECL2(a, b, a - b));
	optables['*'] = binaryVector(_VECL2(a, b, a * b));
	optables['|'] = binaryVector(_VECL2(a, b, a | b));

	// Parse optable.
	char op = argv[2][0];
	return optables[op](argv)? 0 : 1;
}
