add_library(geometry SHARED vector.cpp matrix.cpp)
install(TARGETS geometry DESTINATION bin)
