cmake_minimum_required(VERSION 3.29)
project(Xypher)

set(CMAKE_CXX_STANDARD 20)

add_executable(Xypher main.cpp
        src/Button/Button.cpp
        src/Entities/Entity.cpp
        src/Game/Game.cpp
        src/States/State.cpp
        src/States/MainMenuState.cpp
        src/States/GameState.cpp)

set(SFML_STATIC_LIBRARIES TRUE)
set(SFML_DIR C:/SFML/lib/cmake/SFML)
find_package(SFML COMPONENTS system window graphics audio network REQUIRED)

include_directories(C:/Users/tobis/Schule_ohne_OneDrive/Xypher/sfml/include/SFML)
target_link_libraries(Xypher sfml-system sfml-window sfml-graphics sfml-audio sfml-network)
