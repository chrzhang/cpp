#ifndef GUARD_Student_info
#define GUARD_Student_info

#include <iostream>
#include <string>
#include <vector>

struct Student_info {
    std::string name;
    double midterm, final;
    std::vector<double> homework;
};

bool compare(const Student_info &, const Student_info &);
std::istream & read(std::istream &, Student_info &);
std::istream & read_hw(std::istream &, std::vector<double> &);
bool did_all_hw(const Student_info &);
double median_analysis(const std::vector<Student_info> &);
double average_analysis(const std::vector<Student_info> &);
double optimistic_median_analysis(const std::vector<Student_info> &);
std::vector<double> all_analysis(const std::vector<Student_info> &);
void write_analysis(std::ostream &, const std::string &,
                    double (const std::vector<Student_info> &),
                    const std::vector<Student_info> &,
                    const std::vector<Student_info> &);
void write_all_analysis(std::ostream &,
                        std::vector<double> (const std::vector<Student_info> &),
                        const std::vector<Student_info> &,
                        const std::vector<Student_info> &);
std::vector<Student_info> extract_incompletes(std::vector<Student_info> &);

#endif
