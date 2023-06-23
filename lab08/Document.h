//
// Created by Mali Abramovitch on 31/05/2023.
//

#ifndef LAB08_DOCUMENT_H
#define LAB08_DOCUMENT_H

class Document {
public:
    virtual ~Document() = 0;
    virtual Document* open() = 0;
    virtual void close() = 0;
    virtual void save() = 0;
};
#endif //LAB08_DOCUMENT_H
