# matrix-equation-c-vs-cpp
## AUTHOR
NAME: HUNG DO

AFFILIATION: University of Maryland, Baltimore County

CLASS: CMSC313_1114_SP2025

DATE: April 16, 2025

## DESCRIPTION 
A comparative study of C and C++ implementations for solving a matrix equation. For this project, we will solve D = A + (3 * B) * C^T. The results of this project will help us determine differences in performance and management across two different programming languages. Specifically, this project will demonstrate matrix addition, matrix multiplication, matrix scaling, and matrix transposition.

## FILES
- Matrix.hpp (C++ FILE) - Header file declaring the Matrix class and the corresponding methods for each matrix operation.
- Matrix.cpp (C++ FILE) - Source file implementing the matrix operations (add, multiply, scale, transpose) defined in the Matrix.hpp file.
- test-matrix-math.cpp (C++ FILE) - Test file containing a main() function that defines example matrices (A, B, and C) and performs the operations to generate the final result to store in matrix D.
- Matrix.h (C FILE) - Header file declaring the Matrix struct and the corresponding methods for each matrix operation.
  > *Unlike the C++ project, which used vecotrs, C does not have automatic memory deallocation. Therefore, to emmulate the C++ project as much as possible, this program implements a Matrix struct that allocates and frees memory (freeing must be called manually).*
- Matrix.c (C FILE) - Source file implementing the matrix operations (add, multiply, scale, transpose) defined in the .h file. 
  > *This file was written to be as similar as possible to the Matrix.cpp file.*
- test-matrix-math.c (C FILE) - Test file containing a main() function that defines example matrices (A, B, and C) and performs the operations to generate the final result to store in matrix D.

## BUILD INSTRUCTIONS
### To build the C++ version of the project
1. Download the .hpp and .cpp files, then run the following instructions:
```bash
g++ -Wall -Wextra -std=c++17 Matrix.cpp test-matrix-math.cpp -o matrix_math1
```

2. Then run: 
```bash
./matrix_math1
```
### To build the C version of the project
1. Download the .h and .c files, then run the following instructions:
```bash
gcc -Wall -Wextra -std=c99 Matrix.c test-matrix-math.c -o matrix_math2
```

2. Then run: 
```bash
./matrix_math2
```

## TESTING METHODOLOGY
This project will test the matrix methods with hardcoded matrics A, B, and C. The hardcoded matrices purposesly result in a valid solution. Any mismatches in matrix dimensions will throw and error. The matrices will be used to solve D = A + (3 * B) * C^T, in which the result will be printed in a row by row order for readability.

## ADDITIONAL INFORMATION
- C++ version uses vectors to clean up memory without manual delete calls.
- C++ version uses size_t for x86 compatability
