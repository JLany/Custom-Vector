#include "MYVector.h"
#include <iostream>
#include <stdexcept>
using namespace std;

int main()
{
    MYVector<int> vec(5);
    cout << "(1): " << vec << "\n";
    try {
        vec.insert(vec.begin(), 10);
    }
    catch (out_of_range e) {
        cout << "exception: " << e.what() << "\n";
    }

    cout << "(2): " << vec << "\n";
}
