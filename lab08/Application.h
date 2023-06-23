//
// Created by Mali Abramovitch on 31/05/2023.
//

#ifndef LAB08_APPLICATION_H
#define LAB08_APPLICATION_H
#include "Document.h"

class Application {
protected:
    virtual Document* newDocument() =0;
public:
    virtual ~Application() = 0;
    virtual void createDocument() =0;
    virtual Document* openDocument() =0;
};

#endif //LAB08_APPLICATION_H
