#include <iostream>
#include "../student/Student.h"

struct node
{
  Student student;
  node *leftParent;
  node *rightParent;
};

class Bst // binary search tree
{
private:
  node *root;

public:
  Bst();
  ~Bst();
  void deleteTree(node *actualNode);
  node *getRoot();
  bool isFully();
  bool isEmpty();
  void deleteSearch(node *&actualNode, Student student);
  void deleteNode(node *&actualNode);
  void getParent(Student &student, node *tempNode);
  void insertStudent(Student student);
  void removeStudent(Student student);
  void searchStudent(Student &student, bool &search);
  void printInPreOrder(node *actualNode);
  void printInOrder(node *actualNode);
  void printInPosOrder(node *actualNode);
};
