#include "Student_info.h"
#include "grade.h"
#include <iostream>
#include <list>
#include <vector>
#include <algorithm>

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

vector<Student_info> extract_fails(vector<Student_info> & students) {

    // Use read-only iterators instead of indexing
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

list<Student_info> extract_fails(list<Student_info> & students) {

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

void display(const vector<Student_info> & students) {

    // const_iterator specifies a read-only iterator
    for (vector<Student_info>::const_iterator iter = students.begin();
         iter != students.end(); iter++) {

        cout << iter-> name << endl;

    }
}

void sortWrapper(vector<Student_info> & students) { // Sort vector

    sort(students.begin(), students.end(), compare);

}

void sortWrapper(list<Student_info> & students) { // Sort list

    students.sort(compare);

}
