#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int longestPalindrome(const vector<int>& nums) {
    if (nums.empty()) return 0;

    vector<int> extended;
    for (int num : nums) {
        extended.push_back(-1);
        extended.push_back(num);
    }
    extended.push_back(-1);

    int n = extended.size();
    vector<int> p(n, 0);
    int center = 0, right = 0;
    int max_len = 0;

    for (int i = 1; i < n - 1; ++i) {
        int mirror = 2 * center - i;

        if (i < right)
            p[i] = min(right - i, p[mirror]);

        int l = i - p[i] - 1;
        int r = i + p[i] + 1;
        while (l >= 0 && r < n && extended[l] == extended[r]) {
            p[i]++;
            l--;
            r++;
        }

        if (i + p[i] > right) {
            center = i;
            right = i + p[i];
        }

        if (p[i] > max_len)
            max_len = p[i];
    }

    return max_len > 0 ? max_len : 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> v(n);
    for (int& x : v) cin >> x;

    int result = longestPalindrome(v);
    cout << (result > 1 ? result : 0);

    return 0;
}
