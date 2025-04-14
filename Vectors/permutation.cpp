#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;
vector<vector<int>> all_permutation;
vector<int> permutation;


void search(int n, vector<bool>& chosen, vector<int>& subset) {
	if (permutation.size() == n) {
		all_permutation.push_back(permutation);
	}
	else {
		for (int i = 1; i <= n; i++) {
			if (chosen[i]) continue;
			chosen[i] = true;
			permutation.push_back(i);
			search(n, chosen, subset);
			chosen[i] = false;
			permutation.pop_back();
		}
	}
}


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	const int n = 3;
	vector<bool> chosen(n + 1, false);
	vector<int> subset;
	search(n, chosen, subset);
	for (int i = 0; i < all_permutation.size(); i++) {
		for (int j = 0; j < all_permutation[i].size(); j++)
			cout << all_permutation[i][j];
		cout << '\n';
	}

}

