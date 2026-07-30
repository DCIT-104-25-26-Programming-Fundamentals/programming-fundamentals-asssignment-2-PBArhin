// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 4
// =============================================================================
//
// TASK: Matrix Operations
//
// Write a C++ program that performs three operations on matrices (2D arrays),
// each implemented in its own function.
//
// NOTE: Use a fixed maximum size of 10 for array dimensions.
//       Declare arrays as int matrix[10][10].
//
// -----------------------------------------------------------------------------
// PART A — Transpose a Matrix
// -----------------------------------------------------------------------------
// - Read an M x N matrix from the user.
// - Compute and display its transpose (rows become columns, columns become rows).
//
// Example (2 x 3 input):
//
//   Original Matrix:      Transposed Matrix:
//   1  2  3               1  4
//   4  5  6               2  5
//                         3  6
//
// -----------------------------------------------------------------------------
// PART B — Add Two Matrices
// -----------------------------------------------------------------------------
// - Read two matrices of exactly the same size (M x N).
// - Compute their element-wise sum and display the result.
//
// -----------------------------------------------------------------------------
// PART C — Multiply Two Matrices
// -----------------------------------------------------------------------------
// - Read matrix A of size M x N and matrix B of size N x P.
//   (Number of COLUMNS in A must equal number of ROWS in B.)
// - Compute and display the matrix product A x B (result is M x P).
//
// -----------------------------------------------------------------------------
// EXPECTED INPUT FORMAT
// -----------------------------------------------------------------------------
// The user enters each row's values one at a time:
//
//   Enter number of rows: 2
//   Enter number of columns: 3
//   Enter element [0][0]: 1
//   Enter element [0][1]: 2
//   ...
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - Use nested loops for all operations (no external libraries).
// - Each operation must be in its own function (see scaffold below).
// - Display each matrix in a neat, aligned grid using setw().
// - Tip: Complete Part A first, then Parts B and C.
//

// =============================================================================
// YOUR CODE BELOW — remove the // symbols from the scaffold and fill it in
// =============================================================================

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

const int MAX = 10;

void printMatrix(int matrix[MAX][MAX], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << setw(5) << matrix[i][j];
        }
        cout << endl;
    }
}

void readMatrix(int matrix[MAX][MAX], int rows, int cols, string name = "") {
    if (!name.empty()) {
        cout << "Entering values for " << name << ":" << endl;
    }
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << "Enter element [" << i << "][" << j << "]: ";
            cin >> matrix[i][j];
        }
    }
}

void transposeMatrix(int input[MAX][MAX], int output[MAX][MAX], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            output[j][i] = input[i][j];
        }
    }
}

void addMatrices(int a[MAX][MAX], int b[MAX][MAX], int result[MAX][MAX], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = a[i][j] + b[i][j];
        }
    }
}

void multiplyMatrices(int a[MAX][MAX], int b[MAX][MAX], int result[MAX][MAX], int rowsA, int colsA, int colsB) {
    for (int i = 0; i < rowsA; i++) {
        for (int j = 0; j < colsB; j++) {
            result[i][j] = 0; // Initialize sum
            for (int k = 0; k < colsA; k++) {
                result[i][j] += a[i][k] * b[k][j];
            }
        }
    }
}

int main() {
    int m, n, p;

    cout << "--- PART A: TRANSPOSE ---" << endl;
    cout << "Enter number of rows (M): ";
    cin >> m;
    cout << "Enter number of columns (N): ";
    cin >> n;

    int matA[MAX][MAX];
    readMatrix(matA, m, n);

    cout << "\nOriginal Matrix:" << endl;
    printMatrix(matA, m, n);

    int transposed[MAX][MAX];
    transposeMatrix(matA, transposed, m, n);

    cout << "\nTransposed Matrix:" << endl;
    printMatrix(transposed, n, m);

    cout << "\n----------------------------------------\n" << endl;

    cout << "--- PART B: ADDITION ---" << endl;
    cout << "Reading two matrices of size (" << m << " x " << n << ")..." << endl;

    int matB1[MAX][MAX], matB2[MAX][MAX], sumResult[MAX][MAX];
    readMatrix(matB1, m, n, "Matrix 1");
    readMatrix(matB2, m, n, "Matrix 2");

    addMatrices(matB1, matB2, sumResult, m, n);

    cout << "\nMatrix Sum:" << endl;
    printMatrix(sumResult, m, n);

    cout << "\n----------------------------------------\n" << endl;

    cout << "--- PART C: MULTIPLICATION ---" << endl;
    cout << "Enter number of columns for Matrix B (P) [Matrix A is " << m << "x" << n << "]: ";
    cin >> p;

    int multA[MAX][MAX], multB[MAX][MAX], productResult[MAX][MAX];

    cout << "\nEnter Matrix A (" << m << " x " << n << "):" << endl;
    readMatrix(multA, m, n, "Matrix A");

    cout << "\nEnter Matrix B (" << n << " x " << p << "):" << endl;
    readMatrix(multB, n, p, "Matrix B");

    multiplyMatrices(multA, multB, productResult, m, n, p);

    cout << "\nMatrix Product (A x B):" << endl;
    printMatrix(productResult, m, p);

    return 0;
}