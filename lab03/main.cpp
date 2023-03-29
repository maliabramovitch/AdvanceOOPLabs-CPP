#include<iostream>
#include<vector>
#include<algorithm>
#include<iterator>
#include<cstdlib>
#include<ostream>
#include<fstream>
#include<array>
#include<map>

using namespace std;


//QU01
int QU01() {
    const int SIZE = 64;
    const double eps = 1e-2;
    vector<double> V;
    srand(time(NULL));
    for (int i = 0; i < SIZE; i++)
        V.push_back(static_cast<double>(rand()) / RAND_MAX);

    //TODO : std::replace_if a vector's coordinate is lower than eps.
    replace_if(V.begin(), V.end(), [eps](double &d) -> bool { return d < eps ? 1 : 0; }, 0);
    ostream_iterator<double> out(cout, " ");
    copy(V.begin(), V.end(), out);
    cout << "\r\n";
    return 0;
}

template<typename MapIt>
void showCommonWords(MapIt begin, MapIt end, const std::size_t n) {
    std::vector<MapIt> wordIters;
    wordIters.reserve(std::distance(begin, end));
    for (auto i = begin; i != end; ++i) wordIters.push_back(i);
    //TODO: std::partial_sort n element in wordIters according to \second\.
    auto l = [](MapIt k1, MapIt k2) -> bool { return k1->second < k2->second; };
    partial_sort(wordIters.begin(), wordIters.begin() + n, wordIters.end(), l);
    for (auto wordIter: wordIters) {
        cout << "{" << wordIter->first << "," << wordIter->second << "} ";
    }
}

const int NSIZE = 16;

class RandVar {
public:
    RandVar() : _val(rand()) {}

    void save(ostream &os) const { os << _val << endl; }

private:
    int _val;
};

int QU03(void) {
    ofstream out_file("output.dat");
    array<RandVar, NSIZE> rands;
    //TODO: apply std::for_each on rands to save all its elements.
    for_each(rands.begin(), rands.end(), [&out_file](RandVar rv){rv.save(out_file);});
    return 0;
}


int main(void) {

    map<std::string, int> m;
    m["w"] = 10;
    m["t"] = 3;
    m["i"] = 2;
    m["a"] = 1;
    showCommonWords(m.begin(), m.end(), 2);
}
