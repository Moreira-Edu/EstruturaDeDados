#include "Student.h"
using namespace std;

Student::Student()
{
  ra = -1;
  name = " ";
}
Student::Student(int r, string n)
{
  ra = r;
  name = n;
}
Student::~Student()
{
}
int Student::getRa()
{
  return ra;
}

string Student::getName()
{
  return name;
}