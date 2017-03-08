add_library(geometry SHARED 
	vector.cpp matrix.cpp transform.cpp)
install(TARGETS geometry DESTINATION bin)
