add_executable(ex1b-quad prog_1.c quad.c lin.c)
add_executable(ex1b-cubic prog_2.c)
add_executable(ex1b-gas prog_4.c)
add_executable(ex1b-time prog_5.c)
add_executable(ex1b-mastery mastery.c)

add_library(ex1b-lib cubic.c quad.c lin.c)
target_link_libraries(ex1b-lib -lm)

target_link_libraries(ex1b-cubic ex1b-lib)
target_link_libraries(ex1b-gas ex1b-lib)
target_link_libraries(ex1b-mastery -lm)
target_link_libraries(ex1b-quad -lm)