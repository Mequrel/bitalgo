/**

  Zadanie V: Kolejka.
  Autor: Bartłomiej Szczepanik

  Rozwiązanie wzorcowe.

  Złożoność rozwiązania: O(k)

**/

#include <algorithm>
#include <iostream>
#include <cassert>

using namespace std;

template <class T>
class Queue {
 public:
  Queue(size_t elements_limit) : max_size_(elements_limit) {
    data_ = new T[max_size_];
    queue_size_ = 0;
    head_index_ = 0;
  }

  ~Queue() {
    delete [] data_;
  }

  bool empty() {
    return queue_size_ == 0;
  }

  size_t size() {
    return queue_size_;
  }

  void pop() {
    assert(queue_size_ > 0);

    head_index_++;
    head_index_ %= max_size_;
    queue_size_--;
  }

  void push(T value) {
    assert(queue_size_ < max_size_);

    int last_index = (head_index_ + queue_size_) % max_size_;
    data_[last_index] = value;
    queue_size_++;
  }

  T front() {
    return data_[head_index_];
  }
 
 private:
  size_t max_size_, queue_size_;
  T* data_;
  int head_index_;
};

int main() {
  int n, k;
  cin >> n >> k;

  Queue<int> numbers(n);

  for(int i=0; i<k; ++i) {
    string operation;
    cin >> operation;

    if(operation == "FRONT") {
      if (numbers.empty()) {
        cout << "NONE" << endl;
      }
      else {
        cout << numbers.front() << endl;
      }
    }
    else if (operation == "PUSH") {
      int value;
      cin >> value;

      if(numbers.size() == n) {
        cout << "FULL" << endl;
      }
      else {
        numbers.push(value);
        cout << "OK" << endl;
      }
    }
    else { // operation == "POP"
      if(numbers.empty()) {
        cout << "EMPTY" << endl;
      }
      else {
        numbers.pop();
        cout << "OK" << endl;
      }
    }
  }

  return 0;
}
