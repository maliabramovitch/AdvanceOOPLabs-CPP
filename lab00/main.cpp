#include <iostream>
#include "rational.h"
#include <iomanip>
#include <fstream>
#include <iterator>
#include <algorithm>
#include <sstream>
#include <vector>

using namespace std;

void reversePrint(char *fileName) {
    ifstream file(fileName);
    string txt;
    vector<string> v;
    while (file >> txt) v.push_back(txt);
    std::ostream_iterator<string> out_it(std::cout, " ");
    unique_copy(v.rbegin(), v.rend(), out_it);
}

int main(int argc, char **argv) {
/**
 * rational testing
 */
    rational *r1 = new rational(2, 4);
    rational *r2 = new rational(2, 3);
    string str = "1/2";
    rational *r3 = new rational(str);
    rational *r4 = new rational(4, 1);
    cout << *r3;
    cout << *r1;
    cout << *r2;
    (*r1) /= (*r2);
    cout << *r1;
    (*r2) -= (*r1);
    cout << *r2;
    double d = *r4 * **r3;
    cout << d << endl;
    cout << boolalpha << (*r1 < *r2) << endl;
    delete r2;
    delete r1;
    delete r3;
    delete r4;
    try {
        rational *r5 = new rational(1, 0);
    }
    catch (...) {
        cout << "DevisionByZero" << endl;
    }
/**
 * reversePrint
 */
    reversePrint(argv[1]);
/**
 *
 */
    return 0;
}

