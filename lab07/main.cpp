#include <iostream>
#include "SqMatrix.h"

int main() {
    SqMatrix<int, 3> sq1(new Application);
    SqMatrix<int, 3> sq2(sq1);
    SqMatrix<int , 3> sq3 = std::move(sq2);
    return 0;
}
