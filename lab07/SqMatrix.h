//
// Created by Mali Abramovitch on 24/05/2023.
//

#ifndef LAB07_SQMATRIX_H
#define LAB07_SQMATRIX_H

#include <memory>

class Application {
};

template<typename T, unsigned int N>
class SqMatrix {
    T _arr[N][N];
    std::unique_ptr<Application> _appPtr;
public:
    explicit SqMatrix(Application *app) : _appPtr(std::make_unique<Application>(*app)) {};

    SqMatrix(const SqMatrix &other) {
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                _arr[i][j] = other._arr[i][j];
            }
        }
        // _arr = other._arr;
    }

    SqMatrix(SqMatrix &&other) noexcept: _appPtr(std::make_unique<Application>(*other._appPtr.get())) {
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                _arr[i][j] = other._arr[i][j];
            }
        }
    }

    SqMatrix& operator=(const SqMatrix &other) {
        if (this != &other) {
            for (int i = 0; i < N; ++i) {
                for (int j = 0; j < N; ++j) {
                    _arr[i][j] = other._arr[i][j];
                }
            }
            _appPtr = std::make_unique<Application>(other._appPtr.get());
        }
        return *this;
    }

    SqMatrix& operator=(SqMatrix &&other) noexcept {
        if (this != *other) {
            for (int i = 0; i < N; ++i) {
                for (int j = 0; j < N; ++j) {
                    _arr[i][j] = other._arr[i][j];
                }
            }
            _appPtr = std::move(other._appPtr);
        }
        return *this;
    }

};


#endif //LAB07_SQMATRIX_H
