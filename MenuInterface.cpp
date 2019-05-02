#include "MenuInterface.h"
using namespace std;

MenuInterface::MenuInterface()
{
  //this file is where most of the user input, error handling, and method merging takes place.
  setTrees("ztable");
  underscoreLine = "________________";
}

MenuInterface::~MenuInterface()
{
  //Writes the tree back when the object falls out of scope
  writeTrees("ztable");
}

void MenuInterface::presentOptions()
{
  string input;
  int ans = 0;
  while(ans < 1 || ans > 14)
  {

  cout << underscoreLine << endl << endl
  << " 1. Print all students and their information (sorted by ascending id #)" << endl
  << " 2. Print all faculty and their information (sorted by ascending id #)" << endl
  << " 3. Find and display student information given the students id" << endl
  << " 4. Find and display faculty information given the faculty id" << endl
  << " 5. Given a student’s id, print the name and info of their faculty advisor" << endl
  << " 6. Given a faculty id, print ALL the names and info of his/her advisees." << endl
  << " 7. Add a new student" << endl
  << " 8. Delete a student given the id" << endl
  << " 9. Add a new faculty member" << endl
  << "10. Delete a faculty member given the id." << endl
  << "11. Change a student’s advisor given the student id and the new faculty id." << endl
  << "12. Remove an advisee from a faculty member given the ids" << endl
  << "13. Rollback" << endl
  << "14. Exit" << endl
  << "Option: ";

  cin >> input;
  cout << endl;
  try
  {
    ans = stoi(input);
  }
  catch(...)
  {
    cout << "enter a valid number" << endl << endl;
  }

}

switch (ans)
{
  case 1:
  displayStudentTree();
  break;

  case 2:
  displayFacultyTree();
  break;

  case 3:
  try
  {
  ans = getIdFromUser("Student ID: ");
  displayStudentFromID(ans);
  }
  catch(const char* errorMessage)
  {
    cout << errorMessage << endl;
    presentOptions();
  }

  break;

  case 4:
  try
  {
  ans = getIdFromUser("Faculty ID: ");
  displayFacultyFromID(ans);
  }
  catch(char* errorMessage)
  {
    cout << errorMessage << endl;
    presentOptions();
  }
  break;

  case 5:
  try
  {
    ans = getIdFromUser("Student ID: ");
    int adv = studentTree.getNode(ans)->advisor;
    cout << facultyTree.getNode(adv)->toString() << endl;
    presentOptions();
  }
  catch(const char* errorMessage)
  {
    cout << errorMessage << endl;
    presentOptions();
  }
  break;

  case 6:
  try
  {
    ans = getIdFromUser("Faculty ID: ");
    vector<int> slist = facultyTree.getNode(ans)->studentList;
    for(unsigned int i=0; i<slist.size(); i++)
    {
      cout << studentTree.getNode(slist[i])->toString() << endl;
    }
    presentOptions();
  }
  catch(const char* errorMessage)
  {
    cout << errorMessage << endl;
    presentOptions();
  }
  break;

  case 7:
  try
  {
    addStudent();
    presentOptions();
  }
  catch(const char* errorMessage)
  {
    cout << errorMessage << endl;
    presentOptions();
  }
  break;

  case 8:
    try
    {
      removeStudent();
      presentOptions();
    }
    catch(const char* errorMessage)
    {
      cout << errorMessage;
      presentOptions();
    }
  break;

  case 9:
  try
  {
    addFaculty();
    presentOptions();
  }
  catch(const char* errorMessage)
  {
    cout << errorMessage << endl;
    presentOptions();
  }
  break;

  case 10:
  try
  {
    removeFaculty();
    presentOptions();
  }
  catch(const char* errorMessage)
  {
    cout << errorMessage;
    presentOptions();
  }
  break;

  case 11:

  try
  {
    changeAdvisor();
    presentOptions();
  }
  catch(const char* errorMessage)
  {
    cout << errorMessage;
    presentOptions();
  }
  break;

  case 12:
  try
  {
    changeAdvisor();
    presentOptions();
  }
  catch(const char* errorMessage)
  {
    cout << errorMessage;
    presentOptions();
  }
  break;

  case 13:
  presentOptions();
  break;
  
  case 14:
  break;


}
}

