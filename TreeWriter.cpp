#include "TreeWriter.h"
using namespace std;

TreeWriter::TreeWriter()
{
  //nothing in the constructor because this is primarily a method class. No variables to set up
}

TreeWriter::~TreeWriter()
{
  //nothing new, therefore nothing to delete
}

void TreeWriter::writeTreeStudent(string fpath, GenBST<Student> gbst)
{
  //tree and object toString functionality make this easy
  //Basically calling toString on each element in the tree, and adding them together
  ofstream myfile(fpath);
  if(myfile.is_open())
  {
    myfile << gbst.toString();
    myfile.close();
  }

}

void TreeWriter::writeTreeFaculty(string fpath, GenBST<Faculty> gbst)
{
  //tree and object toString functionality make this easy
  //Basically calling toString on each element in the tree, and adding them together
  ofstream myfile(fpath);
  if(myfile.is_open())
  {
    myfile << gbst.toString();
    myfile.close();
  }
}

GenBST<Student> TreeWriter::readTreeStudent(string fpath)
{
  GenBST<Student> output = GenBST<Student>();
  vector<Student> tempStorage;
  ifstream infile(fpath);

  //stores lines before modifying them to faculty

  string line;
  while (getline(infile, line))
  {
    tempStorage.push_back(studentFromString(line));
  }
  //these numbers help create a balanced tree

  int vectorSize = tempStorage.size();
  int halfSize = round(vectorSize / 2.0);

  vector<int> exploredNumbers;

  //iterates over tree by halfs, skipping read numbers

  while(halfSize > 1)
  {
    for(int i = halfSize; i<vectorSize; i+=halfSize)
    {
      if (find(exploredNumbers.begin(), exploredNumbers.end(), i) != exploredNumbers.end())
      {

      }
      else
      {
        exploredNumbers.push_back(i);
        output.insert(tempStorage[i].id, tempStorage[i]);
      }

    }
    halfSize = round(halfSize / 2.0);

  }
  //only covers minimum step size 2. Next loop is step size 1

  for(int i=0; i<vectorSize; i++)
  {
    if (find(exploredNumbers.begin(), exploredNumbers.end(), i) != exploredNumbers.end())
    {
      //checks if this number has been explored already using iterators.
    }
    else
    {
      output.insert(tempStorage[i].id, tempStorage[i]);
    }
  }

  return output;
}

GenBST<Faculty> TreeWriter::readTreeFaculty(string fpath)
{
  GenBST<Faculty> output = GenBST<Faculty>();
  vector<Faculty> tempStorage;
  ifstream infile(fpath);

  //stores lines before modifying them to faculty
  string line;
  while (getline(infile, line))
  {
    tempStorage.push_back(facultyFromString(line));
  }
  vector<int> exploredNumbers;

  //these numbers help create a balanced tree
  int vectorSize = tempStorage.size();
  int halfSize = round(vectorSize / 2.0);

  //iterates over tree by halfs, skipping read numbers
  while(halfSize > 1)
  {
    for(int i = halfSize; i<vectorSize; i+=halfSize)
    {
      if (find(exploredNumbers.begin(), exploredNumbers.end(), i) != exploredNumbers.end())
      {
        //checks if this number has been explored already using iterators.
      }
      else
      {
        exploredNumbers.push_back(i);
        output.insert(tempStorage[i].id, tempStorage[i]);
      }

    }
    halfSize = round(halfSize / 2.0);
    //reduce step size
  }
  //only covers minimum step size 2. Next loop is step size 1
  for(int i=0; i<vectorSize; i++)
  {
    if (find(exploredNumbers.begin(), exploredNumbers.end(), i) != exploredNumbers.end())
    {
    }
    else
    {
      output.insert(tempStorage[i].id, tempStorage[i]);
    }
  }


  return output;
}

Faculty TreeWriter::facultyFromString(string facultyLine)
{
  cout << "Faculty Added: " << facultyLine << endl;
  char d = ',';
  vector<string> splitLine = splitString(facultyLine, &d);

  int id = stoi(splitLine[0]);
  //Special case for when a faculty has no students. Breaks the rest of the code.
  if(splitLine.size() == 6)
  {
    return Faculty(id, splitLine[1], splitLine[3], splitLine[2]);
  }
  //this split cares about only the extra student IDs at the end of the string
  vector<string> strlist(splitLine.begin() + 5, splitLine.end());

  vector<int> tslist;


  //add each int to the outside elements
  for(unsigned int i = 0; i<strlist.size(); i++)
  {
    int num = stoi(strlist[i]);
    tslist.push_back(num);
  }


  return Faculty(tslist, id, splitLine[1], splitLine[3], splitLine[2]);
}

Student TreeWriter::studentFromString(string studentLine)
{

  char d = ',';



  vector<string> splitLine = splitString(studentLine, &d);

  //convert non strings to relavant types
  cout << "Student Added: " << studentLine << endl;
  int id = stoi(splitLine[0]);
  int advisor = stoi(splitLine[5]);
  double gpa = stod(splitLine[4]);

  //returns object based on data
  return Student(id, splitLine[1], advisor, gpa, splitLine[3], splitLine[2]);


}



vector<string> TreeWriter::splitString(string input, char *delimiter)
{
  vector<string> output;

  //turn string into char array
  char p[input.length()];
  for (unsigned int i = 0; i < sizeof(p); i++)
  {
        p[i] = input[i];
  }

  //Gets first token
  char *token = strtok(p, delimiter);

  //uses iterator over the string t split each element
  while (token != NULL)
      {
        string splitToken = "";
        splitToken = token;
        output.push_back(splitToken);
        //increments based on delimiter
        token = strtok(NULL, delimiter);
      }

      return output;

}
