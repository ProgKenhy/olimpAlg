#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <cmath>
#include <iomanip>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int INF = 1e9 + 7;
const ll LINF = 1e18;
const double PI = 3.14159265358979323846;

#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define precision(x) cout << fixed << setprecision(x)

#define FOR(i, a, b) for(int i = (a); i < (b); i++)
#define REP(i, n) FOR(i, 0, n)
#define ROF(i, a, b) for(int i = (b)-1; i >= (a); i--)

#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())


bool valid(ull fin_time, vector<ll> v, ll n) {
    ll done_t = 0;
    REP(i, sz(v)) {
        done_t += fin_time / v[i];
    }
    return done_t >= n;
}

void solve() {
    ll m, n;
    ll best_time = INT32_MAX;
    cin >> m >> n;
    vector<ll> v(m);
    for (ll& x : v) {
        cin >> x;
        best_time = min(x, best_time);
    }


    ull ans = -1;
    ull fin_time = ull(best_time) * n;
    for (ull b = fin_time; b >= 1; b /= 2) {
        while (!valid(ans + b, v, n)) ans += b;
    }
    ans += 1;

    cout << ans;
}

int main() {
    fastio;
    precision(6);

    int t = 1;
    // cin >> t; // Раскомментировать для нескольких тестов
    while (t--) {
        solve();
    }

    return 0;
}
