#include <cstdio>
#include <vector>

void sito(long long n, bool *T) {
	for(long long i = 0; i < n; ++i) T[i] = true;
	T[0] = false;
	T[1] = false;
	for(long long i = 2; i < n; ++i) {
		if(T[i] == true) {
			for(long long j = i*i; j < n; j += i) {
				T[j] = false;
			}
		}
	}
}

int main() {
	int z;
	bool *prime = new bool[1000001];
	sito(1000001, prime);
	scanf("%d", &z);
	while(z--) {
		int n;
		scanf("%d", &n);
		if(prime[n]) {
			printf("TAK\n");
		}
		else {
			printf("NIE\n");
		}
	}
	delete[] prime;
	return 0;
}
