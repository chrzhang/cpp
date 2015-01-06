#include <iomanip> // Defines setprecision (how many precision digits)
#include <ios> // Defines streamsize (represents sizes for IO)
#include <iostream>
#include <string>
#include <vector>
#include <algorithm> // To sort the vector

#define MIDTERM_WEIGHT .2
#define FINAL_WEIGHT .4
#define HW_WEIGHT .4

using std::cin;
using std::cout;
using std::endl;
using std::setprecision;
using std::string;
using std::streamsize;
using std::vector;

typedef vector<double>::size_type vec_sz;

/*
Calculate a student's grade from midterm, final, and homework scores.
*/
int main() {

    cout << "Please enter your first name: ";
    string name;

    cin >> name;
    cout << "Hello, " << name << "!" << endl;

    cout << "Please enter your midterm and final exam grades: ";
    double midterm, final;
    cin >> midterm >> final;

    // String literals separated only by whitespace are automatically catenated
    cout << "Enter all your homework grades,"
            " followed by EOF: ";

    // Find the average of however many homework grades
    // Built-in types have no implicit initial values
    double sum = 0;

    double x;
    vector<double> homework;

    vec_sz size = homework.size();

    while (0 == size) {

        // Attempt to read from cin (fails because no input or input wrong type)
        while (cin >> x) {

            homework.push_back(x); // Append the new homework grade
            size = homework.size();
            sum += x;

        }

        if (0 == size) {
            cout << endl << "You must enter your grades. "
                            "Please try again." << endl;
        }

    }

    sort(homework.begin(), homework.end());

    vec_sz mid = size / 2;
    double median; // Average of two middle #s if even count, else middle
    median = size % 2 == 0 ? // Even or odd # of grades
                (homework[mid] + homework[mid - 1]) / 2 : homework[mid];
    // double average = sum / size;

    streamsize prec = cout.precision(); // Store orig. precision to restore
    cout << "Your final grade is " << setprecision(3)
         << MIDTERM_WEIGHT * midterm + FINAL_WEIGHT * final + HW_WEIGHT * median
         << setprecision(prec) << endl;

    return 0;

}
