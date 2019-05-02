#include "GenBST.h"
#include "Student.h"
#include "Faculty.h"
#include <fstream>
#include <string.h>
#include <stdio.h>
#include <math.h>
#include <algorithm>
using namespace std;

class TreeWriter
{
public:
  TreeWriter();
  ~TreeWriter();

  void writeTreeStudent(string fPath, GenBST<Student>);
  void writeTreeFaculty(string fPath, GenBST<Faculty>);

  GenBST<Faculty> readTreeFaculty(string fpath);
  GenBST<Student> readTreeStudent(string fpath);

  Student studentFromString(string studentLine);
  Faculty facultyFromString(string facultyLine);

  vector<string> splitString(string input, char *delimiter);
};
