#include "MYVector.h"
#include <iostream>
#include <stdexcept>
#include <algorithm>
using namespace std;

int main()
{
    MYVector<int> vec(4);

    cout << "(1): " << vec << "\n";

    try {
        vec.push_back(10);
        vec.push_back(10);
        vec.insert(vec.begin() + 1, 5);
    }
    catch (out_of_range e) {
        cout << "exception: " << e.what() << "\n";
    }

    cout << "(2): " << vec << "\n";
}
