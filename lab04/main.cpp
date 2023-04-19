#include <iostream>
#include <vector>
#include <algorithm>

/*
 * QU01
 */
template<class IterIn, class IterOut>
void keep_it_real(IterIn first, IterIn last, IterOut out) {
    auto l = [](std::pair<IterIn, int> it1, std::pair<IterIn, int> &it2) -> bool {
        return *(it1.first) < *(it2.first);
    };
    std::vector<std::pair<IterIn, int> > s(last - first);
    for (int i = 0; i < s.size(); ++i)
        s[i] = std::make_pair(first + i, i);
    //TODO 1: std::sort s according to the value of the first element within the pair
    std::sort(s.begin(), s.end(), l);
    //TODO 2: copy s into the IterOut instance
    for (std::pair<IterIn, int> p: s) {
        *(out++) = *p.first;
    }
}

/*
 * QU02
 */
void print_modulo(const std::vector<int> &v, std::ostream &os, int m) {
// output v[i] to os if v[i]%m==0 {
    auto l = [&m, &os](int x) {
        if (x % m == 0) os << x << '\n';
    };
    for_each(begin(v), end(v), l);
}


int main() {
    std::vector<int> v = {1, 4, 8, 7, 5, 6, 4};
    for (int n: v) {
        std::cout << n << " ";
    }
    std::cout << std::endl;
    std::vector<int> t(v.size());
    keep_it_real(v.begin(), v.end(), t.begin());
    for (int n: t) {
        std::cout << n << " ";
    }
    std::cout << std::endl;

    std::vector<int> v2 = {1,4,8,7,5,6,4};
    print_modulo(v2, std::cout, 2);
}
