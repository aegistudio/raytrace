#pragma once
#include <string.h>
#include <iostream>
#include <stdexcept>
#include <sstream>

// generate test-case style ctests.
#define ASSERT_EQ(x, y) if(x != y) {\
	std::stringstream msg;\
	msg << "Expected " << x << ", but got " << y << std::endl;\
	throw std::logic_error(msg.str());\
}

#define ASSERT_NULL(x) if(x) {\
	std::stringstream msg;\
	msg << "Expected nullptr, but got not null value." << std::endl;\
	throw std::logic_error(msg.str());\
}

#define TEST_CASE(name)\
	if(argv > 1 && strcmp(args[1], #name) == 0) try {\
		name();\
		return 0;\
	}\
	catch(std::logic_error e) {\
		std::cout << e.what() << std::endl;\
		return 1;\
	}
