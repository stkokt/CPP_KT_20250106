cmake_minimum_required(VERSION 3.16)

project(Personen LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(Personen main.cpp
    personen.h personen.cpp
    location.h location.cpp
)

include(GNUInstallDirs)
install(TARGETS Personen
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