void MenuInterface::setTrees(string filepathWOtxt)
{
  //attempst to read trees. If both exist, add both, if neither, create both, if 1, throw error.
  TreeWriter readWrite = TreeWriter();

  string fps;
  string fpf;

  string student = "Student.txt";
  string faculty = "Faculty.txt";

  //create parallel student and faculty filepaths
  fps.append(filepathWOtxt);
  fpf.append(filepathWOtxt);

  fps.append(student);
  fpf.append(faculty);
//check if open
  ifstream stFile(fps);
  ifstream faFile(fpf);

  if(stFile.good() && faFile.good())
  {
    //invoke read tree
    cout << "Files Loaded." << endl;
    studentTree = readWrite.readTreeStudent(fps);
    cout << "Student Database Read" << endl;
    facultyTree = readWrite.readTreeFaculty(fpf);
    cout << "Faculty Database Read" << endl;
  }
  else if(!stFile.good() && !faFile.good())
  {
    //invoke create
    cout << "No files found. Fresh start." << endl;
    studentTree = GenBST<Student>();
    facultyTree = GenBST<Faculty>();
    cout << "Database set" << endl;
  }
  else
  {
    cout << "Missing only one file" << endl;
    throw "missing only one file";
  }

}

void MenuInterface::writeTrees(string filepathWOtxt)
{
  //calls during deconstructor, for when the program exits.
  TreeWriter readWrite = TreeWriter();

  string fps;
  string fpf;

  string student = "Student.txt";
  string faculty = "Faculty.txt";

  fps.append(filepathWOtxt);
  fpf.append(filepathWOtxt);

  fps.append(student);
  fpf.append(faculty);

  readWrite.writeTreeStudent(fps, studentTree);
  readWrite.writeTreeFaculty(fpf, facultyTree);
}

void MenuInterface::displayStudentTree()
{
  cout << "Students: " << endl;
  cout << studentTree.toString();
  presentOptions();
}

void MenuInterface::displayFacultyTree()
{
  cout << "Faculty: " << endl;
  cout << facultyTree.toString();
  presentOptions();
}

void MenuInterface::displayStudentFromID(int id)
{
  cout << "Student Info: " << endl;
  try
  {
  cout << studentTree.getNode(id)->toString() << endl;
  }
  catch(const char* errorMessage)
  {
    throw errorMessage;
  }
  presentOptions();
}

void MenuInterface::displayFacultyFromID(int id)
{
  cout << "Faculty Info: " << endl;
  try
  {
  cout << facultyTree.getNode(id)->toString() << endl;
  }
  catch(char* errorMessage)
  {
    cout << errorMessage << endl;
  }
  presentOptions();
}

int MenuInterface::getIdFromUser(string displayString)
{
  //Actually Gets an int while displaying a message, but its most common use in the program is to get an ID
  cout << displayString;
  int ans;
  string input;
  cin >> input;
  cout << endl;
  try
  {
    ans = stoi(input);
    return ans;
  }
  catch(...)
  {
    throw "enter a valid number";

  }

}

void MenuInterface::addStudent()
{
  int id;
  string name;
  int advisor;
  string gpaTest;
  double gpa;
  string focus;
  string level;
try
{
  //try to get each Variable
  cin.clear();
  id = getIdFromUser("Student ID: ");
  if(studentTree.contains(id))
  {
    throw "Student ID already in use";
  }

  cin.clear();
  advisor = getIdFromUser("Advisor ID: ");
  if(!facultyTree.contains(advisor))
  {
    throw "Faculty ID does not exist";
  }

  cin.clear();
  cout << "____Personal Information____" << endl;
  getline(cin,name);
  //Skips a line here for some reason, extra getLine fixes it.


  cin.clear();
  cout << "Name: ";
  getline(cin,name);
  cout << endl;

  cin.clear();
  cout << "Major: ";
  getline(cin,focus);
  cout << endl;

  cin.clear();
  cout << "Year: ";
  getline(cin,level);
  cout << endl;

  cin.clear();
  cout << "GPA: ";
  cin >> gpaTest;
  cout << endl;
  try
  {
    gpa = stod(gpaTest);
  }
  catch(...)
  {
    throw "Invalid GPA";
  }
  //if it passes all errors, make a student
  studentTree.insert(id, Student(id,name,advisor,gpa,focus,level));
  cout << name << " added successfully with ID " << id << endl;
  facultyTree.getNode(advisor)->studentList.push_back(id);
  cout << "Added student to faculty list" << endl;
}
catch(const char* errorMessage)
{
  throw errorMessage;
}

}

