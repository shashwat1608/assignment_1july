#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> generateMatrix(int n) {
    vector<vector<int>> matrix(n, vector<int>(n, 0));
    int num = 1;
    int rowStart = 0, rowEnd = n - 1;
    int colStart = 0, colEnd = n - 1;

    while (rowStart <= rowEnd && colStart <= colEnd) {
        // Traverse right
        for (int col = colStart; col <= colEnd; ++col) {
            matrix[rowStart][col] = num++;
        }
        ++rowStart;

        // Traverse down
        for (int row = rowStart; row <= rowEnd; ++row) {
            matrix[row][colEnd] = num++;
        }
        --colEnd;

        // Traverse left
        if (rowStart <= rowEnd) {
            for (int col = colEnd; col >= colStart; --col) {
                matrix[rowEnd][col] = num++;
            }
            --rowEnd;
        }

        // Traverse up
        if (colStart <= colEnd) {
            for (int row = rowEnd; row >= rowStart; --row) {
                matrix[row][colStart] = num++;
            }
            ++colStart;
        }
    }

    return matrix;
}

void printMatrix(const vector<vector<int>>& matrix) {
    int n = matrix.size();
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << matrix[i][j] << "\t";
        }
        cout << endl;
    }
}

int main() {
    int n;
    cout << "Enter the value of n: ";
    cin >> n;

    vector<vector<int>> matrix = generateMatrix(n);

    cout << "Generated Matrix:" << endl;
    printMatrix(matrix);

    return 0;
}
