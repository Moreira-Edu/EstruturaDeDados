typedef int ItemType;
const int max_items = 100;
using namespace std;

class stack
{
private:
  int stackLength;
  ItemType* formation;

public:
  stack();
  ~stack();
  bool isEmpty();
  bool isFully();
  void insert(ItemType item);
  ItemType remove();
  void print();
  int length();
};
