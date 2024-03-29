cmake_minimum_required(VERSION 3.16)
project(Tetris LANGUAGES CXX)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
option(BUILD_SHARED_LIBS "Build shared libraries" OFF)

include(FetchContent)
FetchContent_Declare(SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 2.6.x)
FetchContent_MakeAvailable(SFML)

file(GLOB_RECURSE _source_list
       ${PROJECT_SOURCE_DIR}/src/*.cpp
       ${PROJECT_SOURCE_DIR}/inc/*.h)

add_executable(${PROJECT_NAME} ${_source_list})

target_include_directories(Tetris PRIVATE
        ${PROJECT_SOURCE_DIR}/inc
)

target_link_libraries(Tetris PRIVATE sfml-graphics)
target_compile_features(Tetris PRIVATE cxx_std_20)


if(WIN32)
    add_custom_command(
        TARGET Tetris
        COMMENT "Copy OpenAL DLL"
        PRE_BUILD COMMAND ${CMAKE_COMMAND} -E copy ${SFML_SOURCE_DIR}/extlibs/bin/$<IF:$<EQUAL:${CMAKE_SIZEOF_VOID_P},8>,x64,x86>/openal32.dll $<TARGET_FILE_DIR:Tetris>
        VERBATIM)
endif()

install(TARGETS Tetris
        CONFIGURATIONS Debug
        RUNTIME
          DESTINATION ${PROJECT_SOURCE_DIR}/bin/Debug
        )
install(TARGETS Tetris
        CONFIGURATIONS Release
        RUNTIME
          DESTINATION ${PROJECT_SOURCE_DIR}/bin/Release
        )