// This class test for the functionality of matrix class under the geometry package.
#include "common.h"
#include "geometry/matrix.h"
#include <iostream>
#include <string.h>
#include <string>
#include <stdlib.h>
#include <sstream>

#include <functional>
#include <vector>

typedef std::function<bool(std::string, std::string)> consumer;

consumer vectorCommand(std::string opcode, std::string format,
		std::function<void(const Vector&)> consume) {
	return [=] (std::string input, std::string operand) {
		if(opcode == input) {
			Vector value = vectorize(operand.c_str());
			std::stringstream strcontainer;
			strcontainer << value;
			printf(format.c_str(), strcontainer.str().c_str());
			printf("\n");
			consume(value);
			return true;
		}
		return false;
	};
}

consumer valueCommand(std::string opcode, std::string format,
		std::function<void(double)> consume) {
	return [=] (std::string input, std::string operand){
		if(opcode == input) {
			double value = atof(operand.c_str());
			printf(format.c_str(), value);
			printf("\n");
			consume(value);
			return true;
		}
		return false;
	};
}

#define _VECL(vn, exp) [&](const Vector& vn) { matrix = (exp); }
#define _VALL(vn, exp) [&](double vn) { matrix = (exp); }

int main(int args, char** argv) {
	Matrix matrix = Matrix::identity();
    std::vector<consumer> appliables;

    // Load identity command.
    appliables.push_back(valueCommand(
		"identity", "Load identity.",
		_VALL(vec, Matrix::identity())
	));

	// Translate command.
	appliables.push_back(vectorCommand(
		"translate", "Translation by %s.",
		_VECL(bias, Matrix::translate(bias) * matrix)
	));

	// Scale commands.
    appliables.push_back(valueCommand(
		"scalef", "Scale by %lf.",
		_VALL(scale, Matrix::scale(scale) * matrix)
	));
    appliables.push_back(vectorCommand(
		"scalev", "Scale by %s.",
		_VECL(scale, Matrix::scale(scale) * matrix)
	));

	// Invert matrix.
	appliables.push_back(valueCommand(
		"invert", "Invert matrix.",
		_VALL(scale, matrix.invert())
	));

	// Rotations.
	appliables.push_back(valueCommand(
		"xRotate", "Rotate around x by %ld.",
		_VALL(x, Matrix::xRotate(x) * matrix)
	));

	appliables.push_back(valueCommand(
		"yRotate", "Rotate around y by %ld.",
		_VALL(y, Matrix::xRotate(y) * matrix)
	));

	appliables.push_back(valueCommand(
		"zRotate", "Rotate around x by %ld.",
		_VALL(z, Matrix::xRotate(z) * matrix)
	));

    for(int i = 1; i < args - 2; i += 2) {
        char* command = argv[i + 0];
        char* operand = argv[i + 1];

		std::vector<consumer>::iterator iter;
		bool matches = false;
        for(iter = appliables.begin(); iter != appliables.end(); iter ++) {
			matches = (*iter)(command, operand);
			if(matches) break;
        }

		if(!matches) {
			std::cout << "Invalid opcode " << command << "." << std::endl;
			return 2;
        }
    }

	Vector input = vectorize(argv[args - 2]);
	Vector output = vectorize(argv[args - 1]);
	std::cout << "The transformation matrix will be " << matrix << std::endl;
    return expect(output, matrix * input)? 0 : 1;
}
