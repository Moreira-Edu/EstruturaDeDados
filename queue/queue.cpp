#include <iostream>
#include "queue.h"
using namespace std;

queue::queue()
{
  first = 0;
  last = 0;
  structure = new ItemType[maxItems];
}

queue::~queue()
{
  delete[] structure;
}

bool queue::isEmpty()
{
  return first == last;
}

bool queue::isFully()
{
  return last - first == maxItems;
}

void queue::insert(ItemType item)
{
  if (isFully())
  {
    cout << "A fila está cheia!\nNão é possível inserir o elemento.\n";
    return;
  }
  structure[last % maxItems] = item;
  last++;
}

ItemType queue::remove()
{
  if (isEmpty())
  {
    cout << "A fila está vazia!\nNenhum elemento foi removido\n";
    return 0;
  }
  first++;
  return structure[(first - 1) % maxItems];
}

void queue::print()
{
  cout << "Fila: [";
  for (int i = first; i < last; i++)
  {
    cout << " " << structure[i % maxItems] << " ";
  }
  cout << "]\n";
}
