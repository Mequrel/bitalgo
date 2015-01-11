/**

  Zadanie U: Dynamiczna tablica.
  Autor: Bartłomiej Szczepanik

  Rozwiązanie pokazowe z użyciem std::vector.

  Złożoność rozwiązania: O(n), złożoność pojedynczej operacji amortyzuje się do O(1)

**/

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n;
  cin >> n;

  vector<int> dynamic_array;

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
