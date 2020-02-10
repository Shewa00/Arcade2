cmake_minimum_required(VERSION 3.0)
project(traffic)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

option(BUILD_TESTS Off)

project(Kursach)

find_package(
  Qt5
  HINTS "$ENV{QTDIR}"
  REQUIRED COMPONENTS
  Core
  Widgets
  Test
)

set(
  ${PROJECT_NAME}_INCLUDE     
        Sources/bullet.h 
        Sources/enemy.h 
        Sources/game.h       
        Sources/health.h 
        Sources/mainwindow.h 
        Sources/player.h 
        Sources/score.h 
        Sources/test_player.h
)
set(
  ${PROJECT_NAME}_SOURCE
  Sources/bullet.cpp 
  Sources/enemy.cpp 
  Sources/game.cpp 
  Sources/health.cpp 
  Sources/main.cpp 
  Sources/mainwindow.cpp 
  Sources/player.cpp 
  Sources/score.cpp 
  Sources/test_player.cpp
)
set(
  ${PROJECT_NAME}_UI
  Sources/mainwindow.ui
)
set(
  ${PROJECT_NAME}_RESOURCE
  resources/resource.qrc
)

set(GUI_TYPE)
if (WIN32)
  set(GUI_TYPE WIN32)
endif ()

# Core

add_library(
  ${PROJECT_NAME}Core
  ${${PROJECT_NAME}_SOURCE}
)

target_link_libraries(${PROJECT_NAME}Core PUBLIC
  Qt5::Core
  Qt5::Widgets
  )

# Demo

add_executable(
  ${PROJECT_NAME}
  ${GUI_TYPE}

  Sources/main.cpp
  Sources/mainwindow.cpp

  ${${PROJECT_NAME}_INCLUDE}
  ${${PROJECT_NAME}_UI}
  ${${PROJECT_NAME}_RESOURCE}
)

target_include_directories(
  ${PROJECT_NAME} PUBLIC
  ${CMAKE_CURRENT_SOURCE_DIR}/Sources
  ${CMAKE_CURRENT_SOURCE_DIR}
)

include_directories(Sources)

set_target_properties(${PROJECT_NAME} PROPERTIES AUTOMOC TRUE)
set_target_properties(${PROJECT_NAME} PROPERTIES AUTOUIC TRUE)
set_target_properties(${PROJECT_NAME} PROPERTIES AUTORCC TRUE)

target_link_libraries(${PROJECT_NAME} PUBLIC
  ${PROJECT_NAME}Core
  )

# Tests
if (BUILD_TESTS)

  add_executable(tests
    tests/tests.cpp Sources/MainWindow.cpp

    ${${PROJECT_NAME}_INCLUDE}
    ${${PROJECT_NAME}_UI}
    ${${PROJECT_NAME}_RESOURCE}
    )
  add_test(tests tests)

  set_target_properties(tests PROPERTIES AUTOMOC TRUE)
  set_target_properties(tests PROPERTIES AUTOUIC TRUE)
  set_target_properties(tests PROPERTIES AUTORCC TRUE)

  target_link_libraries(tests PUBLIC Qt5::Test ${PROJECT_NAME}Core)

endif ()
