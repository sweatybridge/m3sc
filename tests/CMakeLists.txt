add_compile_options(-std=c++1y)

add_definitions(-DGTEST_HAS_TR1_TUPLE=0)

enable_testing()

find_package(GTest REQUIRED)

include_directories(${GTEST_INCLUDE_DIRS})

add_executable(tests-1b main.cc cubic.cc quadratic.cc)
add_executable(tests-cubic main.cc array_cubic.cc array_quad.cc)
add_executable(tests-quartic main.cc quartic.cc)

target_link_libraries(tests-1b ex1b-lib ${GTEST_LIBRARIES})
target_link_libraries(tests-cubic ex1c-lib ${GTEST_LIBRARIES})
target_link_libraries(tests-quartic ex1c-lib ${GTEST_LIBRARIES})

add_test(UnitTests tests-1b tests-cubic tests-quartic)