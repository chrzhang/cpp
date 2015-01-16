#include "Student_info.h"
#include "grade.h"
#include "median.h"
#include <iterator>
#include <algorithm>
#include <iostream>
#include <string>

using std::istream;
using std::ostream;
using std::vector;
using std::back_inserter;
using std::endl;
using std::string;

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


bool did_all_hw(const Student_info & s) {

    // Check if any grades are incompletes (as 0)
    return ((find(s.homework.begin(), s.homework.end(), 0))
            == s.homework.end());

}

double median_analysis(const vector<Student_info> & students) {

    vector<double> grades;

    // transform applies grade_aux to each element in students and puts the
    // result into the container starting at the back of grades
    transform(students.begin(), students.end(), back_inserter(grades),
              grade_aux);

    return median(grades);

}

double average_analysis(const vector<Student_info> & students) {

    vector<double> grades;

    transform(students.begin(), students.end(), back_inserter(grades),
              average_grade);

    return median(grades);

}

double optimistic_median_analysis(const vector<Student_info> & students) {

    vector<double> grades;

    transform(students.begin(), students.end(), back_inserter(grades),
              optimistic_median);

    return median(grades);

}

vector<double> all_analysis(const vector<Student_info> & students) {

    vector<double> ret;

    vector<double> grades;
    transform(students.begin(), students.end(), back_inserter(grades), grade_aux);
    ret.push_back(median(grades));

    grades.clear();
    transform(students.begin(), students.end(), back_inserter(grades), average_grade);
    ret.push_back(median(grades));

    grades.clear();
    transform(students.begin(), students.end(), back_inserter(grades), optimistic_median);
    ret.push_back(median(grades));

    return ret;

}

void write_analysis(ostream & out, const string & name,
                    double analysis(const vector<Student_info> &),
                    const vector<Student_info> & did,
                    const vector<Student_info> & didnt) {

    // out - stream to output info
    // name - name of analysis
    // analysis - function to use for analysis
    // did and didnt - two arguments to be analyzed
    out << name << ": median(did) = " << analysis(did)
        << ", median(didnt) = " << analysis(didnt) << endl;

}

void write_all_analysis(ostream & out, vector<double>
                        analysis(const vector<Student_info> &),
                        const vector<Student_info> & did,
                        const vector<Student_info> & didnt) {

    vector<double> resDid = analysis(did);
    vector<double> resDidnt = analysis(didnt);
    out << "median" << ": median(did) = " << resDid[0] << ", median(didnt) = "
        << resDidnt[0] << endl;
    out << "average" << ": median(did) = " << resDid[1] << ", median(didnt) = "
        << resDidnt[1] << endl;
    out << "median of homework turned in" << ": median(did) = " << resDid[2]
        << ", median(didnt) = " << resDidnt[2] << endl;

}
