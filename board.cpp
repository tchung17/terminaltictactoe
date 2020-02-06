#include<iostream>
#include<cstdlib>
#include<map>
#include<vector>

using namespace std;

class Board {
    public:
        char tac[3][3];
        Board(){
            for (int i = 0; i < 3; i++){
                for (int j = 0; j < 3; j++){
                    tac[i][j] = '-';
                }
            }
        };
        ~Board(){};
        void display() const{
            for (int i = 0; i < 3; i++){
                for (int j = 0; j < 3; j++){
                    cout << tac[i][j];
                }
                cout << endl;
            }
        }

};