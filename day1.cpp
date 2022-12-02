#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    fstream my_file;
    my_file.open("day_one_list.txt", ios::in);
    int current=0, lead=0, second=0, third=0;
    string line_value;
    while (getline(my_file, line_value)) {
        if (line_value.empty()) {
            if (current > second && current < lead) {
                third = second;
                second  = current;
            } else if (current > lead) {
                third = second;
                second = lead;
            } else if (current > third && current < second) {
                third = current;
            } 
            lead = max(current, lead);
            current = 0;
        } else {
            current += stoi(line_value);
        }
    }
    cout << "First: " << lead << " Second: " << second << " Third: " << third <<" Sum of Top 4: " << lead + second + third << endl;
}