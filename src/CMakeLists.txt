add_library(src DataPoint.cpp)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "../bin")
add_executable(elen2004_2014 main.cpp)
target_link_libraries(elen2004_2014 src)
