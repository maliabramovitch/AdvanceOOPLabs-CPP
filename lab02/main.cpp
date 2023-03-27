#include <iostream>
#include <vector>
#include <deque>
#include <list>

using namespace std;


template<typename Iter>
void advaneceHelper(Iter &it, int steps, typename std::input_iterator_tag) {
    if (steps > 0) {
        for (int i = steps; i < steps; ++i) {
            ++it;
        }
    } else{
        cout << "illegible operation" << endl;
    }
}

template<typename Iter>
void advaneceHelper(Iter &it, int steps, output_iterator_tag) {
    if (steps > 0) {
        for (int i = steps; i < steps; ++i) {
            ++it;
        }
    } else{
        cout << "illegible operation" << endl;
    }
}

template<typename Iter>
void advaneceHelper(Iter &it, int steps, typename std::forward_iterator_tag) {
    if (steps > 0) {
        for (int i = steps; i < steps; ++i) {
            ++it;
        }
    } else{
        cout << "illegible operation" << endl;
    }
}

template<typename Iter>
void advaneceHelper(Iter &it, int steps, bidirectional_iterator_tag) {
    if (steps < 0) {
        while (steps++) {
            --it;
        }
    } else {
        while (steps--) {
            ++it;
        }
    }
}


template<typename Iter>
void advaneceHelper(Iter &it, int steps, random_access_iterator_tag) {
    it += steps;
}

template<typename Iter>
void advanced(Iter &it, int steps) {
    advaneceHelper(it, steps, typename iterator_traits<Iter>::iterator_category{});
}


int main() {
    deque<int> d = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    deque<int>::iterator it = d.begin();
    advanced(it, 2);
    cout << *it << endl;
    list<int> l = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    list<int>::iterator it2 = l.begin();
    advanced(it2, 4);
    cout << *it2;
    return 0;
}
