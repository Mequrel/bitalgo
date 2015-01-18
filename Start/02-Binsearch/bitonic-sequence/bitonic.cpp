#include <iostream>
#include <vector>
using namespace std;

int binaryBitonic(const vector<int> &input) {
	int L = 0;
	int R = input.size()-1;
	while(R - L > 5) {
		int middle = (R+L)/2;
		if(input[middle] > input[middle+1]) R = middle;
		else L = middle + 1;
	}
	int biggest = input[L];
	for(int i = L + 1; i <= R; i++) {
		if(input[i] > biggest) biggest = input[i];
	}
	return biggest;
}

int main() {
	int n;
	cin >> n;
	vector<int> input(n);
	for(int i = 0; i < n; i++) cin >> input[i];
	cout << binaryBitonic(input) << "\n";
}
