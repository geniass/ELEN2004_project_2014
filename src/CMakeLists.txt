add_library(src DataPoint.cpp)
add_executable(elen2004_2014 main.cpp)
target_link_libraries(elen2004_2014 src)
