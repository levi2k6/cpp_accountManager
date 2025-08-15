cmake_minimum_required(VERSION 3.20)
project(accountManager VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20) 
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

find_package(fmt CONFIG REQUIRED)
find_package(SDL2 CONFIG REQUIRED)
find_package(yaml-cpp CONFIG REQUIRED)

add_executable(${PROJECT_NAME} 
src/main.cpp 
src/utils.cpp 
src/init/WindowDisplay.cpp
src/init/MainLoop.cpp
src/init/Renderer.cpp
src/init/SceneInit.cpp
src/system/InputSystem.cpp
src/system/SceneSystem.cpp
src/system/UISystem.cpp
src/system/UILayoutSystem.cpp
src/scenes/Auth.cpp
src/UI/UI.cpp
src/UI/components/Box.cpp
src/UI/components/Button.cpp

)

target_link_libraries(${PROJECT_NAME} PRIVATE 
    SDL2::SDL2  
    SDL2::SDL2main
    fmt::fmt
    yaml-cpp::yaml-cpp
)

target_include_directories(${PROJECT_NAME} PRIVATE ${PROJECT_SOURCE_DIR}/include)
