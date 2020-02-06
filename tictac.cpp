#include<iostream>
#include<cstdlib>
#include<map>
#include<vector>
#include"board.cpp"

using namespace std;
class tictac {
    public:
        const Board& get_board() const { return board;}
        bool turn_x() const{ return is_x_turn; }
        bool make_move(pair<char\
        , int> attempt){ 
            attempt.first = toupper(attempt.first);
            if (!try_move(attempt)){
                return false;
            }
            if (is_x_turn){
                board.tac[attempt] = 'X';
            } else {
                board.tac[attempt] = 'O';
            }
            is_x_turn = !is_x_turn;
            return true;
        }
        bool in_tie(){
            bool found = false;
            for (map<pair<char, char>, char>::const_iterator cit = board.tac.cbegin(); cit != board.tac.cend(); cit++){
                if (cit->second == '-'){
                    found = true;
                }
            }
            if (found == 0){
                return true;
            }
            return false;
        }
        bool x_win(){ 
            if (board.tac.at(make_pair('A', '0')) == 'X'){ //top left edge
                if (board.tac.at(make_pair('A', '2')) == 'X' && board.tac.at(make_pair('A', '1')) == 'X'){
                    return true;
                }
                if (board.tac.at(make_pair('C', '0')) == 'X' && board.tac.at(make_pair('B', '0')) == 'X'){
                    return true;
                }
            }
            if (board.tac.at(make_pair('C', '2')) == 'X'){ //bottom right edge
                if (board.tac.at(make_pair('A', '2')) == 'X' && board.tac.at(make_pair('B', '2')) == 'X'){
                    return true;
                }
                if (board.tac.at(make_pair('C', '0')) == 'X' && board.tac.at(make_pair('C', '1')) == 'X'){
                    return true;
                }
            }
            if (board.tac.at(make_pair('B', '1')) == 'X'){ // center piece
                if (board.tac.at(make_pair('A', '1')) == 'X' && board.tac.at(make_pair('C', '1')) == 'X'){
                    return true;
                }
                if (board.tac.at(make_pair('B', '2')) == 'X' && board.tac.at(make_pair('B', '0')) == 'X'){
                    return true;
                }                               
            }
            return false;
        } 
        bool o_win(){
            if (board.tac.at(make_pair('A', '0')) == 'O'){ //top left edge
                if (board.tac.at(make_pair('A', '2')) == 'O' && board.tac.at(make_pair('A', '1')) == 'O'){
                    return true;
                }
                if (board.tac.at(make_pair('C', '0')) == 'O' && board.tac.at(make_pair('B', '0')) == 'O'){
                    return true;
                }
            }
            if (board.tac.at(make_pair('C', '2')) == 'O'){ //bottom right edge
                if (board.tac.at(make_pair('A', '2')) == 'O' && board.tac.at(make_pair('B', '2')) == 'O'){
                    return true;
                }
                if (board.tac.at(make_pair('C', '0')) == 'O' && board.tac.at(make_pair('C', '1')) == 'O'){
                    return true;
                }
            }
            if (board.tac.at(make_pair('B', '1')) == 'O'){ // center piece
                if (board.tac.at(make_pair('A', '1')) == 'O' && board.tac.at(make_pair('C', '1')) == 'O'){
                    return true;
                }
                if (board.tac.at(make_pair('B', '2')) == 'O' && board.tac.at(make_pair('B', '0')) == 'O'){
                    return true;
                }                               
            }
            return false;            
        }

    private:
        Board board;
        bool is_x_turn = false;
        bool try_move(pair<char, char> attempt){
            if (board.tac[attempt] != '-'){
                cout << "Already a piece there" << endl;
                return false;
            }
            if (attempt.first != 'A' && attempt.first != 'B' && attempt.first != 'C'){
                cout << "Invalid coordinate" << endl;
                return false;
            }
            if (attempt.second != '0' && attempt.second != '1' && attempt.second != '2'){
                cout << "Invalid coordinate" << endl;
                return false;
            }
            return true;
        };
};