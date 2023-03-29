//
// Created by Mali Abramovitch on 27/03/2023.
//

#ifndef LIST_LIST_H
#define LIST_LIST_H

#include <iterator>


template<class T>
class List {
    struct Node {
        Node *prev;
        Node *next;
        T *data;

        Node() : prev(0), next(0), data(0) {};

        Node(Node *p, Node *n, T t) : prev(p), next(n), data(new T(t)) {};

        Node(const Node &n) : prev(n.prev), next(n.next), data(new T(*n.data)) {}

        Node(Node &&n) noexcept: prev(n.prev), next(n.next), data(new T(n.data)) {
            n.prev = 0;
            n.next = 0;
            data = 0;
        }

        ~Node() {
            delete data;
        }

        Node &operator=(const Node &n) {
            if (this == &n) return *this;
            prev = n.prev;
            next = n.next;
            data = new T(*n.data);
            return *this;
        }

        Node &operator=(Node &&n) noexcept {
            if (this == &n) return *this;
            prev = n.prev;
            next = n.next;
            data = n.data;
            n.prev = 0;
            n.prev = 0;
            n.data = 0;
            return *this;
        }
    };

    unsigned int length = 0;
    Node *head;
    Node *tail;

public:
    class Iterator : public std::iterator<std::bidirectional_iterator_tag, T> {
        Node* curser;
    public:
        Iterator()=delete;
        explicit Iterator(Node* n) : curser(n){}

        Iterator & operator=(const List::Iterator &other) {
            if (this != &other) {
                curser = other.curser;
            }
            return *this;
        }

        bool operator==(const List::Iterator &o) {
            return curser->data == o.curser->data;
        }

        bool operator!=(const List::Iterator &o) {
            return curser->data != o.curser->data;;
        }

        T& operator*() {
            return *curser->data;
        }

        T operator*() const{
            return *curser->data;
        }

        T operator->() const{
            return *curser->data;
        }


        T& operator->() {
            return *curser->data;
        }

       Iterator& operator++() {
            return curser->next != end()? curser->next : 0;
        }

      friend Iterator operator++(Iterator& i) {
            return ++i;
        }

       Iterator& operator--() {
            return curser->prev != head()? curser->prev : 0;
        }
    };

    List();
    List(const List<T> &);
    List(const List<T> &&) noexcept ;
    ~List();
    List<T> &operator=(const List<T> &other);
    List<T> &operator=(List<T> &&other) noexcept;

    T operator[](unsigned int i) const;
    T &operator[](unsigned int i);
    T getFirstElement() const;
    T &getFirstElement();
    void addFirst(T &element);
    T getLastElement() const;
    T &getLastElement();
    void addLast(T &element);
    List<T>::Iterator begin();
    List<T>::Iterator end();
    void removeAll(const T &element); // remove all instances of element
    void removeFirst(const T &element); // remove the first instance of element
    void clear();
    friend std::ostream &operator<<(std::ostream &os, const List<T> &l);
};


template<class T>
List<T>::List() {
    head = 0;
    tail = 0;
    length = 0;
}

template<class T>
List<T>::List(const List<T> &other) {
    head = new Node();
    tail = new Node();
    head->next = tail;
    tail->prev = head;
    Node *tmp(head);
    typedef List<T>::Iterator Iter;
    Iter b = other.begin();
    for (; b != other.end(); ++b) {
        tmp = new Node(tmp, tmp->next, new T(*b));
    }
    length = other.length;
}


template<class T>
List<T>::List(const List<T> &&other) noexcept {
    tail = other.tail;
    head = other.head;
    length = other.length;
    other.head = 0;
    other.tail = 0;
    length = 0;
}

template<class T>
List<T>::~List() {
    clear();
    delete head, tail;
}

template<class T>
List<T> &List<T>::operator=(const List<T> &other) {
    if (this != &other) {
        clear();
        Node *tmp = head->next;
        for (List<T>::Iterator it = other.begin(); it < other.end(); ++it) {
            tmp = Node(tmp, tmp->next, *it);
        }
        length = other.length;
    }
    return *this;
}

template<class T>
List<T> &List<T>::operator=(List<T> &&other) noexcept {
    if (this != &other) {
        head = other.head;
        tail = other.tail;
        length = other.length;

        other.head = 0;
        other.tail = 0;
        other.length = 0;
    }
    return *this;
}

template<class T>
T List<T>::operator[](unsigned int index) const {
    if (index < 0 || index >= length) throw std::exception();
    List<T>::Iterator it = begin();
    for (int i = 0; i < index; ++i) {
        ++it;
    }
    return *it;
}

template<class T>
T &List<T>::operator[](unsigned int index) {
    if (index < 0 || index >= length) throw std::exception();
    List<T>::Iterator it = begin();
    for (int i = 0; i < index; ++i) {
        ++it;
    }
    return *it;
}


template<class T>
T List<T>::getFirstElement() const {
    return *head->next->data;
}

template<class T>
T &List<T>::getFirstElement() {
    return *head->next->data;
}

template<class T>
void List<T>::addFirst(T &element) {
    Node *tmp = head->next;
    head->next = new Node(head, tmp, element);
    tmp->prev = head->next;
}

template<class T>
T List<T>::getLastElement() const {
    return tail->prev->data;
}

template<class T>
T &List<T>::getLastElement() {
    return tail->prev->data;
}

template<class T>
void List<T>::addLast(T &element) {
    Node *tmp = tail->prev;
    tail->prev = new Node(tmp, tail, element);
    tmp->next = tail->prev;
}

template<class T>
void List<T>::removeFirst(const T &element) {
    for (Node *tmp = head->next; tmp != tail; tmp = tmp->next) {
        if (*tmp->data == element) {
            Node* tmp2 = tmp->prev;
            tmp2->next = tmp->next;
            tmp->next->prev = tmp2;
            delete tmp;
            return;
        }
    }
}

template<class T>
void List<T>::removeAll(const T &element) {
    for (Node *tmp = head->next; tmp != tail;) {
        if (*tmp->data == element) {
            Node* tmp2 = tmp->prev;
            tmp2->next = tmp->next;
            tmp->next->prev = tmp2;
            tmp2 = tmp;
            tmp = tmp->next;
            delete tmp2;
        } else {
            tmp = tmp->next;
        }
    }
}


template<class T>
List<T>::Iterator List<T>::begin() {
    Iterator b = Iterator(head->next);
    return b;
}

template<class T>
List<T>::Iterator List<T>::end() {
    Iterator e = Iterator(tail);
    return e;
}

template<class T>
void List<T>::clear() {
    for (Node* tmp = head->next; tmp != tail;) {
        Node* tmp2 = tmp;
        tmp = tmp->next;
        delete tmp2;
    }
    head->next=tail;
    tail->prev=head;
}


template<class T>
std::ostream &operator<<(std::ostream &os, const List<T> &l) {
    typedef typename List<T>::Iterator Iter;
    for (Iter it = l.begin(); it != l.end() ; ++it) {
        os << *it << ' -> ';
    }
    os << std::endl;
}

#endif //LIST_LIST_H
