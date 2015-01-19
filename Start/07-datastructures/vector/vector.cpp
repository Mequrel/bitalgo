/**

  Zadanie U: Dynamiczna tablica.
  Autor: Bartłomiej Szczepanik

  Rozwiązanie wzorcowe.

  Złożoność rozwiązania: O(n), złożoność pojedynczej operacji amortyzuje się do O(1)

**/

#include <algorithm>
#include <iostream>
#include <cassert>

using namespace std;

template <class T>
class DynamicArray {
 public:
  DynamicArray() {
    capacity_ = 0;
    size_ = 0;
    data_ = nullptr;
  }

  ~DynamicArray() {
    if(data_ != nullptr) {
      delete [] data_;
    }
  }
 
  void resize(int size, const T& value) {
    delete [] data_;
    data_ = nullptr;

    change_capacity(size);
    size_ = size;

    fill(data_, data_ + size_, value);
  }

  size_t size() const {
    return size_;
  }

  T& operator[] (const int index) {
    assert(0 <= index && index < size());

    return data_[index];
  }

  void push_back(const T& value) {
    size_++;
    resize_if_needed();

    (*this)[size_-1] = value;
  }

  void pop_back() {
    assert(size_ > 0);

    size_--;
    resize_if_needed();
  }

 private:
  void resize_if_needed() {
    if(size_ > capacity_) {
      if(capacity_ == 0) {
        change_capacity(1);
      }
      else {
        change_capacity(capacity_ * 2);
      }
    }
    else if(4*size_ <= capacity_) {
      change_capacity(capacity_ / 2);
    }
  }

  void change_capacity(int new_capacity) {
    T* new_data_ = new T[new_capacity];

    if(data_ != nullptr) {
      copy(data_, data_ + size_, new_data_);
      delete [] data_;
    }

    data_ = new_data_;
    capacity_ = new_capacity;
  }

  size_t capacity_, size_;
  T* data_;
};

int main() {
  int n;
  cin >> n;

  DynamicArray<int> dynamic_array;

  for(int i=0; i<n; ++i) {
    string operation;
    cin >> operation;

    if(operation == "RESIZE") {
      int elements, value;
      cin >> elements >> value;

      dynamic_array.resize(elements, value);
    }
    else if(operation == "GET") {
      int index;
      cin >> index;

      if(dynamic_array.size() <= index) {
        cout << "OUT OF BOUND" << endl;
      } else {
        cout << dynamic_array[index] << endl;
      }
    }
    else if (operation == "SET") {
      int index, value;
      cin >> index >> value;

      dynamic_array[index] = value;
    }
    else if (operation == "PUSH_BACK") {
      int value;
      cin >> value;

      dynamic_array.push_back(value);
    }
    else { // operation == "POP_BACK"
      dynamic_array.pop_back();
    }
  }

  return 0;
}
