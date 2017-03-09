#include "maybe.h"
#include "testing.h"

Maybe<std::string> stubFunction(std::string expect) {
	return Maybe<std::string>(expect);
}

Maybe<std::string> cascadeFunction(std::string expect, int layer) {
	if(layer > 0) return cascadeFunction(expect, layer - 1);
	else return stubFunction(expect);
}

void testJust() {
	Maybe<std::string> test1("123");
	ASSERT_EQ(*test1, "123");
}

void testNothing() {
	Maybe<std::string> test2;
	ASSERT_TRUE(!test2);
}

void testFromFunction() {
	Maybe<std::string> test3 = stubFunction("456");
	ASSERT_EQ(*test3, "456");
}

void testCascade() {
	Maybe<std::string> test4 = cascadeFunction("789", 200);
	ASSERT_EQ(*test4, "789");
}

int main(int argv, char** args) {
	TEST_CASE(testJust);
	TEST_CASE(testNothing);
	TEST_CASE(testFromFunction);
	TEST_CASE(testCascade);
	return 2;
}
