cmake_minimum_required(VERSION 3.13)
project(mytest)

if (VCG_HEADER_ONLY)
	set(SOURCES
		mesh.h
		main.cpp
		${VCG_INCLUDE_DIRS}/wrap/ply/plylib.cpp)
endif()

add_executable(mytest
	${SOURCES})

target_link_libraries(
	mytest
	PUBLIC
		vcglib
	)
