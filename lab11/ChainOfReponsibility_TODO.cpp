// The approach of the five-year-old.
// From "Thinking in C++, Volume 2", by Bruce Eckel & Chuck Allison.

#include <iostream>
#include <vector>
#include <memory>
using namespace std;

enum Answer { NO, YES };

class GimmeStrategy {
public:
  virtual Answer canIHave() = 0;
  virtual ~GimmeStrategy() {}
};

class AskMom : public GimmeStrategy {
public:
  Answer canIHave() {
    cout << "Mama, Can I have this?" << endl;
    return NO;
  }
};

class AskDad : public GimmeStrategy {
public:
  Answer canIHave() {
    cout << "Papa, I really need this!" << endl;
    return NO;
  }
};

class AskGrandpa : public GimmeStrategy {
public:
  Answer canIHave() {
    cout << "What's up, Grandpa?" << endl;
    return NO;
  }
};

class AskGrandma : public GimmeStrategy {
public:
  Answer canIHave() {
    cout << "Grandma, I really love you!" << endl;
    return YES;
  }
};

class Gimme : public GimmeStrategy {
  //TODO: define this class as a container of GimmeStrategy with a default c'tor inserting the 4 concrete strategies: {AskDad, AskMom, AskGrandpa, AskGrandma}
    std::vector<shared_ptr<GimmeStrategy>> gimme;
public:
    Gimme() {
        gimme.push_back(make_shared<AskMom>());
        gimme.push_back(make_shared<AskDad>());
        gimme.push_back(make_shared<AskGrandpa>());
        gimme.push_back(make_shared<AskGrandma>());
    }
  Answer canIHave() override{
      for (auto &ask:gimme) {
          if (ask->canIHave() == YES) {
              return YES;
          }
      }
      return NO;
  }
  
};

int main(void) {
  Gimme chain;
  chain.canIHave();
  return 0;
} 
