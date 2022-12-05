#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;
//two sections
//1st half 2nd half
//A = 65 --> 27 (sub 38)
//a = 97 --> 1 (sub 96)

//finds char value (restructures values)
int string_value(string x) {
    int score = 0;
    for (auto character : x) {
        if (int(character) >= 65 && int(character) <= 90) score+= int(character) - 38;
        else if(int(character) >= 97 && int(character) <=122) score+= int(character) - 96;
    }
    return score;
}

//places similar characters into string (part 1)
string find_similar(string s) {
    string value = "";
    for (int i=0; i<s.length()/2; i++) {
        for (int j=s.length()/2; j<s.length(); j++) {
            if (s[i] == s[j] && s[i] != '!' && s[j] && int(value[0]) != int(s[i])) { 
                value.push_back(s[j]);
                s[j] = '!';
                s[i] = '!';
            }
        }
    }
    return value;
}

//finds similar chars between strings
string compare_strings(string x, string y) {
    string value = "";
    for (int i=0; i<x.length(); i++) {
        for (int j=0; j<y.length(); j++) {
            if (x[i] == y[j] && x[i] != '!' && y[j] && int(value[0]) != int(x[i])) { 
                value.push_back(x[i]);
                x[i] = '!';
                y[j] = '!';
            }
        }
    }
    return value;
}



int main() {
    fstream my_file;
    my_file.open("day_three_list.txt", ios::in);
    //my_file.open("test.txt", ios::in);
    string line_value;
    int total = 0;

    //Part 1 Solution
    // int i = 1;
    // while (getline(my_file, line_value)) {
    //     total += string_value(find_similar(line_value));
    //     cout << i << ")" <<find_similar(line_value) << " Value:" << string_value(find_similar(line_value)) << endl;
    //     i++;
    // }
    //cout << "Calculated Total: " <<total;

    //every 3 lines is a group
    //badges = identical letter in group
    //score = sum of all badges

    //Part 2 solutions
    int i = 2;
    vector<string> lines;
    while (getline(my_file, line_value)) {
        lines.push_back(line_value);
    }

    for (int i=2; i<=lines.size(); i+=3) {
        string test_one = compare_strings(lines[i-2], lines[i-1]);
        total += string_value(compare_strings(test_one, lines[i]));
    }
    cout << total;
}