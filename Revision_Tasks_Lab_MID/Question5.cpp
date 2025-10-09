#include<iostream>
using namespace std;

int num = 5;

int jungle[5][5] = {
    {1,1,1,0,1},
    {0,1,0,1,1},
    {1,1,1,1,0},
    {0,1,0,1,1},
    {1,1,1,0,1},
};

int rabbit[5][5];
int cat[5][5];

bool isSafeRabbit(int x,int y) {
    if(x >=0 && x < num && y >= 0 && y < num && jungle[x][y] == 1 && rabbit[x][y] == 0) {
        return true;
    } else {
        return false;
    }
}

bool isSafeCat(int x,int y) {
    if(x >=0 && x < num && y >= 0 && y < num && jungle[x][y] == 1 && cat[x][y] == 0) {
        return true;
    } else {
        return false;
    }
}

bool solvePath_rabbit(int x,int y) {
    if(isSafeRabbit(x,y)) {
        rabbit[x][y] = 1;
        if(x == 2 && y == 2) {
            return true;
        }

        if(solvePath_rabbit(x+1,y)) {
            return true;
        }
        if(solvePath_rabbit(x,y+1)) {
            return true;
        }
        if(solvePath_rabbit(x - 1,y)) {
            return true;
        }
        if(solvePath_rabbit(x,y - 1)) {
            return true;
        }
        rabbit[x][y] = 0;
        return false;
    }
    return false;
}

bool solvePath_cat(int x,int y) {
    if(isSafeCat(x,y)) {
        cat[x][y] = 1;
        if(x == 2 && y == 2) {
            return true;
        }

        if(solvePath_cat(x - 1,y)) {
            return true;
        }
        if(solvePath_cat(x,y - 1)) {
            return true;
        }
        if(solvePath_cat(x + 1,y)) {
            return true;
        }
        if(solvePath_cat(x,y + 1)) {
            return true;
        }
        cat[x][y] = 0;
        return false;
    }
    return false;
}

void rabbitSolve() {
    for(int i=0;i<num;i++) {
        for(int j=0;j<num;j++) {
            rabbit[i][j] = 0;
        }
    }

    if(!solvePath_rabbit(0,0)) {
        cout<<"Solution Not Found"<<endl;
        return;
    }

    for(int i=0;i<num;i++) {
        for(int j=0;j<num;j++) {
            cout<<rabbit[i][j]<<" ";
        }
        cout<<endl;
    }
}

void catSolve() {
    for(int i=0;i<num;i++) {
        for(int j=0;j<num;j++) {
            cat[i][j] = 0;
        }
    }

    if(!solvePath_cat(4,4)) {
        cout<<"Solution Not Found"<<endl;
        return;
    }

    for(int i=0;i<num;i++) {
        for(int j=0;j<num;j++) {
            cout<<cat[i][j]<<" ";
        }
        cout<<endl;
    }
}

void intersectionPoint() {
    for(int i=0;i<num;i++) {
        for(int j=0;j<num;j++) {
            if(rabbit[i][j] == 1 && cat[i][j] == 1) {
                cout<<"The intersection Point of both rabbit an cat is: ("<<i<<" , "<<j<<") "<<endl;
            }
        }
    }
}

int main() {
    cout<<"All possible paths for the Rabbit from (0,0) to (2,2)"<<endl;
    cout<<endl;
    rabbitSolve();
    cout<<endl;
    cout<<"All possible paths for the Cat from (4,4) to (2,2)"<<endl;
    catSolve();
    cout<<endl;
    intersectionPoint();
}
