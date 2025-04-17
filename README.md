# matrix-equation-c-vs-cpp
AUTHOR: Hung Do

AFFILIATION: University of Maryland, Baltimore County, CMSC313_1114_SP2025

DATE: April 16, 2025

DESCRIPTION: A comparative study of C and C++ implementations for solving a matrix equation. For this project, we will solve D = A + (3 * B) * C^T. The results of this project will help us determine differences in performance and management across two different programming languages. Specifically, this project will demonstrate matrix addition, matrix multiplication, matrix scaling, and matrix transposition.

FILES:
MatrixFunctions.hpp - Header file declaring the MatrixFunctions class and the corresponding static methods for each matrix operation.
MatrixFunctions.cpp - Source file implementing the matrix operations (add, multiply, scale, transpose) defined in the .hpp file.
test-matrix-math.cpp - Test file containing a main() function that defines example matrices (A, B, and C) and performs the operations to generate the final result, matrix D.


BUILD INSTRUCTIONS:
To build the C++ project, download the .hpp and .cpp files, then run the following instructions:

g++ -Wall -Wextra -std=c++17 MatrixFunctions.cpp test-matrix-math.cpp -o matrix_math

Then run: 

./matrix_math

TESTING METHODOLOGY:
This project will test the matrix methods with hardcoded matrics A, B, and C. The hardcoded matrices purposesly result in a valid solution. Any mismatches in matrix dimensions will throw and error. The matrices will be used to solve D = A + (3 * B) * C^T, in which the result will be printed in a row by row order for readability.

ADDITIONAL INFORMATION:
C++ uses vectors to clean up memory without manual delete calls.

