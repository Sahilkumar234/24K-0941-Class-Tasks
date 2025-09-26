#include <iostream>
using namespace std;

int num = 5;

int maze[5][5] = {
    {1,0,1,0,1},
    {1,1,1,1,1},
    {0,1,0,1,0},
    {1,1,0,1,1},
    {0,1,1,0,1}
};

int sol[5][5];

bool isSafe(int x, int y) {
    return (x >= 0 && x < num && y >= 0 && y < num && maze[x][y] == 1 && sol[x][y] == 0);
}

bool solveMazeUtil(int x, int y) {
    if (x == num-1 && y == num-1) {
        sol[x][y] = 1;
        return true;
    }
    if (isSafe(x, y)) {
        sol[x][y] = 1;
        if (solveMazeUtil(x+1, y)) 
        return true;
        if (solveMazeUtil(x, y+1)) 
        return true;
        if (solveMazeUtil(x-1, y)) 
        return true;
        if (solveMazeUtil(x, y-1)) 
        return true;
        sol[x][y] = 0;
        return false;
    }
    return false;
}

void solveMaze() {
    for(int i=0;i<num;i++)
        for(int j=0;j<num;j++)
            sol[i][j]=0;

    if (!solveMazeUtil(0,0)) {
        cout << "No solution"<<endl;
        return;
    }
    for(int i=0;i<num;i++) {
        for(int j=0;j<num;j++)
            cout << sol[i][j] << " ";
        cout << endl;
    }
}

int main() {
    solveMaze();
    return 0;
}
