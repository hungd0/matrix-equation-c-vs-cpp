#include "Matrix.h"

int main() {
    Matrix A = create_matrix(2, 2);
    Matrix B = create_matrix(2, 3);
    Matrix C = create_matrix(2, 3);
    
    // Fill in A, B, and C with values
    A.data[0][0] = 6; A.data[0][1] = 4; 
    A.data[1][0] = 8; A.data[1][1] = 3;

    B.data[0][0] = 1; B.data[0][1] = 2; B.data[0][2] = 3;
    B.data[1][0] = 4; B.data[1][1] = 5; B.data[1][2] = 6;

    C.data[0][0] = 2; C.data[0][1] = 4; C.data[0][2] = 6;
    C.data[1][0] = 1; C.data[1][1] = 3; C.data[1][2] = 5;

    // SOLVE D = A + (3*B * C^T)
    /*
        ***NOTE: ALL INTERMEDIATE OPERATIONS MUST BE STORE SEPERATELY***
    */
    Matrix B_scaled = scale(3,B);
    Matrix C_transpose = transpose(C);
    Matrix BC_product = multiply(B_scaled, C_transpose);
    Matrix D = add(A,BC_product);

    print_matrix(D);

    // Free all matrices and intermediate results
    free_matrix(A); free_matrix(B); free_matrix(C); free_matrix(D);
    free_matrix(B_scaled); free_matrix(C_transpose); free_matrix(BC_product);

    return 0;
}
