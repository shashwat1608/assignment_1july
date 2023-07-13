#include <iostream>
#include <vector>

using namespace std;

// Structure to represent a sparse matrix element
struct SparseElement {
    int row;
    int col;
    int value;
};

// Function to multiply two sparse matrices
vector<vector<int>> multiplySparseMatrices(const vector<vector<int>>& mat1, const vector<vector<int>>& mat2) {
    int m = mat1.size();
    int k = mat1[0].size();
    int n = mat2[0].size();

    // Convert input matrices to sparse matrices
    vector<SparseElement> sparseMat1, sparseMat2;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < k; j++) {
            if (mat1[i][j] != 0) {
                sparseMat1.push_back({i, j, mat1[i][j]});
            }
        }
    }
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < n; j++) {
            if (mat2[i][j] != 0) {
                sparseMat2.push_back({i, j, mat2[i][j]});
            }
        }
    }

    // Multiply sparse matrices
    vector<vector<int>> result(m, vector<int>(n, 0));
    for (const auto& elem1 : sparseMat1) {
        for (const auto& elem2 : sparseMat2) {
            if (elem1.col == elem2.row) {
                result[elem1.row][elem2.col] += elem1.value * elem2.value;
            }
        }
    }

    return result;
}

// Function to print a matrix
void printMatrix(const vector<vector<int>>& matrix) {
    for (const auto& row : matrix) {
        for (const auto& element : row) {
            cout << element << " ";
        }
        cout << endl;
    }
}

int main() {
    int m, k, n;

    // Input matrix dimensions
    cout << "Enter the number of rows for matrix 1: ";
    cin >> m;
    cout << "Enter the number of columns for matrix 1 / rows for matrix 2: ";
    cin >> k;
    cout << "Enter the number of columns for matrix 2: ";
    cin >> n;

    // Input matrix elements
    vector<vector<int>> mat1(m, vector<int>(k, 0)), mat2(k, vector<int>(n, 0));
    cout << "Enter the elements of matrix 1:" << endl;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < k; j++) {
            cin >> mat1[i][j];
        }
    }
    cout << "Enter the elements of matrix 2:" << endl;
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < n; j++) {
            cin >> mat2[i][j];
        }
    }

    // Multiply matrices
    vector<vector<int>> result = multiplySparseMatrices(mat1, mat2);

    // Print the result
    cout << "Resultant matrix:" << endl;
    printMatrix(result);

    return 0;
}
