#ifndef MATRIX_H
#define MATRIX_H

// Matrix struct definition
typedef struct {
    int rows;   // number of rows
    int cols;   // number of columns
    int** data; // pointer to the data
} Matrix;

// "Constructor"
Matrix create_matrix(int rows, int cols);   // creates a matrix with the given number of rows and columns

// "Destructor"
void free_matrix(Matrix mat);               // frees the memory allocated for the matrix

// Accessory Functions
void print_matrix(Matrix mat);              // prints the matrix to the console


// Matrix Operations
/*
    To add two matrices, the number of rows and columns must be the same.
*/
Matrix add(Matrix a, Matrix b);             // adds two matrices

/*
    To multiply two matrices, the number of columns in the first matrix must be equal to the number of rows in the second matrix.
*/
Matrix multiply(Matrix a, Matrix b);        // multiplies two matrices

/*
    To scale a matrix, simply multiply each element by a scalar.
*/
Matrix scale(int scalar, Matrix mat);       // scales a matrix by a scalar

/*
    To transpose a matrix, the number of rows and columns will be swapped.
*/
Matrix transpose(Matrix mat);               // returns the transpose of a matrix

#endif