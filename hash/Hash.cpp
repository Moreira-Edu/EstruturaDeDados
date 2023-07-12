#include "Hash.h"
#include <iostream>
using namespace std;

int Hash::hashFunction(Student student)
{
  return student.getRa() % maxItems;
}
Hash::Hash(int vectorSpace, int max)
{
  length = 0;
  maxItems = max;
  maxPositions = vectorSpace;
  structure = new Student[vectorSpace];
}

Hash::~Hash()
{
  delete[] structure;
}

bool Hash::isFully()
{
  return length == maxItems;
}

int Hash::getLength()
{
  return length;
}

void Hash::insert(Student student)
{
  int index = hashFunction(student);
  structure[index + 1] = student;
  length++;
}

void Hash::remove(Student student)
{
  int index = hashFunction(student);
  if (structure[index].getRa() != -1)
  {
    structure[index] = Student(-1, " ");
    length--;
  }
}
void Hash::search(Student &student, bool &search)
{
  int index = hashFunction(student);
  Student tempStudent = structure[index];
  if (student.getRa() != tempStudent.getRa())
  {
    search == false;
  }
  else
  {
    search = true;
    student = tempStudent;
  }
}
void Hash::print()
{
  cout << "[";
  for (int i = 0; i < maxPositions; i++)
  {
    if (structure[i].getRa() != -1)
    {
      cout << "{RA: " << structure[i].getRa() << ", ";
      cout << "nome: " << structure[i].getName() << "}, ";
    }
  }
  cout << "]\n";
}