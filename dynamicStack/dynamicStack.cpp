#include <iostream>
#include <cstddef>
#include "dynamicStack.h"

using namespace std;

dynamicStack::dynamicStack()
{
  top = NULL;
}

dynamicStack::~dynamicStack()
{
  node *tempNode;

  while (top != NULL)
  {
    tempNode = top;
    top = top->next;

    delete tempNode;
  }
}

bool dynamicStack::isEmpty()
{
  return top == NULL;
}

bool dynamicStack::isFully()
{
  node *newNode;

  try
  {
    node *newNode = new node;
    delete newNode;
    return false;
  }
  catch (bad_alloc exception)
  {
    return true;
  }
}

void dynamicStack::insert(ItemType item)
{
  if (isFully())
  {
    cout << "A pilha está cheia!\nNão foi possível inserir este elemento\n";
    return;
  }
  node *newNode = new node;
  newNode->value = item;
  newNode->next = top;
  top = newNode;
}

ItemType dynamicStack::remove()
{
  if (isEmpty())
  {
    cout << "A pilha está vazia\nNão foi possível remover nenhum elemento\n";
    return 0;
  }

  node *tempNode;
  tempNode = top;

  ItemType item = top->value;
  top = top->next;

  delete tempNode;
  return item;
}

void dynamicStack::print()
{
  node *tempNode = top;

  while (tempNode != NULL)
  {
    cout << tempNode->value;
    if (tempNode->next != NULL)
    {
      cout << " -> ";
    }
    tempNode = tempNode->next;
  }
  cout << "\n";
}