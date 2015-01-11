/**

  Zadanie V: Kolejka.
  Autor: Bartłomiej Szczepanik

  Rozwiązanie pokazowe z użyciem std::queue.

  Złożoność rozwiązania: O(k)

**/

#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;

int main() {
  int n, k;
  cin >> n >> k;

  queue<int> numbers;

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
