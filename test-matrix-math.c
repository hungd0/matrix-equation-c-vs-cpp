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

    Matrix D = add(A,multiply(scale(3,B),transpose(C)));

    print_matrix(D);

    // Free all matrices
    free_matrix(A); free_matrix(B); free_matrix(C); free_matrix(D);

    return 0;
}