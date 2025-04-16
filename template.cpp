#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <cmath>
#include <iomanip>
using namespace std;

typedef long long ll;
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

#ifdef DEBUG
#define dbg(x) cerr << #x << " = " << x << endl
#else
#define dbg(x)
#endif

void solve() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (int& x : v) cin >> x;

    sort(all(v));
    for (int x : v) cout << x << " ";
    cout << endl;
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
