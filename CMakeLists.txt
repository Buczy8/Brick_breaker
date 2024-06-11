cmake_minimum_required(VERSION 3.28)
project(brick_breaker)

set(CMAKE_CXX_STANDARD 26)

add_executable(brick_breaker
        main.cpp
        Paddle.h
        Paddle.cpp
        Game.cpp
        Game.h
        GameState.h
        Brick.cpp
        Brick.h
        GameEngine.cpp
        GameEngine.h
        Ball.cpp
        Ball.h
)

set(SFML_STATIC_LIBRARIES TRUE)
set(SFML_DIR ${CMAKE_SOURCE_DIR}/SFML/lib/cmake/SFML)

find_package(SFML 2.6 COMPONENTS graphics audio window system network REQUIRED)


target_link_libraries(brick_breaker sfml-graphics sfml-audio sfml-window sfml-system)

include_directories(${CMAKE_SOURCE_DIR}/SFML/include)
link_directories(${CMAKE_SOURCE_DIR}/SFML/lib)

target_link_libraries(brick_breaker ${CMAKE_SOURCE_DIR}/cmake-build-debug/libScoreTracker.dll)
