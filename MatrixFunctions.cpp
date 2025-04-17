#include "MatrixFunctions.hpp"

// *******************************************************************************
// *******************************************************************************
/*
    Input : Takes 2 2D Matrices (mat_a and mat_b)

    Description : This function performs matrix addition on the input matrices 
    if they are compatible (rows and columns match)

    Returns : The a matrix which stores the result of the matrix addition
*/
std::vector<std::vector<int>> MatrixFunctions::add(
    const std::vector<std::vector<int>>& mat_a,
    const std::vector<std::vector<int>>& mat_b){
    // START OF FUNCTION INNER CODE
    size_t arows = mat_a.size();    // rows in matrix a
    size_t acols = mat_a[0].size(); // columns in matrix a
    size_t brows = mat_b.size();    // rows in matrix b
    size_t bcols = mat_b[0].size(); // columns in matrix b

    if (arows != brows || acols != bcols){
        std::cerr << "Error: Matrices are not compatible for addition" << std::endl;
        return {};  // return empty matrix
    }
    else if (arows == brows && acols == bcols){
        std::vector<std::vector<int>> result(arows, std::vector<int>(acols, 0));
        for (size_t i = 0; i < arows; i++) {                // visit each row
            for (size_t j = 0; j < acols; j++) {            // visit each column
                result[i][j] = mat_a[i][j] + mat_b[i][j];   // add corresponding elements
            }
        }
        return result;  // return the result
    }
    return {};  // return empty matrix
    // END OF FUNCTION INNER CODE
}
    

// *******************************************************************************
/*
    Input : Takes 2 2D Matrices (mat_a and mat_b)

    Description : This function performs matrix multiplication on the input matrices 
    if they are compatible (columns of the first matrix match the rows of the second matrix)

    Returns : The a matrix which stores the result of the matrix multiplication
*/
std::vector<std::vector<int>> MatrixFunctions::multiply(
    const std::vector<std::vector<int>>& mat_a,
    const std::vector<std::vector<int>>& mat_b){
    // START OF FUNCTION INNER CODE
    size_t arows = mat_a.size();    // rows in matrix a
    size_t acols = mat_a[0].size(); // columns in matrix a
    size_t brows = mat_b.size();    // rows in matrix b
    size_t bcols = mat_b[0].size(); // columns in matrix b

    
    if (mat_a.empty() || mat_b.empty() || mat_a[0].empty() || mat_b[0].empty()) {
        std::cerr << "Error: One or more matrices are empty" << std::endl;
        return {};
    }

    if (acols != brows) {
        std::cerr << "Error: Matrices are not compatible for multiplication" << std::endl;
        return {};  // return empty matrix
    }

    std::vector<std::vector<int>> result(arows, std::vector<int>(bcols, 0));
    for (size_t i = 0; i < arows; ++i) {                    // visit each row of matrix a
        for (size_t j = 0; j < bcols; ++j) {                // visit each column of matrix b
            for (size_t k = 0; k < acols; ++k) {            // visit each element in the column of matrix a
                result[i][j] += mat_a[i][k] * mat_b[k][j];  // multiply corresponding elements if row a and column b and add to result
            }
        }
    }
    
    return result;
    // END OF FUNCTION INNER CODE
}


// *******************************************************************************
/*
    Input : Takes a 2D Matrix (mat)

    Description : This function will transpose the input matrix

    Returns : The matrix which stores the result of the matrix transposition
*/
std::vector<std::vector<int>> MatrixFunctions::scale(const int scalar, const std::vector<std::vector<int>>& mat){
    // START OF FUNCTION INNER CODE
    size_t rows = mat.size();       // rows in matrix
    size_t cols = mat[0].size();    // columns in matrix

    std::vector<std::vector<int>> result(rows, std::vector<int>(cols, 0));
    for (size_t i = 0; i < rows; ++i) {         // visit each row of the matrix
        for (size_t j = 0; j < cols; ++j) {     // visit each column of the matrix
            result[i][j] = scalar * mat[i][j];  // multiply each element of the matrix by the scalar
        }
    }

    return result;  // return the transposed matrix
    // END OF FUNCTION INNER CODE
}


// *******************************************************************************
/*
    Input : Takes a 2D Matrix (mat)

    Description : This function will transpose the input matrix

    Returns : The matrix which stores the result of the matrix transposition
*/
std::vector<std::vector<int>> MatrixFunctions::transpose(const std::vector<std::vector<int>>& mat){
    // START OF FUNCTION INNER CODE
    size_t rows = mat.size();       // rows in matrix
    size_t cols = mat[0].size();    // columns in matrix

    std::vector<std::vector<int>> result(cols, std::vector<int>(rows, 0));
    for (size_t i = 0; i < rows; ++i) {     // visit each row of the matrix
        for (size_t j = 0; j < cols; ++j) { // visit each column of the matrix
            result[j][i] = mat[i][j];       // add the swapped element to the result matrix
        }
    }

    return result;  // return the transposed matrix
    // END OF FUNCTION INNER CODE
}

// *******************************************************************************
// *******************************************************************************