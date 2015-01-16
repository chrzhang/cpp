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

bool pgrade(const Student_info & s) {

    return !fgrade(s);

}

vector<Student_info> extract_fails1(vector<Student_info> & students) {

    vector<Student_info> fail;
    // Copy all failing grades into fail with remove_copy_if (predicate needed)
    remove_copy_if(students.begin(), students.end(), back_inserter(fail),
                   pgrade);
    // Since remove_if removes elements for failing grades by marking fails as
    // free space and filling so that the result is a contiguous chunk of passes
    // that have either done nothing or overwritten fail-grade elements
    // The end of the contiguous block of passes is returned so erasing from the
    // result of remove_if until end wipes out the fail values
    students.erase(remove_if(students.begin(), students.end(), fgrade), students.end());

    return fail;

}

vector<Student_info> extract_nots(vector<Student_info> & students,
                                    bool criteria(const Student_info &)) {

    // stable_partition reorders only on basis of partition, not shuffling the
    // existing alphabetical order
    vector<Student_info>::iterator iter = // iter  points to end of pass block
        stable_partition(students.begin(), students.end(), criteria);
    // Construct fail from the beginning of the fails given by iter to the end
    vector<Student_info> fail(iter, students.end());
    // Remove the fails from the argument which includes only the passes
    students.erase(iter, students.end());
    // erase is not an algorithm and is a member function of the container
    // <algorithm> works on container elements, not the containers themselves

    return fail;

}

void display(const vector<Student_info> & students) {

    // const_iterator specifies a read-only iterator
    for (vector<Student_info>::const_iterator iter = students.begin();
         iter != students.end(); iter++) {

        cout << iter-> name << endl;

    }
}
