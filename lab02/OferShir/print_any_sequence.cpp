#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector> 
template<typename Iter>
void print(Iter first, Iter last, const char* nm = "", const char* sep = "\n", std::ostream& os = std::cout) {
  if(nm != 0 && *nm != '\0')
    os << nm << ": " << sep;
  typedef typename std::iterator_traits<Iter>::value_type T;
  //using S = decltype(*first); /* dirty trick that works as well */
  std::copy(first, last, std::ostream_iterator<T>(os, sep));
  os << std::endl;
}

int main(void) {
  char c('A');
  std::vector<char> v;
  for (int i=0; i<20; i++)
    v.push_back(c++);
  print(v.begin(),v.end(),"v");
  return 0;
}
