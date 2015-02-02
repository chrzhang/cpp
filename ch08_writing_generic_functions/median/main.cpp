#include <iostream>
#include "median.h"
#include <vector>

using namespace std;

int main() {

    vector<int> vi;
    for (int i = 0; i < 5; i++) {

        cout << i << endl;
        vi.push_back(i);

    }

    int m = median(vi);
    cout << "median = " << m << endl;

    return 0;

}
