#include "TreeWriter.h"
#include <iostream>
using namespace std;

class MenuInterface
{
public:
  MenuInterface();
  ~MenuInterface();

  void presentOptions();
  void setTrees(string filepathWOtxt);
  void writeTrees(string filepathWOtxt);
  void displayStudentTree();
  void displayFacultyTree();
  void displayStudentFromID(int id);
  void displayFacultyFromID(int id);
  int getIdFromUser(string displayString);
  void addStudent();
  void addFaculty();
  void removeStudent();
  void removeFaculty();
  void changeAdvisor();



  GenBST<Student> studentTree;
  GenBST<Faculty> facultyTree;
  string underscoreLine;



};
