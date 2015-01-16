#ifndef GUARD_Student_info
#define GUARD_Student_info

#include <iostream>
#include <string>
#include <vector>
#include <list>

struct Student_info {
    std::string name;
    double midterm, final;
    std::vector<double> homework;
};

bool compare(const Student_info &, const Student_info &);
std::istream & read(std::istream &, Student_info &);
std::istream & read_hw(std::istream &, std::vector<double> &);
bool fgrade(const Student_info & s);
bool pgrade(const Student_info & s);
std::vector<Student_info> extract_fails1(std::vector<Student_info> &);
std::vector<Student_info> extract_fails2(std::vector<Student_info> &);
void display(const std::vector<Student_info> &);

#endif
