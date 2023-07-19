#include "../student/Student.cpp"
using namespace std;

class Hash
{
private:
  int hashFunction(Student student);
  int maxItems, maxPositions, length;
  Student *structure;

public:
  Hash(int vectorSpace, int max);
  ~Hash();
  bool isFully();
  int getLength();
  void insert(Student student);
  void remove(Student student);
  void search(Student &student, bool &search);
  void print();
};
