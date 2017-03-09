#pragma once
#include <string.h>
#include <iostream>
#include <stdexcept>
#include <sstream>

// generate test-case style ctests.
#define EXCEPT(x, y) {\
	std::stringstream msg;\
	msg << "Expected " << x << ", but got " << y << "." << std::endl;\
	throw std::logic_error(msg.str());\
}

#define ASSERT_EQ(x, y) if(x != y) EXCEPT(x, y);
#define ASSERT_NULL(x) if(x) EXCEPT("nullptr", "not null value");
#define ASSERT_TRUE(x) if(!x) EXCEPT("true", "false");
#define ASSERT_FALSE(x) if(x) EXCEPT("false", "true");

#define TEST_CASE(name)\
	if(argv > 1 && strcmp(args[1], #name) == 0) try {\
		name();\
		return 0;\
	}\
	catch(std::logic_error e) {\
		std::cout << e.what() << std::endl;\
		return 1;\
	}
