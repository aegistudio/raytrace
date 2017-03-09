add_library(geometry SHARED 
	vector.cpp matrix.cpp transform.cpp plane.cpp)
install(TARGETS geometry DESTINATION bin)
