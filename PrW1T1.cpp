
#include <iostream>
namespace MatrixNS {
	int** ReadMatrix(int n, int m) {
		int** matrix = new int* [n] {};
		for (int i = 0; i < n; i++) {
			matrix[i] = new int[m];
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				std::cin >> matrix[i][j];
			}
		}
		return matrix;
	}

	int** Transpone(int** matrix, int n, int m) {
		int** transpone = new int* [m] {};
		for (int i = 0; i < m; i++) {
			transpone[i] = new int[n];
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				transpone[j][i] = matrix[i][j];
			}
		}
		return transpone;
	}

	void Change(int** matrix, int n, int m, int row1, int row2) {
		for (int i = 0; i < m; i++) {
			int temp = matrix[row1][i];
			matrix[row1][i] = matrix[row2][i];
			matrix[row2][i] = temp;
		}
	}

	void Print(int** matrix, int n, int m) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				std::cout << matrix[i][j] << " ";
			}
			std::cout << std::endl;
		}
	}
}
int main()
{
	int n = 3;
	int m = 4;
	int** matrix = MatrixNS::ReadMatrix(n, m);
	MatrixNS::Change(matrix, n, m,0,1);
	for (int i = 0; i < n; i++) {
		delete[] matrix[i];
	}
	delete[] matrix;
	
}