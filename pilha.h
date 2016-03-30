typedef char ItemType;

const int MAX_ITEMS = 100;

class GenericStack
{
 public:
  // Constructor
  GenericStack();

  bool isEmpty() const;
  bool isFull() const;

  void push(ItemType);
  ItemType pop();

  bool VerificaCCP (ItemType item);
  void VerificaPilha ();

 private:
  int top;
  ItemType info[MAX_ITEMS];
};
//Feito por Bruno Kadri e Felipe Godoy 30/03/2016
