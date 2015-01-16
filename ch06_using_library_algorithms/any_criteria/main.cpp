#include <iostream>
#include <stdexcept> // For domain_error
#include <vector>
#include <algorithm> // For sort()
#include <string>
#include <iomanip> // For setprecision()
#include <ios> // For streamsize
#include <istream>
#include "grade.h"
#include "Student_info.h"

using namespace std;

/*
Practice separating failing grades from passing ones.
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

    // Pass any criteria of choosing (in this case, pgrade)
    vector<Student_info> fail_students = extract_nots(students, pgrade);

    cout << "Passing students: " << endl;
    for (vector<Student_info>::iterator it = students.begin();
         it != students.end(); it++) {

        cout << it->name << string(maxlen + 1 - it->name.size(), ' ');
        try {
            double final_grade = grade(*it);
            streamsize prec = cout.precision();
            cout << setprecision(3) << final_grade << setprecision(prec);
        } catch (domain_error e) {
            cout << e.what();
        }
        cout << endl;

    }

    cout << "Failing students: " << endl;
    for (vector<Student_info>::iterator it = fail_students.begin();
         it != fail_students.end(); it++) {

        cout << it->name << string(maxlen + 1 - it->name.size(), ' ');
        try {
            double final_grade = grade(*it);
            streamsize prec = cout.precision();
            cout << setprecision(3) << final_grade << setprecision(prec);
        } catch (domain_error e) {
            cout << e.what();
        }
        cout << endl;

    }

    return 0;

}
