#include <iostream>
#include <list>   //http://www.cplusplus.com/reference/list/list/
#include <vector> //http://www.cplusplus.com/reference/vector/vector/
#include <stack>  //http://www.cplusplus.com/reference/stack/stack/
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
  cout << "Lists:\n";
  //Create a list by specifying a type.
  list<int> l;
  //Push an item to the back or front of the list.
  l.push_back(2);
  l.push_front(0);
  //Insert items. This requires an iterator. 
  list<int>::iterator i = l.begin();
  //For lists, iterators can only support ++ and -- operations.
  i++;
  l.insert(i, 1);
  //Access items.
  //In C++, you need an iterator to access elements in a list.
  for (i = l.begin(); i != l.end(); i++) {
    cout << *i << ' ';
  }
  cout << '\n';
  //You can also get the size easily.
  cout << l.size() << "\n\n";

  cout << "Vectors:\n";
  //Create a vector by specifying a type.
  vector<int> v({0, 1, 2});
  //Push and insert items like lists, access with [] operation.
  //This allows random access.
  int j;
  for (j = 0; j < v.size(); j++) {
    cout << v[j] << ' ';
    v[j] = v.size() - j;
  }
  cout << '\n';
  for (j = 0; j < v.size(); j++) {
    cout << v[j] << ' ';
  }
  cout << "\n\n";

  cout << "Stacks:\n";
  //Create a stack with a type.
  stack<int> s;
  //Push, pop, top, empty, and size are the basic functions.
  //Push and pop operate on the top of the stack.
  s.push(0);
  s.push(1);
  cout << s.top() << '\n';
  s.pop();
  cout << s.top() << '\n';
  cout << s.size() << "\n\n";

  cout << "Queues:\n";
  //Create a queue with a type.
  queue<int> q;
  //Push, pop, front, back, size, and empty are the basic functions.
  //Push pushes to the back of the queue and pop pops from the front.
  q.push(0);
  q.push(1);
  cout << q.front() << '\n';
  q.pop();
  cout << q.front() << '\n';
  cout << q.size() << "\n\n";

  cout << "Priority Queues:\n";
  //Create a priority queue. C++ supports custom comparison operators.
  //It is a max queue by default, so changing your comparator to "greater" will make it  a min queue.
  priority_queue<block, vector<block>, Compare> pq;
  //Push or emplace objects.
  block b(0, 0);
  pq.push(b);
  pq.emplace(2, 2);
  pq.emplace(1, 1);
  pq.emplace(3, 3);
  //Use top to peek at the top element.
  cout << pq.top().value << '\n';
  //Use pop to remove the top element.
  pq.pop();
  //Look again to see the next highest.
  cout << pq.top().value << '\n';
}
