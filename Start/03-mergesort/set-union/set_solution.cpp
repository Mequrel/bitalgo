#include <cstdio>
#include <set>

using namespace std;

int main() {
  int first_size, second_size;
  scanf("%d %d", &first_size, &second_size);

  set<int> numbers;

  for(int i=0; i<first_size+second_size; ++i) {
    int x;
    scanf("%d", &x);

    numbers.insert(x);
  }

  for(int elem : numbers) {
    printf("%d ", elem);
  }

  return 0;
}