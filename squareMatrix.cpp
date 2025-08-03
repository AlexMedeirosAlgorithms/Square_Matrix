#include <iostream>
#include <vector>

using namespace std;

// CSC6033 Module 02 Coding Project
// Alexander Medeiros July 16, 2024

/*
This program is designed define a class called squareMatrix , including methods to store and access square matrix elements. 

Class constructor:
    squareMatrix(int n) : order(n), matrix(n, vector<double>(n, 0.0)) 

Class Methods:
    getElement(int row, int col): ~ this method gets an element from a specified row and column position
        - arguments are, row # and column #

    setElement(int row, int col, double value): ~ this method sets a matrix value at the specified index positions
        - arguments are, row # col #, and the element value type double

    getDiagonal(): ~ loops through elements in the matrix and prints the diagonal

    display(): ~ loops through elements in the matrix and prints them to display for the user
*/

class squareMatrix {
private:
    int order;
    vector<vector<double>> matrix;

public:
    // Parameterized constructor
    squareMatrix(int n) : order(n), matrix(n, vector<double>(n, 0.0)) {}

    // Getter method for matrix elements
    double getElement(int row, int col) const {
        if (row >= 0 && row < order && col >= 0 && col < order) {
            return matrix[row][col];
        }
        throw out_of_range("Indices are out of bounds.");
    }

    // Setter method for matrix elements
    void setElement(int row, int col, double value) {
        if (row >= 0 && row < order && col >= 0 && col < order) {
            matrix[row][col] = value;
        } else {
            throw out_of_range("Indices are out of bounds.");
        }
    }

    // Getter method for diagonal elements
    vector<double> getDiagonal() const {
        vector<double> diagonal(order);
        for (int i = 0; i < order; ++i) {
            diagonal[i] = matrix[i][i];
        }
        return diagonal;
    }

    // Method to display the matrix
    void display() const {
        for (int i = 0; i < order; ++i) {
            for (int j = 0; j < order; ++j) {
                cout << matrix[i][j] << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    // Create a 3x3 square matrix
    squareMatrix matrix(3);

    // Set elements in the matrix
    matrix.setElement(0, 0, 1.1);
    matrix.setElement(0, 1, 2.2);
    matrix.setElement(0, 2, 3.3);
    matrix.setElement(1, 0, 4.4);
    matrix.setElement(1, 1, 5.5);
    matrix.setElement(1, 2, 6.6);
    matrix.setElement(2, 0, 7.7);
    matrix.setElement(2, 1, 8.8);
    matrix.setElement(2, 2, 9.9);

    // Display the matrix
    cout << "Matrix:" << endl;
    matrix.display();

    // Get an element from the matrix
    cout << "Element at (1, 1): " << matrix.getElement(1, 1) << endl;

    // Get the diagonal elements of the matrix
    vector<double> diagonal = matrix.getDiagonal();
    cout << "Diagonal elements: ";
    for (double val : diagonal) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
