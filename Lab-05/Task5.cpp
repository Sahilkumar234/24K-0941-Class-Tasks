#include <iostream>
using namespace std;

#define N 7
int maze[N][N] = {
    {1, 0, 1, 1, 1, 0, 1},
    {1, 1, 0, 1, 1, 1, 0},
    {1, 0, 1, 0, 1, 0, 1},
    {1, 1, 1, 1, 1, 0, 1},
    {0, 0, 0, 0, 1, 1, 1},
    {1, 1, 1, 0, 1, 0, 1},
    {0, 0, 1, 1, 1, 1, 1}
};
int solution[N][N] = {0};
bool isValid(int x, int y) {
    return (x >= 0 && x < N && y >= 0 && y < N && maze[x][y] == 1 && solution[x][y] == 0);
}
bool solveMaze(int x, int y) {
    if (x == N-1 && y == N-1) {
        solution[x][y] = 1;
        return true;
    }
    if (isValid(x, y)) {
        solution[x][y] = 1;
        if (solveMaze(x, y + 1))
            return true;
        if (solveMaze(x + 1, y))
            return true;
        if (solveMaze(x, y - 1))
            return true;
        if (solveMaze(x - 1, y))
            return true;
        solution[x][y] = 0;
        return false;
    }
    
    return false;
}

void printSolution() {
    cout << "array child's path:" << endl;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << solution[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    // Start solving from top-left corner (0, 0)
    if (solveMaze(0, 0)) {
        cout << "Path found to the ice cream shop" << endl;
        printSolution();
    } else {
        cout << "No path exists to the ice cream shop" << endl;
    }
    
    return 0;
}
