cmake_minimum_required(VERSION 3.2)
project(m3sc)

add_compile_options(-std=gnu89)
add_compile_options(-Wall)
add_compile_options(-Werror)
add_compile_options(-Wextra)
add_compile_options(-Wmissing-declarations)

IF (CMAKE_COMPILER_IS_GNUCXX)
  set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -pthread")
ENDIF()

set(CMAKE_C_FLAGS_RELEASE "-O3")
set(CMAKE_C_FLAGS_DEBUG "-g3")

add_subdirectory(exer0)
add_subdirectory(exer1a)
add_subdirectory(exer1b)
add_subdirectory(exer1c)
add_subdirectory(exer2)
add_subdirectory(tests)
