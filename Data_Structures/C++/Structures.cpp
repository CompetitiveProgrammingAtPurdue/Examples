#include <iostream>
#include <list>   //http://www.cplusplus.com/reference/list/list/
#include <vector> //http://www.cplusplus.com/reference/vector/vector/
#include <queue>  //http://www.cplusplus.com/reference/queue/priority_queue/

using namespace std;

class block {
  public:
  int value;
  int priority;
  block(int value, int priority) {
    this->priority = priority;
    this->value = value;
  }
};

struct Compare {
  bool operator()(block & x, block & y) {
    return x.priority < y.priority;
  }
};

int main() {
  //Create a list by specifying a type.
  list<int> a;
  //Push an item to the back or front of the list.
  a.push_back(2);
  a.push_front(0);
  //Insert items. This requires an iterator. 
  list<int>::iterator i = a.begin();
  //For lists, iterators can only support ++ and -- operations.
  i++;
  a.insert(i, 1);
  //Access items.
  //In C++, you need an iterator to access elements in a list.
  for (i = a.begin(); i != a.end(); i++) {
    cout << *i << ' ';
  }
  cout << '\n';
  //You can also get the size easily.
  cout << a.size() << '\n';

  //Create a vector by specifying a type.
  vector<int> b({0, 1, 2});
  //Push and insert items like lists, access with [] operation.
  //This allows random access.
  int j;
  for (j = 0; j < b.size(); j++) {
    cout << b[j] << ' ';
    b[j] = b.size() - j;
  }
  cout << '\n';
  for (j = 0; j < b.size(); j++) {
    cout << b[j] << ' ';
  }
  cout << '\n';
  
  //Create a priority queue. C++ supports custom comparison operators.
  //It is a max queue by default, so changing your comparator to "greater" will make it  a min queue.
  priority_queue<block, vector<block>, Compare> c;
  //Push or emplace objects.
  block d(0, 0);
  c.push(d);
  c.emplace(2, 2);
  c.emplace(1, 1);
  c.emplace(3, 3);
  //Use top to peek at the top element.
  cout << c.top().value << '\n';
  //Use pop to remove the top element.
  c.pop();
  //Look again to see the next highest.
  cout << c.top().value << '\n';
}
