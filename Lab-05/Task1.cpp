#include<iostream>
using namespace std;

int game(int player, int target) {
    int guess;
    cout << "Player " << player << ", enter your guess: ";
    cin >> guess;
    if (guess == target) {
        cout << "Player " << player << " wins the game!" << endl;
        return player;
    } else if (guess < target) {
        cout << "Too low" << endl;
    } else {
        cout << "Too high" << endl;
    }

    if (player == 1) {
        player = 2;
    } else {
        player = 1;
    }
    return game(player, target);
}

int main() {
    srand(time(nullptr)); 
    int target = rand() % 100 + 1; 
    int winner = game(1, target);
    cout << "Congratulations to Player " << winner << "!" << endl;
    return 0;
}
