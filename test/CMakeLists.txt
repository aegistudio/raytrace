add_subdirectory(geometry testbin)
#add_subdirectory(raytrace)

include(TestCase)

add_executable(maybeTest maybeTest.cpp)
add_testcase(maybeTest testNothing)
add_testcase(maybeTest testJust)
add_testcase(maybeTest testFromFunction)
add_testcase(maybeTest testCascade)
