cmake_minimum_required(VERSION 3.3)
project(m3sc)

add_compile_options(-std=gnu89)
add_compile_options(-Wall)
add_compile_options(-Werror)
add_compile_options(-Wextra)
add_compile_options(-Wmissing-declarations)

add_subdirectory(exer0)
add_subdirectory(exer1a)
add_subdirectory(exer1b)
add_subdirectory(exer1c)
add_subdirectory(tests)