#include <iostream>
#include <iterator>
#include <memory>
#include <fstream>
#include <deque>
using namespace std;

void goo (const char* iname, const char* oname) {
/*   auto_ptr<fstream> ifile(new fstream(iname , std::ios::in));
   auto_ptr<fstream> ofile(new fstream(oname , std::ios::out));
   deque<char> dc;
   istream_iterator<char> r_it(*ifile);
   ostream_iterator<char> w_it(*ofile);
   while (r_it != istream_iterator<char>() )
      dc.push_front(*r_it++);
   copy(dc.begin(),dc.end(),w_it);*/

    shared_ptr<fstream> file(new fstream(iname , std::ios::in));
    if (!*file.get()) {
        cout << "file was not opened!\n" << endl;
        exit(-1);
    }
    deque<char> dc;
    istream_iterator<char> r_it(*file);
    while (r_it != istream_iterator<char>() )
        dc.push_front(*r_it++);
    file.reset(new fstream(oname , std::ios::out));
    if (!*file.get()) {
        cout << "file was not opened!\n" << endl;
        exit(-1);
    }
    ostream_iterator<char> w_it(*file);
    copy(dc.begin(),dc.end(),w_it);
}

/*int main(int argc, char** argv) {
  if (argc < 3) {
     cerr << "REQUIRED: ifile name followed by ofile name.\n";
    return -1;
  }
  goo(argv[1],argv[2]);
  return 0;
}*/
