cmake_minimum_required(VERSION 3.28)
project(brick_breaker)

set(CMAKE_CXX_STANDARD 17)

add_executable(brick_breaker main.cpp
        Paddle.h
        Paddle.cpp
        Ball.h
        Ball.cpp
        Brick.h
        Brick.cpp
        Game.cpp
        Game.h
)

set(SFML_STATIC_LIBRARIES TRUE)
set(SFML_DIR "C:/SFML/lib/cmake/SFML")

find_package(SFML 2.6 COMPONENTS graphics audio window system network REQUIRED)
include_directories(D:/SFML/include)
target_link_libraries(brick_breaker sfml-graphics sfml-audio sfml-window sfml-system sfml-network)