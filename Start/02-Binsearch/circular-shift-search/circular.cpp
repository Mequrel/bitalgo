/**

  Zadanie F: Wyszukiwanie w ciągu przesuniętym cyklicznie.
  Autor: Bartłomiej Szczepanik

  Rozwiązanie wzorcowe.

  Złożoność rozwiązania: O(k lg n)

**/

#include <cstdio>
#include <cmath>

using namespace std;

const int NOT_FOUND = -1;

int binsearch(int* sequence, int size, int query) {
  int left = 0;
  int right = size;

  while(left < right) {
    int middle = (left + right) / 2;
    if(sequence[middle] < query) {
      left = middle + 1;
    }
    else {
      right = middle;
    }
  }
  
  return (sequence[left] == query) ? left : NOT_FOUND;
}

int find_max(int* sequence, int size) {
  int current = 0;
  int hop = size / 2;

  while(hop > 0) {
    if(sequence[current] < sequence[current + hop]) {
      current += hop;
    }
    hop /= 2;
  }

  return current;
}

int cyclic_binsearch(int* sequence, int size, int query) {
  int max_index = find_max(sequence, size);

  if(sequence[0] <= query && query <= sequence[max_index]) {
    return binsearch(sequence, max_index + 1, query);
  }
  else {
    int result = binsearch(sequence + max_index + 1, size - max_index - 1, query);
    if(result != NOT_FOUND) {
      result += max_index + 1;
    }
    return result;
  }
}

int main() {
  int n, k;
  scanf("%d %d", &n, &k);

  int* sequence = new int[n];
  for(int i=0; i<n; ++i) {
    scanf("%d", &sequence[i]);
  }

  for(int i=0; i<k; ++i) {
    int query;
    scanf("%d", &query);

    int result_index = cyclic_binsearch(sequence, n, query);

    if(result_index == NOT_FOUND) {
      printf("-1 ");
    }
    else {
      printf("%d ", result_index + 1);
    }
  }

  return 0;
}