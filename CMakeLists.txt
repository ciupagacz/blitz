# This file is provided as an compiling example
# Modify and distribute it however you want!!

cmake_minimum_required(VERSION 3.5)

if(POLICY CMP0069)
	cmake_policy(SET CMP0069 NEW)
endif()
if(POLICY CMP0072)
    cmake_policy(SET CMP0072 NEW)
endif()

project(blitz LANGUAGES C)

add_library(blitz STATIC "src/main.c")

set_target_properties(
	blitz PROPERTIES

	C_STANDARD 23
	C_STANDARD_REQUIRED YES
)

target_include_directories(blitz PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

target_compile_options(blitz PRIVATE -O3 -Wall -Werror)

set_property(TARGET blitz PROPERTY INTERPROCEDURAL_OPTIMIZATION TRUE)
