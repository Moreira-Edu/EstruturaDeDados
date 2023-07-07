#include <iostream>
#include "dynamicQueue.cpp"
using namespace std;

int main()
{
  dynamicQueue queueObject;
  int option;
  ItemType item;

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
      queueObject.insert(item);
    }

    if (option == 2)
    {
      cout << "Removido: " << queueObject.remove() << "\n";
    }

    if (option == 3)
    {
      queueObject.print();
    }

  } while (option != 0);

  return 0;
}