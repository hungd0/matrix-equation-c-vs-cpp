#ifndef MATRIXFUNCTIONS_HPP
#define MATRIXFUNCTIONS_HPP

#include <cstddef> // for size_t
#include <iostream>
#include <vector>

class MatrixFunctions {
    public:
    // Matrix Operations
    /*
        To add two matrices, the number of rows and columns must be the same.
    */
    static std::vector<std::vector<int>> add(
        const std::vector<std::vector<int>>& mat_a,
        const std::vector<std::vector<int>>& mat_b); // Adds two matrices, returns the result
    
    /*
        To multiply two matrices, the number of columns in the first matrix must be equal to the number of rows in the second matrix.
    */
    static std::vector<std::vector<int>> multiply(
        const std::vector<std::vector<int>>& mat_a,
        const std::vector<std::vector<int>>& mat_b); // Multiplies two matrices, returns the result
        
    /*
        To scale a matrix, simply multiply each element by a scalar.
    */
    static std::vector<std::vector<int>> scale(const int scalar, const std::vector<std::vector<int>>& mat);
    
    /*
        To transpose a matrix, the number of rows and columns will be swapped.
    */
    static std::vector<std::vector<int>> transpose(const std::vector<std::vector<int>>& mat); // Transposes a matrix, returns the result
};

#endif // MATRIXFUNCTIONS_HPP