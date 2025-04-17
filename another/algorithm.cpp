#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


ll binary_search(vector<ll> v, ll x) {
    ll a = 0, k = 0;
    ll b = sz(v) - 1;
    while (a <= b)
    {
        k = (a + b)/2;
        if (v[k] == x) return k;
        if (v[k] < x) a = k + 1;
        else b = k - 1;
    }
}

void search(vector <int> arr) {
	for (int i = 0; i < arr.size(); i++)
	{
		cout << arr[i] << ' ';
	}
	cout << endl;
	cout << lower_bound(arr.begin(), arr.end(), -2) - arr.begin() << " " << upper_bound(arr.begin(), arr.end(), 3) - arr.begin() << '\n';
	cout << binary_search(arr.begin(), arr.end(), -1) << '\n';
	//do
	//{
	//	for (auto x : arr) cout << x << " ";
	//	cout << "\n";
	//} while (next_permutation(arr.begin(), arr.end()));
}


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	vector<int> arr{-1, 2, 4, -3, 5, 2, -5, 2};
	cout << min_element(arr.begin(), arr.end()) - arr.begin();
	sort(arr.begin(), arr.end());
	search(arr);
}
