#include <iostream>
#include "Hash.cpp"

using namespace std;

int main()
{

  int vectorSpaces, max, option, ra;
  bool search;
  string name;

  cout << "Digite o tamanho da hash\n";
  cin >> vectorSpaces;

  cout << "Digite o número máximo de elementos\n";
  cin >> max;

  cout << "O fator de carga é: " << (float)max / vectorSpaces << endl;
  Hash hashStudent(vectorSpaces, max);

  do
  {
    cout << "Digite 0 para parar o algorítimo.\n";
    cout << "Digite 1 para inserir um aluno.\n";
    cout << "Digite 2 para remover um aluno.\n";
    cout << "Digite 3 para buscar um aluno.\n";
    cout << "Digite 4 para imprimir a tabela de alunos.\n";
    cin >> option;

    if (option == 1)
    {
      cout << "Informe o RA do aluno:\n";
      cin >> ra;
      cout << "Informe o nome do aluno:\n";
      cin >> name;

      Student student(ra, name);
      hashStudent.insert(student);
    }

    if (option == 2)
    {
      cout << "Informe o RA do aluno:\n";
      cin >> ra;

      Student student(ra, "");
      hashStudent.remove(student);
    }

    if (option == 3)
    {
      cout << "Informe o RA do aluno:\n";
      cin >> ra;
      Student student(ra, "");
      hashStudent.search(student, search);

      search ? cout << "Aluno encontrado:\n{RA: " << student.getRa() << ", "
                    << "nome: " << student.getName() << "}\n"
             : cout << "Aluno não encontrado\n";
    }

    if (option == 4)
    {
      hashStudent.print();
    }
  } while (option != 0);

  return 0;
}