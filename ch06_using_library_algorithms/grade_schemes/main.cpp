#include <iostream>
#include <vector>
#include <string>
#include "grade.h"
#include "Student_info.h"

using std::vector;
using std::cout;
using std::cin;
using std::endl;
using std::string;

/*
Compare grades according to different grading schemes.
Calculate grades for students where grades are entered with
[name] [midterm_score] [final_exam_score] [hw1 score] [hw2 score] ...
followed by any additional students.
*/
int main() {

    // Store students based on whether they did ALL the homework
    vector<Student_info> did, didnt;
    Student_info student;

    while (read(cin, student)) {

        if (did_all_hw(student))
            did.push_back(student);
        else
            didnt.push_back(student);

    }

    if (did.empty()) { // empty() sometimes more efficient than testing size
        cout << "No student did all the homework!" << endl;
        return 1;
    }

    if (didnt.empty()) {
       cout << "Every student did all the homework!" << endl;
       return 1;
    }

    // Analyze them scores
    // Use the median, treating the assignments that weren't turned in as 0
    write_analysis(cout, "median", median_analysis, did, didnt);
    // Use the average, treating the assignments that weren't turned in as 0
    write_analysis(cout, "average", average_analysis, did, didnt);
    // use the median, but discount stuff the students never submitted
    write_analysis(cout, "median of homework turned in",
                   optimistic_median_analysis, did, didnt);

    write_all_analysis(cout, all_analysis, did, didnt);

    return 0;

}
