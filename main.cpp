#include<iostream>
#include<cstdlib>
#include<map>
#include<vector>
#include"tictac.cpp"
#include<string>

using namespace std;
int main(){
    tictac tic;
    bool game_over = false;
    while (!game_over){
        if (tic.turn_x()){
            cout << "X's turn" << endl;
        } else {
            cout << "O's turn" << endl;
        }
        if (tic.x_win()){
            cout << "X wins!" << endl;
            game_over = true;
            break;
        } else if (tic.o_win()){
            cout << "O wins!" << endl;
            game_over = true;
            break;
        } else if (tic.in_tie()){
            cout << "Tie!" << endl;
            game_over = true;
            break;
        }

        string choice;
        cout << "Next Command: " << endl;
        cin >> choice;
        if (choice.length() != 1){
            cerr << "Command must be d, m, q, or ?" << endl;

        } else {
        switch (choice[0]){
        case 'd': case 'D': //display board
            tic.get_board().display();
            break;
        case 'm': case 'M': {//make a move
            string argument;
            cin >> argument;
            if (argument.length() != 2) {
                cout << "Coordinate must be 2 characters long" << endl;
                break;
            }
            if (isalpha(argument[0]) == 0 || isdigit(argument[1]) == 0) {
                cout << "Coordinate format incorrect" << endl;
                break;
            } else {
                const pair<char, int> attempt1 = make_pair(argument[0], argument[1]);
                tic.make_move(attempt1);
            }
            tic.get_board().display();
            break;
        }
        case 'q': case 'Q': //quit the game
            game_over = true;
            break;
        case '?': //show commands
            break;
        default:
            cout << "Unrecognized command" << endl;
        }
        }

    }
    return 0;
}