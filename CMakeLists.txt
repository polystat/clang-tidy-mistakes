# ===========================================================================
# CMAKE: clang-tidy-mistakes
# ===========================================================================
# DESCRIPTION:
#   Example repository with C++ mistakes that can be found with clang-tidy.
#   CMake builds the "$BUILD_DIR/compile_commands-json" (compile-database).
#   This simplifies to explore clang-tidy and clang-tidy runners/wrappers.
#
# EXAMPLE:
#   # -- STEP: Use CMake to build: $BUILD_DIR/compile_commands.json
#   # NEEDS: CMAKE_EXPORT_COMPILE_COMMANDS=ON
#   BUILD_DIR=build
#   cmake -S . -B $BUILD_DIR -G Ninja
#   cmake --build $BUILD_DIR
#   # -- POSTCONDITION: "$BUILD_DIR/compile_commands.json" exists
#
#   # -- STEP: Use "$BUILD_DIR/compile_commands.json" with clang-tidy, ...
#   clang-tidy -p $BUILD_DIR false-negative/*.cpp
#   run-clang-tidy -p $BUILD_DIR
#
# SEE ALSO:
#  * https://github.com/polystat/clang-tidy-mistakes
#  * https://releases.llvm.org/16.0.0/tools/clang/tools/extra/docs/clang-tidy/index.html
#
# RELATED: CMake -- CMAKE_EXPORT_COMPILE_COMMANDS
#  * https://cmake.org/cmake/help/latest/variable/CMAKE_EXPORT_COMPILE_COMMANDS.html
# ===========================================================================

cmake_minimum_required(VERSION 3.20..3.26)

if(CMAKE_CURRENT_SOURCE_DIR STREQUAL CMAKE_SOURCE_DIR)
    message(STATUS "cmake.version: ${CMAKE_VERSION}")
endif()

# --------------------------------------------------------------------------
# PROJECT:
# ---------------------------------------------------------------------------
project(clang_tidy_mistakes VERSION 0.1 LANGUAGES CXX)

if(NOT DEFINED CMAKE_EXPORT_COMPILE_COMMANDS)
    set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
endif()
if(NOT DEFINED CMAKE_CXX_STANDARD)
    set(CMAKE_CXX_STANDARD 17)
endif()
message(STATUS "USING: CMAKE_CXX_STANDARD=${CMAKE_CXX_STANDARD}")


# ---------------------------------------------------------------------------
# SECTION: LIBS
# ---------------------------------------------------------------------------
add_library(cxx_false_negative)
target_sources(cxx_false_negative PRIVATE
    "false-negative/buffer-overrun.cpp"
    "false-negative/const-assignment.cpp"
    "false-negative/data-execution.cpp"
    "false-negative/dependency-loop.cpp"
    "false-negative/destructor-exception.cpp"
    "false-negative/duplicated-delete.cpp"
    "false-negative/float-loop.cpp"
    "false-negative/function-cast.cpp"
    "false-negative/global-null.cpp"
    "false-negative/infinite-recursion.cpp"
    "false-negative/inifite-goto.cpp"
    "false-negative/long-loop.cpp"
    "false-negative/memcpy-buffer-overrun.cpp"
    "false-negative/noexcept-crash.cpp"
    "false-negative/null-escaping.cpp"
    "false-negative/stack-corruption.cpp"
    "false-negative/thread-invalid-stack.cpp"
    "false-negative/thread-recursion.cpp"
    "false-negative/unhandled-exception.cpp"
    "false-negative/virtual-call-constructor.cpp"
    "false-negative/virtual-div-by-zero.cpp"
)
