cmake_minimum_required(VERSION 3.5)
project(project1 C ASM_NASM)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O0 -g -Wall -std=gnu14")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Werror -Wformat-security -Wignored-qualifiers -Winit-self -Wswitch-default -Wfloat-equal -Wshadow -Wpointer-arith -Wtype-limits -Wempty-body -Wlogical-op -Wmissing-field-initializers -Wctor-dtor-privacy	-Wnon-virtual-dtor -Wstrict-null-sentinel -Wold-style-cast -Woverloaded-virtual -Wsign-promo -Weffc++")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -nasm=intel")
SET(CMAKE_ASM-NASM_COMPILER_ARG1 "-f elf")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wno-unused-variable -Wno-unused-but-set-variable -Wno-effc++")

#set_source_files_properties(InstructionCounter.asm PROPERTIES COMPILE_FLAGS "-x assembler-with-cpp")

set(SOURCE_FILES
    main.c
    InstructionCounter.asm
)

add_executable(project1 ${SOURCE_FILES})