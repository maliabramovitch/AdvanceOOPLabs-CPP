//
// Created by Mali Abramovitch on 31/05/2023.
//

#ifndef LAB08_SINGLETONE_H
#define LAB08_SINGLETONE_H

#include <memory>

class SingleTone {
    static std::unique_ptr<SingleTone> ins;

    SingleTone() = default;

public:
    static SingleTone &getInstance();

    SingleTone(const SingleTone &) = delete;

    SingleTone(SingleTone &&) = delete;

    SingleTone &operator=(const SingleTone &) = delete;

    SingleTone &operator=(SingleTone &&) = delete;
};

SingleTone &SingleTone::getInstance() {
    if (ins) {
        ins = std::unique_ptr<SingleTone>(new SingleTone());
    }
    return *ins;
}

#endif //LAB08_SINGLETONE_H
