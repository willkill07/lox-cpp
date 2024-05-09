cmake_minimum_required(VERSION 3.26 FATAL_ERROR)
project(Lox)
enable_language(CXX)

set(CMAKE_BUILD_TYPE RelWithDebInfo)

include(cmake/CPM.cmake)

cpmaddpackage("gh:fmtlib/fmt#10.2.1")
cpmaddpackage("gh:TartanLlama/expected#v1.1.0")
cpmaddpackage("gh:TartanLlama/optional#v1.1.0")
cpmaddpackage("gh:CLIUtils/CLI11#v2.4.1")

function(configure_target name)
  set_target_properties(
    ${name}
    PROPERTIES CXX_STANDARD 20
               CXX_STANDARD_REQUIRED On
               CXX_EXTENSIONS Off)
endfunction()

add_executable(lox)
configure_target(lox)

add_subdirectory(src)
