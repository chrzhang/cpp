#include "Student_info.h"
#include "grade.h"
#include <iostream>
#include <list>
#include <vector>

#define FAIL_CUTOFF 60

using std::istream;
using std::vector;
using std::cout;
using std::endl;
using std::list;

bool compare(const Student_info & x, const Student_info & y) {

    return x.name < y.name;

}

istream & read(istream & is, Student_info & s) {

    is >> s.name >> s.midterm >> s.final;

    read_hw(is, s.homework);

    return is;

}

istream & read_hw(istream & in, vector<double> & hw) {

    if (in) {
        hw.clear();

        double x;
        while (in >> x)
            hw.push_back(x);

        in.clear();
    }

    return in;

}

bool fgrade(const Student_info & s) {

    return grade(s) < FAIL_CUTOFF;

}

vector<Student_info> extract_fails1(vector<Student_info> & students) {

    // Needs twice the space as the original vector of student to store
    // intermediate pass and fail vectors
    vector<Student_info> pass, fail;

    for (vector<Student_info>::size_type i = 0; i != students.size(); i++) {

        if (fgrade(students[i]))
            fail.push_back(students[i]);
        else
            pass.push_back(students[i]);
    }

    students = pass;

    return fail;

}

vector<Student_info> extract_fails2(vector<Student_info> & students) {

    // Remove any failing students from the vector as they are encountered
    vector<Student_info> fail;
    vector<Student_info>::size_type i = 0;

    while (i != students.size()) {

        if (fgrade(students[i])) {
            fail.push_back(students[i]);
            students.erase(students.begin() + i);
        } else
            i++;

    }

    return fail;

}

vector<Student_info> extract_fails3(vector<Student_info> & students) {

    vector<Student_info> fail;
    vector<Student_info>::iterator iter = students.begin();
    while (iter != students.end()) {

        if (fgrade(*iter)) {
            fail.push_back(*iter);
            // erase() returns the following element
            iter = students.erase(iter);
            // erase() invalidates all iterators after point erased
        } else
            ++iter;

    }

    return fail;

}

list<Student_info> extract_fails4(list<Student_info> & students) {

    list<Student_info> fail;
    list<Student_info>::iterator iter = students.begin();

    while (iter != students.end()) {

        if (fgrade(*iter)) {
            fail.push_back(*iter);
            iter = students.erase(iter);
        } else
            iter++;

    }

    return fail;

}

void remove_fails(vector<Student_info> & students) {

    size_t amountPassed = 0;
    size_t totalSize = students.size();
    size_t i = 0;
    while (i < totalSize) {

        if (!fgrade(students[i])) {
            amountPassed++;
            students.insert(students.begin(), students[i]);
        }

        ++i;

    }

    students.resize(amountPassed);

}


void display(const vector<Student_info> & students) {

    // const_iterator specifies a read-only iterator
    for (vector<Student_info>::const_iterator iter = students.begin();
         iter != students.end(); iter++) {

        cout << iter-> name << endl;

    }
}
