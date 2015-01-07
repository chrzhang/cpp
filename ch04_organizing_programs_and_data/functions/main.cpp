#include <iostream>
#include <stdexcept> // For domain_error
#include <vector>
#include <algorithm> // For sort()
#include <string>
#include <iomanip> // For setprecision()
#include <ios> // For streamsize
#include <istream>

#define MIDTERM_WEIGHT 0.2
#define FINAL_WEIGHT 0.4
#define HW_WEIGHT 0.4

using std::vector;
using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::domain_error;
using std::istream;
using std::streamsize;
using std::setprecision;

/*
Compose a grade given test and homework scores.
*/
double grade(double midterm, double final, double homework) {

    return MIDTERM_WEIGHT * midterm +
           FINAL_WEIGHT * final +
           HW_WEIGHT * homework;

}

/*
Find the median of a vector of doubles.
*/
double median(vector<double> vec) {

    // The vector is copied so that 'sort' won't cause the original vector
    // contents to be changed
    typedef vector<double>::size_type vec_sz;

    vec_sz size = vec.size();
    if (0 == size)
        throw domain_error("median of an empty vector");
    sort(vec.begin(), vec.end());
    vec_sz mid = size / 2;

    return size % 2 == 0 ? (vec[mid] + vec[mid - 1]) / 2 : vec[mid];

}

/*
Overloaded. Compose a grade given test scores and a vector of homework scores.
*/
double grade(double midterm, double final, const vector<double> & hw) {

    // Since the vector hw does not need to be copied within this scope, pass
    // as a reference to avoid the expensive, pass-by-value copying. Handle the
    // possibility of messing with the original value by using a const qualifier
    // to ensure read-only access
    if (hw.empty())
        throw domain_error("student has done no homework");

    // Because hw is const, hw may be any value, even a non-lvalue (a call to a
    // function, i.e. grade(midterm, final, emptyvec());
    return grade(midterm, final, median(hw));

}

/*
Read homework grades from an input stream into a vector.
*/
istream & read_hw(istream & in, vector<double> & hw) {

    // Non-const arguments like in and hw must be lvalues (nontemporary objects)

    // The vector could be filled with rubbish
    hw.clear();

    double x;
    while (in >> x)
        hw.push_back(x);

    // in  fails when reading an EOF or an improper input for a double
    // Reset the error state and disregard additional input after the last grade
    in.clear(); // Now input can continue for the next student

    // Return the stream to allow callers to check the value of
    // read_hw(cin, homework) rather than test cin explicitly after reading
    return in;
}

/*
Get a student's grade.
*/
int main() {

    cout << "Please enter your first name: ";
    string name;
    cin >> name;
    cout << "Hello, " << name << "!" << endl;

    cout << "Please enter your midterm and final exam grades: ";
    double midterm, final;
    cin >> midterm >> final;

    cout << "Enter all your homework grades, followed by EOF: ";

    vector<double> homework;

    read_hw(cin, homework);

    try {
        double final_grade = grade(midterm, final, homework);
        streamsize prec = cout.precision();
        cout << "Your final grade is " << setprecision(3) << final_grade
             << setprecision(prec) << endl;
    } catch (domain_error) {
        cout << endl << "You must enter your grades. Please try again." << endl;
        return 1;
    }

    return 0;

}
