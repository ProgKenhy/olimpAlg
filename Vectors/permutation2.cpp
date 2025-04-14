#include <iostream>
#include <vector>
#include <algorithm>
#define PB push_back
using namespace std;

typedef long long ll;
vector<vector<int>> all_permutation;
vector<int> permutation;


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n = 3;

	for (int i = 1; i <= n; i++) {
		permutation.push_back(i);
	}
	do {
		all_permutation.PB(permutation);
	} while (next_permutation(permutation.begin(), permutation.end()));

	for (int i = 0; i < all_permutation.size(); i++) {
		for (int j = 0; j < all_permutation[i].size(); j++)
			cout << all_permutation[i][j];
		cout << '\n';
	}

}

