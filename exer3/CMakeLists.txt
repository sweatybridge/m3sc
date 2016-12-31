add_executable(ex3-sfactors prog_1.c factors.c)
add_executable(ex3-timing prog_4.c)
add_executable(ex3-poisson prog_5.c)
add_executable(ex3-dst mastery.c)

add_library(ex3-lib dst.c factors.c)
target_link_libraries(ex3-lib -lm)

target_link_libraries(ex3-timing ex3-lib)
target_link_libraries(ex3-poisson ex3-lib)
target_link_libraries(ex3-dst ex3-lib)
