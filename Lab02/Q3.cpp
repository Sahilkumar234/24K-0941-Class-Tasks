#include <iostream>
using namespace std;

class JaggedArray {
    int **array;      
    int *colSizes;    
    int rows;        

public:
  
    JaggedArray(int r) {
        rows = r;
        array = new int*[rows];
        colSizes = new int[rows];
        for (int i = 0; i < rows; i++) {
            array[i] = 0;
            colSizes[i] = 0;
        }
    }

    
    void store(int r, int size, int values[]) {
        delete[] array[r];  
        array[r] = new int[size];
        colSizes[r] = size;

        for (int i = 0; i < size; i++) {
            array[r][i] = values[i];
        }
    }

    
    void display() {
        for (int i = 0; i < rows; i++) {
            int sum = 0;
            for (int j = 0; j < colSizes[i]; j++) {
                sum += array[i][j];
            }
            cout << "Team " << i + 1 << " score sum = " << sum << endl;
        }
    }

    
    ~JaggedArray() {
        for (int i = 0; i < rows; i++) {
            delete[] array[i];
        }
        delete[] array;
        delete[] colSizes;
    }
};

int main() {
    int teams = 3;
    JaggedArray scores(teams);

  
    int team1[] = {2, 0, 1};         
    int team2[] = {5, 5};             
    int team3[] = {1, 6, 7, 2};     

    scores.store(0, 3, team1);
    scores.store(1, 2, team2);
    scores.store(2, 4, team3);

    cout << "Team Score:0 "<< endl;
    scores.display();

    return 0;
}
