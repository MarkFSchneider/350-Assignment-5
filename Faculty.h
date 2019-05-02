#ifndef Included_Person_H
#define Included_Person_H
#include "Person.h"
#endif
#include <vector>
#include <iterator>
using namespace std;

class Faculty: public Person
{
public:
  Faculty();
  Faculty(int tID, string tName, string tFocus = "No Department",  string tLevel = "Unassigned Faculty");
  Faculty(vector<int> tsList, int tID, string tName, string tFocus = "No Department",  string tLevel = "Unassigned");
  ~Faculty();

  string toString();

  vector<int> studentList;
};
