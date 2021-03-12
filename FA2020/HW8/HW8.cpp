#include <memory>
#include <iostream>
using std::cout;
using std::endl;
using std::shared_ptr;
using std::make_shared;

class Node {
private:
  int datavalue{0};
  shared_ptr<Node> tail_ptr{nullptr};
public:
  Node() {} Node(int value)
    : datavalue(value) {};

  int value() { return datavalue; };

  bool has_next() {
    if ( tail_ptr == nullptr )
      return false;
    else return true;
  };

  int list_length() {
    if (!has_next()) return 1;
    else
      return 1+tail_ptr->list_length();
  };

  void set_tail( shared_ptr<Node> tail ) {
    tail_ptr = tail;
  };

  void append( shared_ptr<Node> tail) {
    if ( !has_next() ) {
      set_tail(tail);
    }
    else { 
      tail_ptr->append(tail);
    }
  };

  void insert( shared_ptr<Node> tail) {
    if(list_length() == 1) {
      if(datavalue <= tail->value()) {
	tail_ptr = tail;
      }
      else {
	auto
	  newNode = make_shared<Node>(datavalue);
	set_tail(newNode);
	datavalue = tail->value();
      }
    }
    else {
      if (datavalue >= tail->value() || !has_next()) {
	auto
	  newNode = make_shared<Node>(datavalue);
	if(has_next()) {
	  tail_ptr->insert(newNode);
	}
	else {
	  set_tail(newNode);
	}
	datavalue = tail->value();
      }
      else {
	tail_ptr->insert(tail);
      }
    }
  };

  void print() {
    cout << datavalue;
    if (!has_next())
      cout << endl;
    else {
      cout << ",";
      tail_ptr->print();
    }
  };
};

int main() {
  auto
    head = make_shared<Node>(0);
  int data;
  std::cin >> data;
  while (data > 0) {
    auto
      newnode = make_shared<Node>(data);
    head -> insert(newnode);
    head -> print();
    std::cin >> data;
  }
  /*Test Code
  auto
    first = make_shared<Node>(2),
    second = make_shared<Node>(3),
    third = make_shared<Node>(4),
    fourth = make_shared<Node>(5),
    fifth = make_shared<Node>(6),
    sixth = make_shared<Node>(7);

  first->set_tail(second);
  first->print();
  cout << "List length: "
       << first->list_length() << endl;
  first->append(third);
  first->print();
  cout << "List length: "
       << first->list_length() << endl;
  first->append(fifth);
  first->print();
  cout << "List length: "
       << first->list_length() << endl;
  first->append(sixth);
  first->print();
  cout << "List length: "
       << first->list_length() << endl;

  first->insert(fourth);
  first->print();
  cout << "List length: "
       << first->list_length() << endl;
  */
  return 0;
}
