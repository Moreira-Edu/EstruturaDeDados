#include <iostream>
#include <cstddef>
#include "dynamicQueue.h"
using namespace std;

dynamicQueue::dynamicQueue()
{
  first = NULL;
  last = NULL;
}

dynamicQueue::~dynamicQueue()
{
  node *tempNode;

  while (first != NULL)
  {
    tempNode = first;
    first = first->next;
    delete tempNode;
  }
}

bool dynamicQueue::isEmpty()
{
  return first == NULL;
}

bool dynamicQueue::isFully()
{
  try
  {
    node *tempNode;
    tempNode = new node;
    delete tempNode;
    return false;
  }
  catch (bad_alloc exception)
  {
    return true;
  }
}

void dynamicQueue::insert(ItemType item)
{
  if (isFully())
  {
    cout << "A fila está cheia!\nNão foi possível inserir este elemento\n";
    return;
  }

  node *newNode = new node;
  newNode->value = item;
  newNode->next = NULL;

  if (first == NULL)
  {
    first = newNode;
  }
  else
  {
    last->next = newNode;
  }

  last = newNode;
}

ItemType dynamicQueue::remove()
{
  if (isEmpty())
  {
    cout << "A fila está vazia!\nNão há elemento a ser removido";
    return 0;
  }

  node *tempNode = first;
  ItemType item = first->value;
  first = first->next;

  if (first == NULL)
  {
    last = NULL;
  }
  delete tempNode;

  return item;
}

void dynamicQueue::print()
{
  node *tempNode = first;

  while (tempNode != NULL)
  {
    cout << tempNode->value;
    tempNode = tempNode->next;
    if (tempNode != NULL)
    {
      cout << " -> ";
    }
  }

  cout << "\n";
}