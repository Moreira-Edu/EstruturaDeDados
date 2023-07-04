#include <iostream>
#include "stack.cpp"
using namespace std;
int main()
{
  stack stackObject;
  ItemType item;
  int option;

  cout << "Programa gerador de pilha\n";
  do
  {
    cout << "Digite 0 para encerrar o programa: \n";
    cout << "Digite 1 para inserir um elemento: \n";
    cout << "Digite 2 para remover um elemento: \n";
    cout << "Digite 3 para imprimir a pilha: \n";
    cout << "Digite 4 para imprimir o tamanho da pilha: \n";
    cin>> option;

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

    if (option == 4)
    {
      cout<< "Tamanho da pilha: "<< stackObject.length()<< "\n";
    }

  } while (option != 0);

  return 0;
}