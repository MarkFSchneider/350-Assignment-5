#ifndef Included_Person_H
#define Included_Person_H
#include "Person.h"
#endif
using namespace std;

class Student: public Person
{
public:
  Student();
  Student(int sID, string sName, int sAdvisor, double sGPA = -1, string sFocus = "Undeclared",  string sLevel = "Unassigned Year");
  ~Student();

  string toString();

  int advisor;
  double gpa;


};
