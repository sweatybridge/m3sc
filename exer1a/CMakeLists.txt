add_executable(ex1a-mastery mastery.c)
add_executable(ex1a-quad prog_1.c)
add_executable(ex1a-planet prog_2.c)
add_executable(ex1a-limit prog_3.c)

target_link_libraries(ex1a-mastery -lm)
target_link_libraries(ex1a-quad -lm)
target_link_libraries(ex1a-planet -lm)
target_link_libraries(ex1a-limit -lm)