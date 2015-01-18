#include <iostream>
#include <stdexcept> // For domain_error
#include <vector>
#include <algorithm> // For sort()
#include <string>
#include <iomanip> // For setprecision()
#include <ios> // For streamsize
#include <istream>
#include <map>
#include "grade.h"
#include "Student_info.h"

using namespace std;

/*
Calculate grades for students where grades are entered with
[name] [midterm_score] [final_exam_score] [hw1 score] [hw2 score] ...
followed by any additional students.
*/
int main() {

    vector<Student_info> students;
    Student_info record;
    string::size_type maxlen = 0;

    while (read(cin, record)) {

        maxlen = max(maxlen, record.name.size());
        students.push_back(record);

    }

    sort(students.begin(), students.end(), compare);

    // Map letter grades (char as key) to the # of students with that grade
    map<char, int> stats;
    static const double MAX_GRADE = 100;
    static const double A_CUTOFF = 90;
    static const double B_CUTOFF = 80;
    static const double C_CUTOFF = 70;
    static const double D_CUTOFF = 60;

    for (vector<Student_info>::size_type i = 0; i != students.size(); i++) {

        cout << students[i].name
             << string(maxlen + 1 - students[i].name.size(), ' ');

        try {
            double final_grade = grade(students[i]);
            if (final_grade > MAX_GRADE) {
                cout << "Grade is larger than 100. Invalid. ";
            } else if (final_grade >= A_CUTOFF) {
                stats['A']++;
            } else if (final_grade >= B_CUTOFF) {
                stats['B']++;
            } else if (final_grade >= C_CUTOFF) {
                stats['C']++;
            } else if (final_grade >= D_CUTOFF) {
                stats['D']++;
            } else {
                stats['F']++;
            }
            streamsize prec = cout.precision();
            cout << setprecision(3) << final_grade << setprecision(prec);
        } catch (domain_error e) {
            cout << e.what();
        }

        cout << endl;

    }

    for (map<char, int>::const_iterator it = stats.begin(); it != stats.end();
         it++) {

        cout << it->first << ": " << it->second << endl;

    }

    return 0;

}
