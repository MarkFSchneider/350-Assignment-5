#include "Person.h"
using namespace std;



string Person::toString()
{
  //standard template for toString
  ostringstream oss;
  oss << id << ',' << name << ',' << level << ',' << focus;
  return oss.str();
}

bool Person::operator <(Person gPerson)
{
  return id < gPerson.id;
}

bool Person::operator >(Person lPerson)
{
  return id > lPerson.id;
}
