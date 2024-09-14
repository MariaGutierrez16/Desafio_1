cmake_minimum_required(VERSION 3.16)

project(Codigo_Desafio1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(Codigo_Desafio1 main.cpp)

include(GNUInstallDirs)
install(TARGETS Codigo_Desafio1
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
