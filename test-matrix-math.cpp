#include<iostream>
#include<vector>
#include "MatrixFunctions.hpp"

using namespace std;

void printMatrix(vector<vector<int>> matrix);

int main(){
    vector<vector<int>> A = {{6, 4}, {8, 3}};
    vector<vector<int>> B = {{1, 2, 3}, {4, 5, 6}};
    vector<vector<int>> C = {{2, 4, 6}, {1, 3, 5}};
    vector<vector<int>> D;

    // SOLVE D = A + (3*B * C^T)
    D = MatrixFunctions::add(A,MatrixFunctions::multiply(MatrixFunctions::scale(3,B),MatrixFunctions::transpose(C)));
    printMatrix(D);

    return 0;
}

void printMatrix(vector<vector<int>> matrix){
    for(size_t i = 0; i < matrix.size(); i++){
        for(size_t j = 0; j < matrix[i].size(); j++){
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}