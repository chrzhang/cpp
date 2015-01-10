#include <iostream>
#include <stdexcept> // For domain_error
#include <vector>
#include <list>
#include <algorithm> // For sort()
#include <string>
#include <iomanip> // For setprecision()
#include <ios> // For streamsize
#include <istream>
#include "grade.h"
#include "Student_info.h"

using std::vector;
using std::list;
using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::domain_error;
using std::istream;
using std::streamsize;
using std::setprecision;
using std::sort;
using std::max;

// Change to a list (it also works)
typedef list<Student_info> container;

/*
Be able to alternate between list and vector implementations by changing
the typedef declaration above.
Calculate grades for students where grades are entered with
[name] [midterm_score] [final_exam_score] [hw1 score] [hw2 score] ...
followed by any additional students.
*/
int main() {

    container students;
    Student_info record;
    string::size_type maxlen = 0;

    while (read(cin, record)) {

        maxlen = max(maxlen, record.name.size());
        students.push_back(record);

    }

    sortWrapper(students);

    extract_fails(students); // Overloaded to accept either list or vector

    for (auto it = students.begin(); it != students.end(); it++) {

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
