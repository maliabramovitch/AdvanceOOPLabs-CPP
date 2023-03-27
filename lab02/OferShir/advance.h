#include <iterator>

using namespace std;

template<typename Iter>
void advance(Iter& p, int n) {
	advance_helper( p, n, typename iterator_traits<Iter>::iterator_category{});
}
template<typename Iter>
void advance_helper(Iter& p, int n, input_iterator_tag) {
	if (n>0)
		++p;
	else if (n<0)
		throw std::invalid_argument("Invalid steps argument n"); 
}

template<typename Iter>
void advance_helper(Iter& p, int n, output_iterator_tag) {
	if (n>0)
		++p;
	else if (n<0)
		throw std::invalid_argument("Invalid steps argument n"); 
}

template<typename Iter>
void advance_helper(Iter& p, int n, forward_iterator_tag) {
	if (n>0)
		while (n--) ++p;
	else if (n<0)
		throw std::invalid_argument("Invalid steps argument n"); 
}

template<typename Iter>
void advance_helper(Iter& p, int n, bidirectional_iterator_tag) {
	if (n>0)
		while (n--) ++p;
	else if (n<0)
		while (n++) --p;
}
template<typename Iter>
void advance_helper(Iter& p, int n, random_access_iterator_tag) {
  p+=n;
}
