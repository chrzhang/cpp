#include <iostream>
#include <string>
#include <vector>

#define NUM_HWs 3
#define MIDTERM_WEIGHT .2
#define FINAL_WEIGHT .4
#define HW_WEIGHT .4

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::string;

/*
Keep track of grades for several students at once.
*/
int main() {

    // These vectors have a 1-1 correspondence (names[x] has grades[x])
    vector<string> names;
    vector<double> grades;

    string name;

    cout << "Enter student name (or EOF to quit): ";

    while (cin >> name) { // Per student

        names.push_back(name);

        cout << "\tEnter midterm grade: ";
        double midterm;
        if (!(cin >> midterm)) {
            cout << "Invalid input." << endl;
            return -1;
        }

        cout << "\tEnter final grade: ";
        double final;
        if (!(cin >> final)) {
            cout << "Invalid input." << endl;
            return -1;
        }

        double homework_total = 0;
        double homework = 0;

        for (int i = 0; i < NUM_HWs; i++) {
            cout << "\tEnter homework  " << i + 1 << " grade: ";
            if (!(cin >> homework)) {
                cout << "Invalid input." << endl;
                return -1;
            }
            homework_total += homework;
        }

        grades.push_back(MIDTERM_WEIGHT * midterm + FINAL_WEIGHT * final +
                         HW_WEIGHT * (homework_total / NUM_HWs));

        cout << "Enter student name (or EOF to quit): ";
    }

    cout << endl;

    for (auto it = names.begin(); it != names.end(); it++) {

        cout << *it << " Grade: " << grades[it - names.begin()];

        cout << endl;
    }


}
