cmake_minimum_required(VERSION 3.16)

project(Parsec)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED true)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)

include_directories(include)

aux_source_directory(src LibrarySource)
add_library(Parsec SHARED ${LibrarySource})

aux_source_directory(examples ExampleSource)
foreach(Src ${ExampleSource})
  string(REGEX MATCH "^.*/(.*)\.cpp$" TargetName ${Src})
  add_executable(${CMAKE_MATCH_1} ${Src})
  target_link_libraries(${CMAKE_MATCH_1} Parsec)
endforeach(Src ${ExampleSource})
