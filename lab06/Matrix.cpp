#include <array>

/*
The C++ Programming Language (B.S. 4th Ed.)
*/
template<class T>
class Matrix {
     std::array<int,2> dim;
     T* elem; // pointer to size() elements of type T

public:
     Matrix(int d1, int d2) :dim{d1,d2}, elem{new T[d1*d2]} {}
     int size() const { return dim[0]*dim[1]; }

     Matrix(const Matrix&);             // copy constructor
     Matrix(Matrix&&);                  // move constructor

     Matrix& operator=(const Matrix&);  // copy assignment
     Matrix& operator=(Matrix&&);       // move assignment

     ~Matrix(); // destructor

	 // ...

};