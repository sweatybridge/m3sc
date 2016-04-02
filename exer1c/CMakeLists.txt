add_executable(ex1c-array prog_1.c)
add_executable(ex1c-quartic prog_2.c)
add_executable(ex1c-ellipse prog_3.c)
add_executable(ex1c-mastery mastery.c)

add_library(ex1c-lib array.c quartic.c)
target_link_libraries(ex1c-lib -lm)

target_link_libraries(ex1c-array ex1c-lib)
target_link_libraries(ex1c-quartic ex1c-lib)
target_link_libraries(ex1c-ellipse ex1c-lib)
target_link_libraries(ex1c-mastery ex1c-lib)