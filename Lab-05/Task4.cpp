#include <iostream>
using namespace std;

bool isSafe(int** board, int row, int col, int n) {
    for (int i = 0; i < col; i++) {
        if (board[row][i] == 1) {
            return false;
        }
    }
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j] == 1) {
            return false;
        }
    }
    for (int i = row, j = col; i < n && j >= 0; i++, j--) {
        if (board[i][j] == 1) {
            return false;
        }
    }
    return true;
}

bool solveQueen(int** board, int col, int n) {
    if (col >= n) {
        return true;
    }
    
    for (int i = 0; i < n; i++) {
        if (isSafe(board, i, col, n)) {
            board[i][col] = 1;
            
            if (solveQueen(board, col + 1, n)) {
                return true;
            }
            
            board[i][col] = 0;
        }
    }
    return false;
}

void countAllSolution(int** board, int col, int n, int& count) {
    if (col >= n) {
        count++;
        return;
    }
    
    for (int i = 0; i < n; i++) {
        if (isSafe(board, i, col, n)) {
            board[i][col] = 1;
            countAllSolution(board, col + 1, n, count);
            board[i][col] = 0;
        }
    }
}

void printBoard(int** board, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (board[i][j] == 1) {
                cout << "Q ";
            } else {
                cout << ". ";
            }
        }
        cout << endl;
    }
    cout << endl;
}

bool solveOneSolution(int n) {
    int** board = new int*[n];
    for (int i = 0; i < n; i++) {
        board[i] = new int[n];
        for (int j = 0; j < n; j++) {
            board[i][j] = 0;
        }
    }
    
    cout << "Finding solution for N = " << n << endl;
    
    if (!solveQueen(board, 0, n)) {
        cout << "Solution does not exist for N = " << n << endl;
        for (int i = 0; i < n; i++) {
            delete[] board[i];
        }
        delete[] board;
        return false;
    }
    
    printBoard(board, n);
    
    for (int i = 0; i < n; i++) {
        delete[] board[i];
    }
    delete[] board;
    
    return true;
}

void countSolutions(int n) {
    int** board = new int*[n];
    for (int i = 0; i < n; i++) {
        board[i] = new int[n];
        for (int j = 0; j < n; j++) {
            board[i][j] = 0;
        }
    }
    
    int count = 0;
    countAllSolution(board, 0, n, count);
    
    cout << "Total distinct solutions for N = " << n << ": " << count << endl;
    
    for (int i = 0; i < n; i++) {
        delete[] board[i];
    }
    delete[] board;
}

int main() {
    int N;
    
    cout << "Enter the value of N: ";
    cin >> N;
    
    if (N <= 0) {
        cout << "Please enter a positive integer." << endl;
        return 1;
    }
    
    if (solveOneSolution(N)) {
        countSolutions(N);
    }
    
    cout << "check for N = 4 " << endl;
    if (solveOneSolution(4)) {
        countSolutions(4);
    }
    
    return 0;
}
