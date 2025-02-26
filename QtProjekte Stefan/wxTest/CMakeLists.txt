cmake_minimum_required(VERSION 3.29)

project(wxwidgets)

set(wxWidgets_ROOT_DIR "C:/WX")
find_package(wxWidgets COMPONENTS gl core base OPTIONAL_COMPONENTS net)
set(SOURCES main.cpp)
add_executable(wxwidgets ${SOURCES})
if (wxWidgets_FOUND)
include(${wxWidgets_USE_FILE})
target_link_libraries(wxwidgets ${wxWidgets_LIBRARIES})
endif()
