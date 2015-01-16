#include <vector>
#include "grade.h"
#include "median.h"
#include "Student_info.h"
#include <iostream>
#include <stdexcept>

#define MIDTERM_WEIGHT .2
#define FINAL_WEIGHT .4
#define HW_WEIGHT .4

using std::vector;
using std::cout;
using std::endl;
using std::domain_error;

double grade(double midterm, double final, double homework) {

    return MIDTERM_WEIGHT * midterm +
           FINAL_WEIGHT * final +
           HW_WEIGHT * homework;

}

double grade(double midterm, double final, const vector<double> & hw) {

    if (hw.empty()) {
        throw domain_error("student did no homework");
    }

    return grade(midterm, final, median(hw));

}

double grade(const Student_info & s) {

    return grade(s.midterm, s.final, s.homework);

}
