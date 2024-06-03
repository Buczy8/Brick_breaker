cmake_minimum_required(VERSION 3.28)
project(brick_breaker)

set(CMAKE_CXX_STANDARD 26)

add_executable(brick_breaker
        main.cpp
        Paddle.h
        Paddle.cpp
        Ball.h
        Ball.cpp
        Game.cpp
        Game.h
        GameState.h
)

set(SFML_STATIC_LIBRARIES TRUE)
set(SFML_DIR "C:/SFML/lib/cmake/SFML")

find_package(SFML 2.6 COMPONENTS graphics audio window system network REQUIRED)


target_link_libraries(brick_breaker sfml-graphics sfml-audio sfml-window sfml-system)

include_directories("C:/SFML/include")
link_directories("C:/SFML/lib")

target_link_libraries(brick_breaker ${CMAKE_SOURCE_DIR}/cmake-build-debug/libcom.dll)