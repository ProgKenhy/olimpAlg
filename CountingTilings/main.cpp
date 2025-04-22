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
typedef vector<ll> vtl;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef priority_queue<int> pq;
typedef priority_queue<int, vector<int>, greater<int>> pqr;

const int INF = INT32_MAX;
const ll LINF = LLONG_MAX;
const double PI = atan(1) * 4;

#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define precision(x) cout << fixed << setprecision(x)

#define FOR(i, a, b) for(ll i = (a); i < (b); i++)
#define REP(i, n) FOR(i, 0, n)
#define ROF(i, a, b) for(ll i = (b)-1; i >= (a); i--)

#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())

const int MOD = 1e9 + 7;

void solve() {
    int n, m;
    cin >> n >> m;
    double result = 1;


    if ((n == 1 and m == 1) or ((n * m) % 2 == 1)) result = 0;

    for (int a = 1; a <= n/2; ++a) {
        for (int b = 1; b <= m/2; ++b) {
            double cos_a = cos(PI * a / (n + 1));
            double cos_b = cos(PI * b / (m + 1));
            double term = 4 * cos_a * cos_a + 4 * cos_b * cos_b;
            result *= term ;
        }
    }

    cout << ull(result) % MOD << endl;
}

int main() {
    fastio;
    precision(0);

    int t = 1;
    while (t--) {
        solve();
    }

    return 0;
}
