cmake_minimum_required(VERSION 3.22)
project(grade_manager)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)


find_package(Qt6 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED
        Sql)

add_executable(grade_manager
        src/main.cpp
        src/GradeManager.cpp src/GradeManager.h
        src/ui/Login.cpp src/ui/Login.h src/ui/Login.ui)
target_link_libraries(grade_manager
        Qt::Core
        Qt::Gui
        Qt::Widgets
        Qt::Sql
        )

