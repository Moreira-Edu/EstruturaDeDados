#include <iostream>
#include <cstddef>
#include "binaryTree.h"

using namespace std;

Bst::Bst()
{
  root = NULL;
}

Bst::~Bst()
{
  deleteTree(root);
}

void Bst::deleteTree(node *actualNode)
{
  if (actualNode != NULL)
  {
    deleteTree(actualNode->leftParent);
    deleteTree(actualNode->rightParent);
    delete actualNode;
  }
}

node *Bst::getRoot()
{
  return root;
}

bool Bst::isFully()
{
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

bool Bst::isEmpty()
{
  return root == NULL;
}

void Bst::insertStudent(Student student)
{
  if (isFully())
  {
    cout << "Não foi possível inserir este elemento!\n";
    return;
  }

  node *newNode = new node;
  newNode->student = student;
  newNode->rightParent = NULL;
  newNode->leftParent = NULL;

  if (root == NULL)
  {
    root = newNode;
  }
  else
  {
    node *tempNode = root;
    while (tempNode != NULL)
    {
      if (student.getRa() < tempNode->student.getRa())
      {
        if (tempNode->leftParent == NULL)
        {
          tempNode->leftParent = newNode;
          break;
        }
        else
        {
          tempNode = tempNode->leftParent;
        }
      }
      else
      {
        if (tempNode->rightParent == NULL)
        {
          tempNode->rightParent = newNode;
          break;
        }
        else
        {
          tempNode = tempNode->rightParent;
        }
      }
    }
  }
}

void Bst::removeStudent(Student student)
{
  cout << "Aluno" << student.getName() << " deletado!";
  deleteSearch(root, student);
}

void Bst::deleteSearch(node *&actualNode, Student student)
{
  if (student.getRa() < actualNode->student.getRa())
  {
    deleteSearch(actualNode->leftParent, student);
  }
  else if (student.getRa() > actualNode->student.getRa())
  {
    deleteSearch(actualNode->rightParent, student);
  }
  else
  {
    deleteNode(actualNode);
  }
}

void Bst::deleteNode(node *&actualNode)
{
  node *tempNode = actualNode;

  if (actualNode->leftParent == NULL)
  {
    actualNode = actualNode->rightParent;
    delete tempNode;
  }
  else if (actualNode->rightParent == NULL)
  {
    actualNode = actualNode->leftParent;
    delete tempNode;
  }
  else
  {
    Student parentStudent;
    getParent(parentStudent, actualNode);
    actualNode->student = parentStudent;
    deleteSearch(actualNode->rightParent, parentStudent);
  }
}
void Bst::getParent(Student &student, node *tempNode)
{
  tempNode = tempNode->rightParent;

  while (tempNode->leftParent != NULL)
  {
    tempNode = tempNode->leftParent;
  }

  student = tempNode->student;
}

void Bst::searchStudent(Student &student, bool &search)
{
  search = false;
  node *actualNode = root;
  while (actualNode != NULL)
  {
    if (student.getRa() < actualNode->student.getRa())
    {
      actualNode = actualNode->leftParent;
    }
    else if (student.getRa() > actualNode->student.getRa())
    {
      actualNode = actualNode->rightParent;
    }
    else
    {
      student = actualNode->student;
      search = true;
      break;
    }
  }
}
void Bst::printInPreOrder(node *actualNode)
{
  if (actualNode != NULL)
  {
    cout << "{nome: " << actualNode->student.getName();
    cout << ", RA: " << actualNode->student.getRa() << "}\n";

    printInPreOrder(actualNode->leftParent);
    printInPreOrder(actualNode->rightParent);
  }
}

void Bst::printInOrder(node *actualNode)
{
  if (actualNode != NULL)
  {
    printInOrder(actualNode->leftParent);

    cout << "{nome: " << actualNode->student.getName();
    cout << ", RA: " << actualNode->student.getRa() << "}\n";

    printInOrder(actualNode->rightParent);
  }
}
void Bst::printInPosOrder(node *actualNode)
{
  if (actualNode != NULL)
  {
    printInPosOrder(actualNode->leftParent);
    printInPosOrder(actualNode->rightParent);

    cout << "{nome: " << actualNode->student.getName();
    cout << ", RA: " << actualNode->student.getRa() << "}\n";
  }
}