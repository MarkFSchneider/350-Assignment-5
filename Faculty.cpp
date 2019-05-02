#include "Faculty.h"
using namespace std;

Faculty::Faculty()
{

}

Faculty::Faculty(int tID, string tName, string tFocus,  string tLevel)
{
  id = tID;
  name = tName;
  focus = tFocus;
  level = tLevel;

}

Faculty::Faculty(vector<int> tsList, int tID, string tName, string tFocus,  string tLevel)
{
  id = tID;
  name = tName;
  focus = tFocus;
  level = tLevel;
  studentList = tsList;

}

Faculty::~Faculty()
{

}

string Faculty::toString()
{
  //creates a string stream, inherits toString from Person Class and adds on faculty spesific fields.
  //more complex because the student list must be iterated over
  string lStudents;
  if (!studentList.empty())
  {
    ostringstream vts;
    // Convert all but the last element to avoid a trailing ","
    copy(studentList.begin(), studentList.end()-1, ostream_iterator<int>(vts, ","));
    // Now add the last element with no delimiter
    vts << studentList.back();
    lStudents = vts.str();
  }

  ostringstream oss;
  oss << Person::toString() << ',' << "Amount of students mentored: " << studentList.size() << ',' << lStudents;
  return oss.str();
}
