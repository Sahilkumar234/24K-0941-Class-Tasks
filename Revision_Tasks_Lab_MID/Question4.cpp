#include<iostream>
using namespace std;

// line 42 finalWaterGrid[x][y] = 0; this does the backtracking

int num = 4;

int waterGrid[4][4] = {
    {1,1,0,1},
    {0,1,1,0},
    {1,1,0,1},
    {0,1,1,1},
};

int finalWaterGrid[5][5];

bool isSafe(int x,int y) {
    if(x >=0 && x < num && y >= 0 && y < num && waterGrid[x][y] == 1 && finalWaterGrid[x][y] == 0) {
        return true;
    } else {
        return false;
    }
}

bool WatContGrid(int x,int y) {
    if(isSafe(x,y)) {
        finalWaterGrid[x][y] = 1;
        if(x == num - 1 && y == num - 1) {
            return true;
        }

        if(WatContGrid(x + 1,y)) {
            return true;
        }
        if(WatContGrid(x,y + 1)) {
            return true;
        }
        if(WatContGrid(x - 1,y)) {
            return true;
        }
        if(WatContGrid(x,y - 1)) {
            return true;
        }
        finalWaterGrid[x][y] = 0;
        return false;
    }
    return false;
}

void solveWatGrid() {
    for(int i=0;i<num;i++) {
        for(int j=0;j<num;j++) {
            finalWaterGrid[i][j] = 0;
        }
    }

    if(!WatContGrid(0,0)) {
        cout<<"Solution Not found..."<<endl;
        return;
    } 

    for(int i=0;i<num;i++) {
        for(int j=0;j<num;j++) {
            cout<<finalWaterGrid[i][j]<<" ";
        }
        cout<<endl;
    }
}

int main() {
    solveWatGrid();
}
