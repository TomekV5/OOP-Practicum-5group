#include <iostream>

//Task 1

namespace MatrixNS {

    // Read matrix from console input
    int** readMatrix() {
        int rows, cols;
        std::cin >> rows >> cols;

        int** matrix = new int*[rows];
        for(size_t i = 0; i < rows; i++) {
            matrix[i] = new int[cols];
            for(size_t j = 0; j < cols; j++)
                std::cin >> matrix[i][j];
        }

        return matrix;
    }

    //Transpose matrix by given matrix
    int** transpose(int** matrix, int rows, int cols) {
        int** result = new int*[cols];
        for(size_t i = 0; i < cols; i++) {
            result[i] = new int[rows];
        }

        for(size_t i = 0; i < rows; i++) {
            for(size_t j = 0; j < cols; j++)
                result[j][i] = matrix[i][j];
        }

        return result;
    }

    //Change rows
    int** changeRows(int** matrix, int row1, int row2) {
        row1--;
        row2--;
        int* temp = matrix[row1];
        matrix[row1] = matrix[row2];
        matrix[row2] = temp;
        return matrix;
    }

    //Print matrix
    void print(int** matrix, int rows, int cols) {
        for(size_t i = 0; i < rows; i++) {
            for(size_t j = 0; j < cols; j++) {
                std::cout << matrix[i][j];
                if(j != cols - 1) std::cout << " ";
            }
            std::cout <<"\n"; // same as std::cout << std::endl
        }
    }
}


//Input
// 4 2
// 1 2
// 5 6
// 3 4
// 7 8

//Testing matrix:
// 1 2           1 2        1 3 5 7
// 5 6      -->  3 4    --> 2 4 6 8
// 3 4           5 6
// 7 8           7 8

//For Testing
int main() {
    int** matrix = MatrixNS::readMatrix();
    std::cout << "Matrix read:\n";
    MatrixNS::print(matrix, 4, 2);
    std::cout << "------------------------------\n";
    matrix = MatrixNS::changeRows(matrix, 2, 3);
    std::cout << "Changed row 2 and 3:\n";
    MatrixNS::print(matrix, 4, 2);
    std::cout << "------------------------------\n";
    matrix = MatrixNS::transpose(matrix, 4, 2);
    std::cout << "Transpose:\n";
    MatrixNS::print(matrix, 2, 4);
}