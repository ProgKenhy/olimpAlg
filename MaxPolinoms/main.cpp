#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <cmath>
#include <iomanip>
#include <queue>
//#include <fstream>
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
    ll n, ans = 0;
    cin >> n;
    vector<ll> v(n);
    for (ll& x : v) cin >> x;

    FOR(i, 1, sz(v)) {
        if (v[i] == v[i - 1]) {
            ll temp = 0;
            FOR(b, 0, i)
            {
                if (v[i - b - 1] == v[i + b])
                    temp += 2;
                else break;
            }
            ans = max(ans, temp);
        }
        if (v[i - 1] == v[i + 1]) {
            ll temp = 1;
            FOR(b, 1, i + 1)
            {
                if (v[i - b] == v[i + b])
                    temp += 2;
                else break;
            }
            ans = max(ans, temp);
        }
    }
    cout << ans;
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
оцени и сделай лучше если можно
