cmake_minimum_required(VERSION 3.16)
project(Tetris LANGUAGES CXX)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
option(BUILD_SHARED_LIBS "Build shared libraries" ON)

set(SOURCES
    src/Controller/Controller.cpp
    src/Model/AbstractShape.cpp
    src/Model/Map.cpp
    src/Model/Model.cpp
    src/View/View.cpp
    src/View/ViewMap.cpp
    src/Game.cpp
    src/main.cpp
)

include(FetchContent)
FetchContent_Declare(SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 2.6.x)
FetchContent_MakeAvailable(SFML)

add_executable(${PROJECT_NAME} ${SOURCES})

target_include_directories(Tetris PRIVATE
        ${PROJECT_SOURCE_DIR}/inc
        ${PROJECT_SOURCE_DIR}/inc/Controller
        ${PROJECT_SOURCE_DIR}/inc/Model
        ${PROJECT_SOURCE_DIR}/inc/Model/Blocks
        ${PROJECT_SOURCE_DIR}/inc/Model/Factory
        ${PROJECT_SOURCE_DIR}/inc/View
)
target_link_libraries(Tetris PRIVATE sfml-graphics)
target_compile_features(Tetris PRIVATE cxx_std_17)

if(WIN32)
    add_custom_command(
        TARGET Tetris
        COMMENT "Copy OpenAL DLL"
        PRE_BUILD COMMAND ${CMAKE_COMMAND} -E copy ${SFML_SOURCE_DIR}/extlibs/bin/$<IF:$<EQUAL:${CMAKE_SIZEOF_VOID_P},8>,x64,x86>/openal32.dll $<TARGET_FILE_DIR:Tetris>
        VERBATIM)
endif()

install(TARGETS Tetris)