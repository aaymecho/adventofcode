#include <iostream>
#include <fstream>
#include <string>

using namespace std;

//A-X = rock 1 (lose)
//B-Y = paper 2 (draw)
//C-Z = scissor 3 (win)
//6 win
//3 draw

int main() {
    fstream my_file;
    my_file.open("day_two_list.txt", ios::in);
    int points = 0;
    string line_value;

    while (getline(my_file, line_value)) {
        char opp = line_value[0];
        char self = line_value[2];

        switch(self) {
            case ('X'):
                if (opp == 'A') points += 3;
                if (opp == 'B') points += 1;
                if (opp == 'C') points += 2;
                break;

             case ('Y'):
                points += 3; //draw condition
                if (opp == 'A') points += 1;
                if (opp == 'B') points += 2;
                if (opp == 'C') points += 3;
                break;

            case ('Z'):
                points += 6; //win condition
                if (opp == 'A') points += 2;
                if (opp == 'B') points += 3;
                if (opp == 'C') points += 1;
                break;
            default:
                break;
        }
    }
    cout << points;
}

