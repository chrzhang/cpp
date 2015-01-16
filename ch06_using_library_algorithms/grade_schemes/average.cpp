#include "average.h"
#include <vector>
#include <numeric>

double average(const std::vector<double> & v) {

    // accumulate adds all in v into sum initialized to 0.0
    return accumulate(v.begin(), v.end(), 0.0) / v.size();

}
