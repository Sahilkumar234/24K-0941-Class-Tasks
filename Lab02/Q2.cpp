#include <iostream>
using namespace std;

class DynamicMatrix {
private:
    int** matrix1;
    int rows;
    int cols;
public:
    DynamicMatrix(int r, int c, int fillValue = 0) : rows(r), cols(c) {
        matrix1 = new int*[r];
        for (int i = 0; i < r; ++i) {
            matrix1[i] = new int[c];
        }
        for (int i = 0; i < rows; ++i)
            for (int j = 0; j < cols; ++j)
                matrix1[i][j] = fillValue;
    }
    ~DynamicMatrix() {
         if (matrix1) {
            for (int i = 0; i < rows; ++i) {
                delete[] matrix1[i];
            }
            delete[] matrix1;
            matrix1 = nullptr;
        }
    }


    void resize(int newRows, int newCols, int fillValue = 0) {
        int** newMatrix = new int*[newRows];
        for (int i = 0; i < newRows; ++i) {
            newMatrix[i] = new int[newCols];
        }

        for (int i = 0; i < newRows; ++i) {
            for (int j = 0; j < newCols; ++j) {
                if (i < rows && j < cols) {
                    newMatrix[i][j] = matrix1[i][j];
                } else {
                    newMatrix[i][j] = fillValue;
                }
            }
        }

        matrix1 = newMatrix;
        rows = newRows;
        cols = newCols;
    }
    void transpose() {
        int** transposed = new int*[cols];
        for (int i = 0; i < cols; ++i) {
            transposed[i] = new int[rows];
        }
        for (int i = 0; i < rows; ++i)
            for (int j = 0; j < cols; ++j)
                transposed[j][i] = matrix1[i][j];

        int temp = rows;
        rows = cols;
        cols = temp;

        matrix1 = transposed;
    }

    void printWithAdd2OddIndices() {
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                int val = matrix1[i][j];
                if ((i + j) % 2 == 1) {
                    val += 2;
                }
                cout << val << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    DynamicMatrix matrix(3, 4, 1);

    cout << "Initial matrix: "<<endl;
    matrix.printWithAdd2OddIndices();

    matrix.resize(4, 5, 7);
    cout << "After resize to 4x5 with fill=7: "<<endl;
    matrix.printWithAdd2OddIndices();

    matrix.transpose();
    cout << "After transpose:"<<endl;
    matrix.printWithAdd2OddIndices();

    return 0;
}
