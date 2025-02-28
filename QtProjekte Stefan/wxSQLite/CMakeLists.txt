cmake_minimum_required(VERSION 3.29)

project(wxSQLite)

set(wxWidgets_ROOT_DIR "C:/WX1")
set(SQLITE3_INCLUDE_DIR "C:/SQLite")
set(SQLITE3_SOURCES
    "C:/SQLite/sqlite3.c"
)
find_package(wxWidgets COMPONENTS gl core base OPTIONAL_COMPONENTS net)
set(SOURCES main.cpp)
add_executable(wxSQLite ${SOURCES} ${SQLITE3_SOURCES})
#if (wxWidgets_FOUND)
include(${wxWidgets_USE_FILE})
target_link_libraries(wxSQLite ${wxWidgets_LIBRARIES})
target_include_directories(wxSQLite PRIVATE ${SQLITE3_INCLUDE_DIR})
#endif()
