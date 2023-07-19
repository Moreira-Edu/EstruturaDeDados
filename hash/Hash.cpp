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
  if (isFully())
  {
    cout << "A tabela está cheia!\nImpossível adicionar novos alunos\n";
    return;
  }
  int index = hashFunction(student);
  while (structure[index].getRa() > 0)
  {
    index = (index + 1) % maxPositions;
  }

  structure[index] = student;
  length++;
}

void Hash::remove(Student student)
{
  int index = hashFunction(student);
  bool found = false;
  while (structure[index].getRa() != 1)
  {
    if (structure[index].getRa() == student.getRa())
    {
      cout << "Aluno removido!\n";
      structure[index] = Student(-2, " ");
      length--;
      found = true;
      break;
    }
    index = (index + 1) % maxPositions;
  }
  if (!found)
    cout << "Aluno não encontrado!\n";
}

void Hash::search(Student &student, bool &search)
{
  search = false;

  int index = hashFunction(student);
  while (structure[index].getRa() != -1)
  {
    if (structure[index].getRa() == student.getRa())
    {
      search = true;
      student = structure[index];
      break;
    }
    index = (index + 1) % maxPositions;
  }
}

void Hash::print()
{
  cout << "[";
  for (int i = 0; i < maxPositions; i++)
  {
    if (structure[i].getRa() > 0)
    {
      cout << "{RA: " << structure[i].getRa() << ", ";
      cout << "nome: " << structure[i].getName() << "}, ";
    }
  }
  cout << "]\n";
}