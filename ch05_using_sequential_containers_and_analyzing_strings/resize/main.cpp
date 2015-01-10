#include <iostream>
#include <random>
#include <stdexcept> // For domain_error
#include <vector>
#include <list>
#include <algorithm> // For sort()
#include <string>
#include <iomanip> // For setprecision()
#include <ios> // For streamsize
#include <istream>
#include <fstream>
#include "grade.h"
#include <iterator> // For begin() and end()
#include "Student_info.h"
#include <ctime> // To measure performance

using std::vector;
using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::domain_error;
using std::istream;
using std::streamsize;
using std::setprecision;
using std::sort;
using std::max;
using std::ifstream;
using std::list;
using std::begin;
using std::end;
using std::rand;
using std::default_random_engine;
using std::uniform_int_distribution;
using std::ofstream;
using std::clock;

/*
Compare performance of extracting (removing) from a list by erasing versus
moving to the front and resizing a vector.
Calculate grades for students where grades are entered with
[name] [midterm_score] [final_exam_score] [hw1 score] [hw2 score] ...
followed by any additional students.
*/
int main() {

    cout << "Creating sample file." << endl;
    ofstream f;
    f.open("input.txt");

    cout << "Enter sample size: ";
    int n = 0;
    cin >> n;

    default_random_engine generator;
    uniform_int_distribution<int> distribution(1, 100);

    for (int i = 0; i < n; i++) {

        f << "Foo";

        for (int j = 0; j < 5; j++) // Generate scores
            f << " " << distribution(generator);

        f << endl;

    }

    f.close();

    vector<Student_info> students;
    Student_info record;
    string::size_type maxlen = 0;

    ifstream myfile("input.txt");
    if (!myfile.is_open()) {
        cout << "Unable to open file" << endl;
        return -1;
    }
    while (read(myfile, record)) {

        maxlen = max(maxlen, record.name.size());
        students.push_back(record);

    }
    myfile.close();

    sort(students.begin(), students.end(), compare);

    vector<Student_info> students2 = students;

    cout << "Extracting fails with erase()." << endl;
    clock_t begin = clock();
    extract_fails3(students); // With erase()
    clock_t end = clock();
    double elapsed = double(end - begin) / CLOCKS_PER_SEC;
    cout << "Done. Elapsed " << elapsed << endl;
    cout << "Extracting fails with moving and resizing." << endl;
    begin = clock();
    remove_fails(students2); // With moving to front and resizing
    end = clock();
    elapsed = double(end - begin) / CLOCKS_PER_SEC;
    cout << "Done. Elapsed " << elapsed << endl;

    return 0;

}
