cmake_minimum_required(VERSION 2.8)	 

project(HashTable)			

set(SOURCE_EXE main.cpp)		

set(SOURCE_LIB hash.cpp)			

add_library(hash STATIC ${SOURCE_LIB})	

add_executable(main ${SOURCE_EXE})	

target_link_libraries(main hash)		
