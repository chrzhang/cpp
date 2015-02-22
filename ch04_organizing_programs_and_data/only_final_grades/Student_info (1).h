#ifndef GUARD_Student_info
#define GUARD_Student_info

#include <iostream>
#include <string>
#include <vector>

struct Student_info {
    std::string name;
    double final_grade;
};

bool compare(const Student_info &, const Student_info &);
std::istream & read(std::istream &, Student_info &);
std::istream & read_grades(std::istream &, double &);

#endif
