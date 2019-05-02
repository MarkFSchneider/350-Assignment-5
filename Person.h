#include <iostream>
#include <sstream>
using namespace std;

class Person
{
public:
  virtual string toString();
  bool operator < (Person gPerson);
  bool operator > (Person lPerson);
  bool operator == (Person ePerson);

  int id;
  string name;
  string level;
  string focus;
  //student focus is Major
  //Faculty focus is Department

};
