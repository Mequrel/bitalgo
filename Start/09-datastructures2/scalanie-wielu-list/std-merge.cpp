/**

  Zadanie: Scalanie wielu list.
  Autor: Bartłomiej Szczepanik

  Rozwiązanie pokazowe z użyciem std::priority_queue.

  Złożoność rozwiązania: O(m lg n)

**/

#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int>> load_numbers() {
  int lists_count;
  scanf("%d", &lists_count);

  vector<vector<int>> lists;
  lists.resize(lists_count);

  for(int i=0; i<lists_count; ++i) {
    int size;
    scanf("%d", &size);

    for(int j=0; j<size; ++j) {
      int value;
      scanf("%d", &value);

      lists[i].push_back(value);
    }
  }

  return lists;
}

typedef pair<int, int> ValueListId;

int main() {
  vector<vector<int>> lists = load_numbers();

  vector<int> current_positions;
  current_positions.resize(lists.size(), 0);

  priority_queue<ValueListId, vector<ValueListId>, greater<ValueListId>> first_elements;

  for(int i=0; i<lists.size(); ++i) {
    int list_id = i;
    int first_element_value = lists[i][0];

    first_elements.push({first_element_value, i});
  }

  while(!first_elements.empty()) {
    pair<int, int> min_element = first_elements.top();
    first_elements.pop();

    int value = get<0>(min_element);
    int list_id = get<1>(min_element);

    printf("%d ", value);
    current_positions[list_id]++;
    int position = current_positions[list_id];

    if(position < lists[list_id].size()) {
      first_elements.push({lists[list_id][position], list_id});
    } 
  }

  return 0;
}