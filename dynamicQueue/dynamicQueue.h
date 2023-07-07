typedef int ItemType;

struct node
{
  ItemType value;
  node *next;
};

class dynamicQueue
{
private:
  node *first;
  node *last;

public:
  dynamicQueue();
  ~dynamicQueue();
  bool isEmpty();
  bool isFully();
  void insert(ItemType item);
  ItemType remove();
  void print();
};
