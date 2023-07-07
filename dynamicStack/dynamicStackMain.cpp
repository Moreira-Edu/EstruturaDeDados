#include <iostream>
#include "dynamicStack.cpp"
using namespace std;

int main()
{
  dynamicStack stackObject;
  ItemType item;
  int option;
  do
  {
    cout << "Digite 0 para encerrar o programa: \n";
    cout << "Digite 1 para inserir um elemento: \n";
    cout << "Digite 2 para remover um elemento: \n";
    cout << "Digite 3 para imprimir a pilha: \n";
    cin >> option;

    if (option == 1)
    {
      cout << "Digite o elemento a ser inserido: \n";
      cin >> item;
      stackObject.insert(item);
    }

    if (option == 2)
    {
      cout << "Removido: " << stackObject.remove() << "\n";
    }

    if (option == 3)
    {
      stackObject.print();
    }

  } while (option != 0);

  return 0;
}
