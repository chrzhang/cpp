#include <stdexcept>
#include <vector>
#include <algorithm>
#include "grade.h"
#include "median.h"
#include "average.h"
#include "Student_info.h"

#define MIDTERM_WEIGHT .2
#define FINAL_WEIGHT .4
#define HW_WEIGHT .4

using std::domain_error;
using std::vector;

double grade(double midterm, double final, double homework) {

    return MIDTERM_WEIGHT * midterm +
           FINAL_WEIGHT * final +
           HW_WEIGHT * homework;

}

double grade(double midterm, double final, const vector<double> & hw) {

    if (hw.empty ())
        throw domain_error("student has done no homework");

    return grade(midterm, final, median(hw));

}

double grade(const Student_info & s) {

    return grade(s.midterm, s.final, s.homework);

}

double grade_aux(const Student_info & s) {

    try {
        return grade(s);
    } catch (domain_error) {
        return grade(s.midterm, s.final, 0);
    }

}

double average_grade(const Student_info & s) {

    return grade(s.midterm, s.final, average(s.homework));

}

double optimistic_median(const Student_info & s) {

    vector<double> nonzero;
    // remove_copy finds values in s.homework that are != 0 and copies them into
    // nonzero
    remove_copy(s.homework.begin(), s.homework.end(), back_inserter(nonzero),
                0);

    if (nonzero.empty())
        return grade(s.midterm, s.final, 0);
    else
        return grade(s.midterm, s.final, median(nonzero));

}
