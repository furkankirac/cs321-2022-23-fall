// CS321 Programming Paradigms

// Major Concepts to touch:

// Lecture contents will be available in the LMS
// code will be available in https://github.com/furkankirac

// History of C++ and a general overview of the language
// --------------------------------------------------------------------------------
// Who designed C language? Dennis Ritchie (also designer of UNIX OS)
// Smalltalk - First flavor of OOP
// C++ by Bjarne Stroustrup

// Core language + Standard Library (Alexander Stepanov)
// ANSI
// ISO

// C++8x, C++98, C++04, C++11, C++14, C++17, C++20, C++23 (upcoming)

// CHECK below:
// COMPILER CONFORMANCE: https://en.cppreference.com/w/cpp/compiler_support
// LANGUAGE REFERENCE: https://en.cppreference.com/

// Standard Library: libstdc++ (GCC), libc++ (clang is a fork of GCC4.2), MSVC
// windows uses \ as path separator
// macos, and linux uses / as path separator

// CMake: is important, not very likable, but nothing better than it right now :(

// Imperative-Programming paradigm
// Object-Oriented-Programming paradigm
// Functional-Programming paradigm
// Generic-Programming paradigm

// Compile-time vs run-time parameters

// All exams are on campus, face-to-face
// Midterm Exam 1 (25%)
// Midterm Exam 2 (35%)
// Final Exam (40%)

// Will use:
//   Compiler: GCC 12+ and C++20 standard.
//   MacOS: install GCC by using Homebrew: brew install gcc
//   Linux: install by using the package manager the latest GCC
//   Windows: use a Virtual Machine, install latest Ubuntu with GCC
//   You can use GCC, and any editor of your choice.

//   However, I would highly suggest you to use Qt Creator if not familiar with C++.
//   Editor: Qt Creator 8.0+. Why? Lightweight, very nicely supports CMake.
//   Don't download the whole Qt Framework! You can only download QtCreator for your machine.
//   It's open-source.

// C and C++ have smt. called preprocessor

#include <iostream>

int main(int argc, char* argv[])
{
    std::cout << "Hello World!" << std::endl;
    std::cout << argc << std::endl;

    for(int i=0; i<argc; i++)
    {
        std::cout << argv[i] << std::endl;
    }

    return 0; // 0 means everything is okay
}
