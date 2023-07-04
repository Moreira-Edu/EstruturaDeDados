#include <iostream>
#include "stack.h"
using namespace std;

stack::stack()
{
  stackLength = 0;
  formation = new ItemType[max_items];
}

stack::~stack()
{
  delete[] formation;
}

bool stack::isFully()
{
  return stackLength == max_items;
}

bool stack::isEmpty()
{
  return stackLength == 0;
}

void stack::insert(ItemType item)
{
  if (isFully())
  {
    cout << "A pilha está cheia!\n";
    cout << "Não é possível inserir este elemento";
  }
  else
  {
    formation[stackLength] = item;
    stackLength++;
  }
}

ItemType stack::remove()
{
  if (isEmpty())
  {
    cout << "A pilha está vazia!\n";
    cout << "Não há elementos para ser removido";
    return 0;
  }
  else
  {
    stackLength--;
    return formation[stackLength];
  }
}

void stack::print()
{
  cout << "Pilha: [";
  for (int i = 0; i < stackLength; i++)
  {
    cout << formation[i] << " ";
  }
  cout << "]\n";
}

int stack::length()
{
  return stackLength;
}