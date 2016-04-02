add_executable(ex2-gauss prog_1.c solve_linear.c)
add_executable(ex2-bgauss prog_3.c solve_linear.c)
add_executable(ex2-poisson-1d prog_5.c solve_linear.c)
add_executable(ex2-poisson-2d prog_6.c solve_linear.c)
add_executable(ex2-poisson-3d mastery.c solve_linear.c)

add_definitions(-DINSTRUMENT)
