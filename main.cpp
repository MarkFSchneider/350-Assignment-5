#include "MenuInterface.h"
using namespace std;

GenBST<Student> makeAndAddTestStudents()
{

  GenBST<Student> testTree = GenBST<Student>();

  Student testStudent = Student(10, "bob", 99);
  Student testStudent2 = Student(14, "stan", 99);
  Student testStudent3 = Student(26, "rick", 99);
  Student testStudent4 = Student(7, "george", 99);
  Student testStudent5 = Student(17, "ricardo", 99);

  testTree.insert(testStudent.id, testStudent);
  testTree.insert(testStudent2.id, testStudent2);
  testTree.insert(testStudent3.id, testStudent3);
  testTree.insert(testStudent4.id, testStudent4);
  testTree.insert(testStudent5.id, testStudent5);

  return testTree;
}

GenBST<Faculty> makeAndAddTestFaculty()
{
  GenBST<Faculty>fTestTree = GenBST<Faculty>();
  Faculty testFaculty = Faculty(99, "Mr.Joseph");
  testFaculty.studentList.push_back(10);
  testFaculty.studentList.push_back(14);
  testFaculty.studentList.push_back(26);
  testFaculty.studentList.push_back(7);
  testFaculty.studentList.push_back(17);

  Faculty testFaculty2 = Faculty(98, "Mr.Stan");
  testFaculty2.studentList.push_back(11);
  testFaculty2.studentList.push_back(15);
  testFaculty2.studentList.push_back(27);
  testFaculty2.studentList.push_back(8);

  fTestTree.insert(testFaculty.id, testFaculty);
  fTestTree.insert(testFaculty2.id, testFaculty2);

  return fTestTree;
}

int main(int argc, char const *argv[])
{

  /*
  BST is working.
  Student class working
  Faculty class working
  Can Write Tree for both classes

  read into Faculty tree
  read into Student tree

  Up Next:
  menu interface

  NON ROLLBACK OPTIONS.
  Print all students + info
  Print all Faculty + info
  Print one student info off of ID
  Print one Faculty info off of ID
  Print faculty info off student ID
  Print Students info off faculty ID

  ROLLBACK FUCNTIONALITY NEEDED
  add new student
  add faculty
  delete student off ID *note, must remove from faculty list
  delete faculty off ID *note, must re-advise students

  PROBABLY NEED ROLLBACK
  Change advisor of student
  remove student from advisor *note, move it to new advisor



  */

  

  MenuInterface interface;

  interface.presentOptions();





}
