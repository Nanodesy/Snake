cmake_minimum_required(VERSION 3.28)

project(
	Snake 
	VERSION 1.0.0
	DESCRIPTION "A classic Snake game"
	LANGUAGES CXX
)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
option(BUILD_SHARED_LIBS "Build shared libraries" OFF)

include(FetchContent)
FetchContent_Declare(SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 2.6.1)
FetchContent_MakeAvailable(SFML)

add_executable(${PROJECT_NAME} 
	${PROJECT_SOURCE_DIR}/src/Snake/main.cpp
	${PROJECT_SOURCE_DIR}/src/Snake/Apple.cpp
	${PROJECT_SOURCE_DIR}/src/Snake/Game.cpp
	${PROJECT_SOURCE_DIR}/src/Snake/PlayerInput.cpp
	${PROJECT_SOURCE_DIR}/src/Snake/Sidebar.cpp
	${PROJECT_SOURCE_DIR}/src/Snake/Snake.cpp
	${PROJECT_SOURCE_DIR}/src/Snake/Statistic.cpp
	${PROJECT_SOURCE_DIR}/src/Snake/Timer.cpp
)

target_link_libraries(${PROJECT_NAME}  PRIVATE sfml-graphics)
target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_17)

target_include_directories(${PROJECT_NAME}
	PRIVATE 
		${PROJECT_SOURCE_DIR}/include/Snake
)

if(WIN32)
    add_custom_command(
        TARGET CMakeSFMLProject
        COMMENT "Copy OpenAL DLL"
        PRE_BUILD COMMAND ${CMAKE_COMMAND} -E copy ${SFML_SOURCE_DIR}/extlibs/bin/$<IF:$<EQUAL:${CMAKE_SIZEOF_VOID_P},8>,x64,x86>/openal32.dll $<TARGET_FILE_DIR:CMakeSFMLProject>
        VERBATIM)
endif()

install(TARGETS ${PROJECT_NAME})

