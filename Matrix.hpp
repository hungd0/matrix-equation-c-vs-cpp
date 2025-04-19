#ifndef MATRIX_HPP
#define MATRIX_HPP

#include <cstddef> // for size_t
#include <iostream>
#include <vector>

class Matrix {
    private:
    size_t rows;                            // number of rows in the matrix
    size_t cols;                            // number of columns in the matrix
    std::vector<std::vector<int>> data;     // 2D vector to store the matrix data

    public:
    // Constructor
    Matrix();                               // default constructor
    Matrix(size_t rows, size_t cols);       // constructor with rows and cols
    
    // Accessory Functions
    void print_matrix();                    // prints the matrix to the console
    
    // Accessors
    size_t getRows() const;                 // returns the number of rows in the matrix
    size_t getCols() const;                 // returns the number of columns in the matrix
    int get(size_t i, size_t j) const;      // returns the element at position (i, j)

    // Mutators
    void set(size_t i, size_t j, int value);// sets the element at position (i, j) to value

    // Matrix Operations
    /*
        To add two matrices, the number of rows and columns must be the same.
    */
    Matrix add(const Matrix& other);        // adds two matrices
    
    /*
        To multiply two matrices, the number of columns in the first matrix must be equal to the number of rows in the second matrix.
    */ 
    Matrix multiply(const Matrix& other);   // multiplies two matrices

    /*
        To scale a matrix, simply multiply each element by a scalar.
    */
    Matrix scale(const int& scalar);        // scales a matrix by a scalar

    /*
        To transpose a matrix, the number of rows and columns will be swapped.
    */
    Matrix transpose();                     // returns the transpose of a matrix
};
#endif // MATRIX_HPP
