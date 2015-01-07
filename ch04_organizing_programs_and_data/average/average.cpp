#include "average.h"
#include <vector>
#include <stdexcept>

using std::vector;
using std::domain_error;

double average(const vector<double> & v) {

    if (v.empty())
        throw domain_error("vector is empty");

    double sum = 0;
    for (auto it = v.begin(); it != v.end(); it++) {

        sum += *it;

    }

    return sum / v.size();

}
