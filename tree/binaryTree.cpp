#include <iostream>
#include <cstddef>
#include "binaryTree.h"
using namespace std;

Bst()
{
  root = NULL;
}

~Bst() {}
void Bst::deleteTree(node *actualNode) {}
node *Bst::getRoot() {}
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

  node *newNode = new Node;
  newNode->student = student;
  newNode->rightParent = NULL;
  newNode->leftParent = NULL;

  if (root = NULL)
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
  deleteSearch(student, root);
}

void Bst::deleteSearch(node *&actualNode, Student student)
{
  if (student.getRa() < actualNode->student.getRa())
  {
    deleteSearch(student, actualNode->leftParent);
  }
  else if (student.getRa() > actualNode->student.getRa())
  {
    deleteSearch(student, actualNode->rightParent);
  }
  else
  {
    deleteNode(actualNode);
  }
}

void Bst::deleteNode(node *&actualNode)
{
  node *tempNode = actualNode;

  if (actualNode->leftParent == Null)
  {
    actualNode = actualNode->rightParent;
    delete tempNode;
  }
  else if (actualNode->rightParent == Null)
  {
    actualNode = actualNode->leftParent;
    delete tempNode;
  }
  else
  {
    Student student;
    getParent(student, actualNode);
    actualNode->student = student;
    deleSearch(student, actualNode->rightParent);
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
  while (actualNode != NULL || search == true)
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
    }
  }
}
void Bst::printInPreOrder(node *actualNode) {}
void Bst::printInOrder(node *actualNode) {}
void Bst::printInPosOrder(node *actualNode) {}