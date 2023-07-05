typedef int ItemType;
const int maxItems = 5;

class queue
{
private:
  int first, last;
  ItemType *structure;

public:
  queue();
  ~queue();
  bool isEmpty();
  bool isFully();
  void insert(ItemType item);
  ItemType remove();
  void print();
};
