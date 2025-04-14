#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;
vector<vector<int>> all_subsets;

void search(int k, int n, vector<int>& subset) {
	if (k == n + 1) {
		all_subsets.push_back(subset);
	}
	else {
		//	включить	k	в	подмножество
		subset.push_back(k);
		search(k + 1, n, subset);
		subset.pop_back();
		//	не	включать	k	в	подмножество
		search(k + 1, n, subset);
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n = 3;
	vector<int> subset;
	search(2, n, subset);
	for (int i = 0; i < all_subsets.size(); i++) {
		for (int j = 0; j < all_subsets[i].size(); j++)
			cout << all_subsets[i][j];
		cout << '\n';
	}
}

