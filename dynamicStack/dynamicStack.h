typedef int ItemType;

struct node
{
  ItemType value;
  node *next;
};

class dynamicStack
{
private:
  node *top;

public:
  dynamicStack();
  ~dynamicStack();
  bool isEmpty();
  bool isFully();
  void insert(ItemType item);
  ItemType remove();
  void print();
};
