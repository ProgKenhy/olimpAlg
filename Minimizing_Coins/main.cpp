#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <cmath>
#include <iomanip>
#include <queue>
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
const ull ULINF = ULLONG_MAX;
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


ull foo(ull s, ull cur_s, vector<ull> coins) {
    vector <ull> value(s + 1, ULINF);
    value[0] = 0;

    for (ull i=1; i <= s; i++)
        for(auto coin : coins){
            if (coin <= i and value[i - coin] != ULINF)
                value[i] = min(value[i], value[i - coin] + 1);
        }

    return value[s];
}



void solve() {
    ull n, s, cur_s = 0;
    cin >> n >> s;
    vector<ull> coins(n);
    for (ull& x : coins) cin >> x;
    ull ans = foo(s, cur_s, coins);
    if (ans == ULINF) cout << -1;
    else cout << ans;
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