void MenuInterface::addFaculty()
{
  int id;
  string name;
  string focus;
  string level;

  try
  {
    //Get all information
    cin.clear();
    id = getIdFromUser("Faculty ID: ");

    cin.clear();
    cout << "____Personal Information____" << endl;
    getline(cin,name);
    //Skips a line here for some reason, extra getLine fixes it.

    cin.clear();
    cout << "Name: ";
    getline(cin,name);
    cout << endl;

    cin.clear();
    cout << "Department: ";
    getline(cin,focus);
    cout << endl;

    cin.clear();
    cout << "Level: ";
    getline(cin,level);
    cout << endl;


    //builds faculty from info.
    facultyTree.insert(id, Faculty(id,name,focus,level));
    cout << name << " with ID " << id << " added to system" << endl;

  }
  catch(const char* errorMessage)
  {
    throw errorMessage;
  }

}

void MenuInterface::removeStudent()
{
  //error checking if student exists, then deletes it from advisors list and from tree
  try
  {
  int id = getIdFromUser("Student ID: ");
  if(!studentTree.contains(id))
  {
    throw "No student with that ID";
  }
  vector<int>* includedList = &facultyTree.getNode(studentTree.getNode(id)->advisor)->studentList;
  vector<int>::iterator position = find(includedList->begin(), includedList->end(), id);
  if (position != includedList->end())
  {
    includedList->erase(position);
  }
  else
  {
    throw "Student Advisor and Faculty Advisees have a discrepency.";
  }

  studentTree.deleteNode(id);
  cout << "Student Deleted" << endl;
  }
  catch(const char* errorMessage)
  {
    throw errorMessage;
  }
  catch(...)
  {
    throw "unknown error in removing student";
  }
}

void MenuInterface::removeFaculty()
{
  //error checking if faculty exists, then deletes it and switches adivsee list
  try
  {
    int id = getIdFromUser("Faculty ID: ");
    int tid = getIdFromUser("Transfer ID: ");

    if(!facultyTree.contains(id) || !facultyTree.contains(tid))
    {
      throw "One or more faculty do not exist";
    }

    vector<int>* transferFacultyList = &facultyTree.getNode(tid)->studentList;
    vector<int>* deleteFacultyList = &facultyTree.getNode(id)->studentList;

    //adds old faculty on back of new faculty`
    transferFacultyList->insert(transferFacultyList->end(), deleteFacultyList->begin(), deleteFacultyList->end());

    for(unsigned int i = 0; i<deleteFacultyList->size(); i++)
    {
      try
      {
        //changes ID on each student to new advisor
        studentTree.getNode(deleteFacultyList->at(i))->advisor = tid;
      }
      catch(const char* errorMessage)
      {
        throw errorMessage;
      }
    }
    //finally can delete
    facultyTree.deleteNode(id);


  }
  catch(const char* errorMessage)
  {
    throw errorMessage;
  }
}

void MenuInterface::changeAdvisor()
{
  int stID = getIdFromUser("Student to Change: ");
  int faID = getIdFromUser("Faculty Destination: ");

  if(!studentTree.contains(stID) || !facultyTree.contains(faID))
  {
    throw "Faculty and/or student does not exist";
  }

  try
  {
    //deletes student from old advisors list
    vector<int>* includedList = &facultyTree.getNode(studentTree.getNode(stID)->advisor)->studentList;
    vector<int>::iterator position = find(includedList->begin(), includedList->end(), stID);
    if (position != includedList->end())
    {
      includedList->erase(position);
    }
    else
    {
      throw "Student Advisor and Faculty Advisees have a discrepency.";
    }

    //Add student to new faculty
    facultyTree.getNode(faID)->studentList.push_back(stID);

    studentTree.getNode(stID)->advisor = faID;
  }
  catch(const char* errorMessage)
  {
    throw errorMessage;
  }



  //1. Remove student from old 2. Change Student advisor number 3. change faculty Advisee
}
