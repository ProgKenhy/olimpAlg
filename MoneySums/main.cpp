#pragma GCC optimize("O2")
#pragma GCC target("avx")
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <cmath>
#include <iomanip>
#include <queue>
#include <fstream>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef priority_queue<int> pq;
typedef priority_queue<int, vector<int>, greater<int>> pqr;

const int INF = INT32_MAX;
const ll LINF = LLONG_MAX;
const double PI = 3.14159265358979323846;

#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define precision(x) cout << fixed << setprecision(x)

#define FOR(i, a, b) for(ll i = (a); i < (b); i++)
#define REP(i, n) FOR(i, 0, n)
#define ROF(i, a, b) for(ll i = (b)-1; i >= (a); i--)

#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())


void solve() {
    //    ifstream file("test_input.txt");
    ll n, m = 0;
    cin >> n;
    vector<ll> v(n);
    for (ll& x : v) { cin >> x; m += x; }
    vector<vector<bool>> possible (m+1, vector<bool>(n+1, false));
    possible[0][0] = true;
    for (ll j = 1; j <= n; j++) {
        ll cur_weight = v[j - 1];  // Берем (j-1)-й элемент, так как v индексируется с 0
        for (ll i = 0; i <= m; i++) {
            // Вариант, когда не берем текущий элемент
            possible[i][j] = possible[i][j - 1];

            // Вариант, когда берем текущий элемент
            if (i >= cur_weight) {
                possible[i][j] = possible[i][j] || possible[i - cur_weight][j - 1];
            }
        }
    }

    ll count = 0;
    vector<ll> ans;
    for (ll i = 1; i <= m; i++)
    {
        if (possible[i][n]) ans.push_back(i);
    }
    cout << sz(ans) << '\n';
    for (ll i = 0; i < sz(ans); i++)
        cout << ans[i] << ' ';
        //file.close();
}

int main() {
    fastio;
    precision(6);

    int t = 1;
    while (t--) {
        solve();
    }

    return 0;
}
