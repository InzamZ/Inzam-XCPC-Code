cmake_minimum_required(VERSION 3.23)
project(Inzam_XCPC_Code)

set(CMAKE_CXX_STANDARD 14)

file (GLOB_RECURSE files *.cpp)
foreach (file ${files})
    string(REGEX REPLACE ".+/(.+)/(.+)/(.+)\\..*" "\\1-\\2-\\3" exe ${file})
    add_executable (${exe} ${file})
    message (\ \ \ \ --\ src/${exe}.cpp\ will\ be\ compiled\ to\ bin/${exe})
endforeach ()