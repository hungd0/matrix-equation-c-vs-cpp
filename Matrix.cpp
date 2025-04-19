#include "Matrix.hpp"

// *******************************************************************************
// *******************************************************************************
// Constructors
Matrix::Matrix(){
    this->rows = 0;                                 // default rows to 0
    this->cols = 0;                                 // default columns to 0
    this->data = std::vector<std::vector<int>>();   // empty vector
}

Matrix::Matrix(size_t rows, size_t cols) {
    this->rows = rows;
    this->cols = cols;
    this->data = std::vector<std::vector<int>>(rows, std::vector<int>(cols,0));
}


// *******************************************************************************
// Print Function
/*
    Input : None
    Description : Prints the matrix, purpose is to help facilitate debugging
    Returns :  None
*/
void Matrix::print_matrix() {
    for (size_t i = 0; i < this->rows; i++) {
        for (size_t j = 0; j < this->cols; j++) {
            std::cout << this->data[i][j] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}


// *******************************************************************************
// Accessors
size_t Matrix::getRows() const { 
    return rows; 
}

size_t Matrix::getCols() const { 
    return cols; 
}

int Matrix::get(size_t i, size_t j) const {
    if (i >= rows || j >= cols || i < 0 || j < 0) {
        throw std::out_of_range("Matrix::get: index out of range");
    }
    return data[i][j];
}

// *******************************************************************************
// Mutators
void Matrix::set(size_t i, size_t j, int value) { 
    if (i >= rows || j >= cols || i < 0 || j < 0) {
        throw std::out_of_range("Matrix::set: index out of range");
    }
    data[i][j] = value; 
}


// *******************************************************************************
// Matrix Operations
/*
    Input : Takes a 2D Matrix

    Description : This function performs matrix addition on the current object matrix and input matrix 
    if they are compatible (rows and columns match)

    Returns : The a matrix which stores the result of the matrix addition
*/   
Matrix Matrix::add(const Matrix& other){
    // START OF FUNCTION INNER CODE
    if (this->rows != other.getRows() || this->cols != other.getCols()) {
        std::cerr << "Error: Matrices are not compatible for addition" << std::endl;
        return {};  // return empty matrix
    }
    
    Matrix result(this->rows, this->cols);                          // create a new matrix
    for (size_t i = 0; i < this->rows; i++) {                       // visit each row
        for (size_t j = 0; j < this->cols; j++) {                   // visit each column
            result.set(i, j, (this->data[i][j] + other.get(i,j)));  // add corresponding elements
        }
    }
    return result;  // return the result
    // END OF FUNCTION INNER CODE
}

// *******************************************************************************
/*
    Input : Takes a 2D Matrix

    Description : This function performs matrix multiplication on the current object matrix and input matrix 
    if they are compatible (columns of the object matrix match the rows of the other matrix)

    Returns : The a matrix which stores the result of the matrix multiplication
*/
Matrix Matrix::multiply(const Matrix& other){
    // START OF FUNCTION INNER CODE
    if (this->cols != other.getRows()) {
        std::cerr << "Error: Matrices are not compatible for multiplication\n";
        return {};
    }

    Matrix result(this->rows, other.getCols());
    for (size_t i = 0; i < this->rows; ++i) {           // visit each row of the current matrix
        for (size_t j = 0; j < other.getCols(); ++j) {  // visit each column of the other matrix
            for (size_t k = 0; k < this->cols; ++k) {   // visit each element in the column of the current matrix
                // multiply corresponding elements of the current matrix's row and column of the other matrix and add to result
                result.set(i, j, (result.get(i,j) + this->data[i][k] * other.get(k,j)));
            }
        }
    }
    return result;
    // END OF FUNCTION INNER CODE
}

// *******************************************************************************
/*
    Input : Takes a 2D Matrix (mat)

    Description : This function will transpose the current object matrix

    Returns : The matrix which stores the result of the matrix transposition
*/
Matrix Matrix::scale(const int& scalar){
    Matrix result(this->rows, this->cols);
    for (size_t i = 0; i < this->rows; ++i) {               // visit each row of the matrix
        for (size_t j = 0; j < this->cols; ++j) {           // visit each column of the matrix
            result.set(i, j, (scalar * this->data[i][j]));  // multiply each element of the matrix by the scalar
        }
    }

    return result;  // return the transposed matrix
    // END OF FUNCTION INNER CODE
}

// *******************************************************************************
/*
    Input : Takes a 2D Matrix (mat)

    Description : This function will transpose the current object matrix

    Returns : The matrix which stores the result of the matrix transposition
*/
Matrix Matrix::transpose(){
    // START OF FUNCTION INNER CODE
    Matrix result(this->cols, this->rows);
    for (size_t i = 0; i < this->rows; ++i) {     // visit each row of the matrix
        for (size_t j = 0; j < this->cols; ++j) { // visit each column of the matrix
            result.set(j, i, (this->data[i][j])); // add the swapped element to the result matrix
        }
    }

    return result;  // return the transposed matrix
    // END OF FUNCTION INNER CODE
}

// *******************************************************************************
// *******************************************************************************
