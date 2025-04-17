#include <stdio.h>
#include <stdlib.h>
#include "Matrix.h"

// *******************************************************************************
// *******************************************************************************
/*
    Input :  dimensions of the rows and columns of the matrix
    Returns :  a pointer to a dynamically allocated matrix
*/
Matrix create_matrix(int rows, int cols) {
    // START OF FUNCTION INNER CODE
    Matrix mat;         // Declare a matrix
    mat.rows = rows;    // Set the number of rows
    mat.cols = cols;    // Set the number of columns
    mat.data = malloc(rows * sizeof(int*));         // Allocate memory for rows
    for (int i = 0; i < rows; ++i) {                // iterate through each row
        mat.data[i] = malloc(cols * sizeof(int));   // Allocate memory for each column
    }
    return mat; // Return the matrix
    // END OF FUNCTION INNER CODE
}


// *******************************************************************************
/*
    Input : matrix to free
    Description : Frees the dynamically allocated memory of the matrix
    Returns :  None
*/
void free_matrix(Matrix mat){
    // START OF FUNCTION INNER CODE
    for (int i = 0; i < mat.rows; ++i) {    // visit each row
        free(mat.data[i]);                  // free the memory allocated for each column
    }
    free(mat.data);                         // free the memory allocated for the rows
    // END OF FUNCTION INNER CODE
}


// *******************************************************************************
/*
    Input : matrix to print
    Description : Prints the matrix, purpose is to help facilitate debugging
    Returns :  None
*/
void print_matrix(Matrix mat){
    // START OF FUNCTION INNER CODE
    for (int i = 0; i < mat.rows; ++i) {      // visit each row
        for (int j = 0; j < mat.cols; ++j) {  // visit each column
            printf("%d ", mat.data[i][j]);    // print the value
        }
        printf("\n");
    }
    printf("\n");
    // END OF FUNCTION INNER CODE
}

// *******************************************************************************
/*
    Input : Takes 2 2D Matrices (mat_a and mat_b)

    Description : This function performs matrix addition on the input matrices 
    if they are compatible (rows and columns match)

    Returns : The a matrix which stores the result of the matrix addition
*/
Matrix add(Matrix a, Matrix b){
    // START OF FUNCTION INNER CODE
    if (a.rows != b.rows || a.cols != b.cols) {
        printf("Error: Matrices are not compatible for addition\n");
        exit(1);
    }
    
    Matrix result = create_matrix(a.rows, a.cols);  // Create a matrix to store the result
    for (int i = 0; i < a.rows; ++i) {                      // visit each row
        for (int j = 0; j < a.cols; ++j) {                  // visit each column
            result.data[i][j] = a.data[i][j] + b.data[i][j];// add corresponding elements
        }
    }

    return result;  // return the result
    // END OF FUNCTION INNER CODE
}


// *******************************************************************************
/*
    Input : Takes 2 2D Matrices (mat_a and mat_b)

    Description : This function performs matrix multiplication on the input matrices 
    if they are compatible (columns of the first matrix match the rows of the second matrix)

    Returns : The a matrix which stores the result of the matrix multiplication
*/
Matrix multiply(Matrix a, Matrix b){
    // START OF FUNCTION INNER CODE
    if (a.cols != b.rows) {
        printf("Error: Matrices are not compatible for multiplication\n");
        exit(1);  // return empty matrix
    }

    Matrix result = create_matrix(a.rows, b.cols);                  // matrix to store the result
    for (int i = 0; i < a.rows; ++i) {                              // visit each row of matrix a
        for (int j = 0; j < b.cols; ++j) {                          // visit each column of matrix b
            result.data[i][j] = 0;                                  // prevent garbage values by initializing to 0
            for (int k = 0; k < a.cols; ++k) {                      // visit each element in the column of matrix a
                result.data[i][j] += a.data[i][k] * b.data[k][j];   // multiply corresponding elements if row a and column b and add to result
            }
        }
    }
    
    return result;  // return the result
    // END OF FUNCTION INNER CODE
}


// *******************************************************************************
/*
    Input : Takes a 2D Matrix (mat)

    Description : This function will transpose the input matrix

    Returns : The matrix which stores the result of the matrix transposition
*/
Matrix scale(int scalar, Matrix mat){
    // START OF FUNCTION INNER CODE
    Matrix result = create_matrix(mat.rows, mat.cols);  // create a result matrix
    for (int i = 0; i < mat.rows; ++i) {                // visit each row of the matrix
        for (int j = 0; j < mat.cols; ++j) {            // visit each column of the matrix
            result.data[i][j] = scalar * mat.data[i][j];// multiply each element of the matrix by the scalar
        }
    }

    return result;  // return the result
    // END OF FUNCTION INNER CODE
}


// *******************************************************************************
/*
    Input : Takes a 2D Matrix (mat)

    Description : This function will transpose the input matrix

    Returns : The matrix which stores the result of the matrix transposition
*/
Matrix transpose(Matrix mat){
    // START OF FUNCTION INNER CODE
    Matrix result = create_matrix(mat.cols, mat.rows);  // create a result matrix
    for (int i = 0; i < mat.rows; ++i) {                // visit each row of the matrix
        for (int j = 0; j < mat.cols; ++j) {            // visit each column of the matrix
            result.data[j][i] = mat.data[i][j];         // add the swapped element to the result matrix
        }
    }

    return result;  // return the transposed matrix
    // END OF FUNCTION INNER CODE
}

// *******************************************************************************
// *******************************************************************************