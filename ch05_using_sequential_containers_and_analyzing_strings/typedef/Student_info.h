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
std::vector<Student_info> extract_fails(std::vector<Student_info> &);
std::list<Student_info> extract_fails(std::list<Student_info> &);
void display(const std::vector<Student_info> &);
void sortWrapper(std::vector<Student_info> &);
void sortWrapper(std::list<Student_info> &);
#endif
