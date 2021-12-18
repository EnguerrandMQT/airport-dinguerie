cmake_minimum_required(VERSION 3.20.5)
project(airport)

set(CompilerFlags
        CMAKE_CXX_FLAGS
        CMAKE_CXX_FLAGS_DEBUG
        CMAKE_CXX_FLAGS_RELEASE
        CMAKE_C_FLAGS
        CMAKE_C_FLAGS_DEBUG
        CMAKE_C_FLAGS_RELEASE
        )
# C'est un autre compilateur C
# G++ est une extension de GCC
# Clang c'est une extension du compilateur LLVM KLANG Qlang

if(MSVC)
    add_compile_options(
        $<$<CONFIG:>:/MT> #---------|
        $<$<CONFIG:Debug>:/MTd> #---|-- Statically link the runtime libraries
        $<$<CONFIG:Release>:/MT> #--|
    )
    set(SFML_STATIC_LIBRARIES TRUE)
    set(SFML_DIR "C:/SFML-2.5.1_windows_VS15.6_static/lib/cmake/SFML")
endif()

SET(CMAKE_CONFIGURATION_TYPES "Debug;Release" CACHE STRING "Configs" FORCE)

find_package(SFML 2.5 COMPONENTS graphics window system REQUIRED)
find_package(Threads)
include_directories(headers)

file(GLOB SOURCES "src/*.cpp")

add_executable(airport ${SOURCES})

target_compile_features(airport PUBLIC cxx_std_17)
target_link_libraries(airport sfml-graphics sfml-window Threads::Threads)