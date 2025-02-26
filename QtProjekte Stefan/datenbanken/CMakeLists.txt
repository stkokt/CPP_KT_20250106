cmake_minimum_required(VERSION 3.10)
project(datenbanken)

# Setze den C++-Standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Pfad zu den SQLite Quelldateien und Headern
set(SQLITE3_INCLUDE_DIR "C:/SQLite")
set(SQLITE3_SOURCES
    "C:/SQLite/sqlite3.c"
)

# Erstelle dein ausführbares Programm
add_executable(dbs main.cpp ${SQLITE3_SOURCES})

# Füge das Verzeichnis hinzu, in dem sich die Header-Dateien von SQLite befinden
target_include_directories(dbs PRIVATE ${SQLITE3_INCLUDE_DIR})
