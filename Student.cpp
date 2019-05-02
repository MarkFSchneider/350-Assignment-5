#include "Student.h"
using namespace std;

Student::Student()
{

}

Student::Student(int sID, string sName, int sAdvisor, double sGPA, string sFocus,  string sLevel)
{
  id = sID;
  name = sName;
  advisor = sAdvisor;
  gpa = sGPA;
  focus = sFocus;
  level = sLevel;
}

Student::~Student()
{

}

string Student::toString()
{
  //creates a string stream, inherits toString from Person Class and adds on student spesific fields.
  ostringstream oss;
  oss << Person::toString() << ',' << gpa << ',' << advisor;
  return oss.str();
}
