//
// Created by Mali Abramovitch on 31/05/2023.
//

#ifndef LAB08_MYPOWERPOINT_H
#define LAB08_MYPOWERPOINT_H
#include "Document.h"

class MyPowerPoint : public Document{
public:
    ~MyPowerPoint() override {

    }

    Document *open() override {
        return nullptr;
    }

    void close() override {

    }

    void save() override {

    }
};



#endif //LAB08_MYPOWERPOINT_H
