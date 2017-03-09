include(CTest)
include(../TestCase)
enable_testing()

# Define some constants.
set(PI     "3.141592653589")
set(PI_2   "1.57079632679")
set(PI_3   "1.0471975512")
set(PI_4   "0.78539816339")
set(SQR3_2 "0.86602540378")

# Build test driver vectorTest.
add_executable(vectorTest common.cpp vectorTest.cpp)
target_link_libraries(vectorTest geometry)

# Add the tests for vector.
macro(vector_test TNAME TPARAM0 TPARAM1 TPARAM2 TPARAM3)
	add_test(geometry.vectorTest.${TNAME} vectorTest 
		${TPARAM0} ${TPARAM1} ${TPARAM2} ${TPARAM3})
endmacro()

vector_test(span1     "(1,0,0)" "^" "(1,0,0)" "0")
vector_test(span2     "(1,0,0)" "^" "(-1,0,0)" ${PI})
vector_test(span3     "(1,0,0)" "^" "(0,1,0)" ${PI_2})
vector_test(plus      "(2,3,4)" "+" "(5,6,7)" "(7,9,11)")
vector_test(subtract  "(2,3,4)" "-" "(5,6,7)" "(-3,-3,-3)")
vector_test(project   "(2,3,4)" "|" "(0,1,0)" "(0,3,0)")
vector_test(dot       "(3,4,0)" "&" "(3,4,0)" "25")
vector_test(modulus   "(3,4,0)" "!" "5" "")
vector_test(cross     "(2,0,0)" "*" "(0,3,0)" "(0,0,6)")
vector_test(direction "(3,4,12)" "~" "(0.23076923076,0.30769230769,0.92307692307)" "")

# Build test driver matrixTest.
add_executable(matrixTest common.cpp matrixTest.cpp)
target_link_libraries(matrixTest geometry)

# Add the tests for matrix
add_test(geometry.matrixTest.invariant matrixTest
	"identity" "" "(1,3,5)" "(1,3,5)")
add_test(geometry.matrixTest.scale0 matrixTest
	"scalef" "2" "(1,3,5)" "(2,6,10)")
add_test(geometry.matrixTest.scale1 matrixTest
	"scalef" "2" "invert" "" "(2,6,10)" "(1,3,5)")
add_test(geometry.matrixTest.translate0 matrixTest
	"translate" "(1,-1,1)" "(4,4,4)" "(5,3,5)")
add_test(geometry.matrixTest.translate1 matrixTest
	"translate" "(1,-1,1)" "translate" "(-1,1,-1)" "(4,4,4)" "(4,4,4)")
add_test(geometry.matrixTest.rotate0 matrixTest
	"xRotate" ${PI_3} "(0,1,0)" "(0,0.5,${SQR3_2})")

# Build test driver planeTest.
add_executable(planeTest common.cpp planeTest.cpp geomtest.cpp)
target_link_libraries(planeTest geometry)

# Add the tests for plane.
add_testcasep(geometry planeTest testNormal)
add_testcasep(geometry planeTest testTransform)
