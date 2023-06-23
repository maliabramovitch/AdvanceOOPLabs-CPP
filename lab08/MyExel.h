//
// Created by Mali Abramovitch on 31/05/2023.
//

#ifndef LAB08_MYEXEL_H
#define LAB08_MYEXEL_H

#include <string>
#include "Document.h"

class MyExel : public Document {
public:
    ~MyExel() override = default;

    Document *open() override {}

    void close() override {}

    void save() override {}

};


#endif //LAB08_MYEXEL_H
