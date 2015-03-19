/**

  Zadanie: Scalanie wielu list.
  Autor: Bartłomiej Szczepanik

  Rozwiązanie dla celów testowych.

  Złożoność rozwiązania: O(m lg m)

**/

#include <algorithm>
#include <cstdio>
#include <vector>

using namespace std;

int main() {
  int lists_count;
  scanf("%d", &lists_count);

  vector<int> elements;

  for(int i=0; i<lists_count; ++i) {
    int size;
    scanf("%d", &size);

    for(int j=0; j<size; ++j) {
      int value;
      scanf("%d", &value);

      elements.push_back(value);
    }
  }

  sort(elements.begin(), elements.end());

  for(int element : elements) {
    printf("%d ", element);
  }

  return 0;
}