#include "Student_info.h"
#include "median.h"

#define MIDTERM_WEIGHT .2
#define FINAL_WEIGHT .4
#define HW_WEIGHT .4

using std::istream;
using std::vector;

bool compare(const Student_info & x, const Student_info & y) {

    return x.name < y.name;

}

istream & read(istream & is, Student_info & s) {

    is >> s.name;

    read_grades(is, s.final_grade);

    return is;

}

istream & read_grades(istream & in, double & final_grade) {

    if (in) {
        double x;
        final_grade = 0;

        in >> x;
        final_grade += MIDTERM_WEIGHT * x;

        in >> x;
        final_grade += FINAL_WEIGHT * x;

        std::vector<double> homework_grades;
        while (in >> x)
            homework_grades.push_back(x);

        final_grade += HW_WEIGHT * median(homework_grades);

        in.clear();
    }

    return in;

}
