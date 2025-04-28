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
typedef vector<ll> vtl;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef priority_queue<int> pq;
typedef priority_queue<int, vector<int>, greater<int>> pqr;

const double PI = 3.14159265358979323846;

#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)

#define FOR(i, a, b) for(ll i = (a); i < (b); i++)
#define REP(i, n) FOR(i, 0, n)
#define ROF(i, a, b) for(ll i = (b)-1; i >= (a); i--)

#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())


void solve() {
    ll n;
    ll ans = 0;
    cin >> n;
    vector<ll> v(n);
    vector<ll> number(201, 0);
    for (ll& x : v)
    {
        cin >> x;
        number[x] += 1;
    }
    for (ll& x : v)
    {
        FOR(i, x + 1, sz(number)) {
            ans += number[i];
        }
        number[x]--;
    }
    cout << ans << '\n';
}

int main() {
    fastio;

    int t = 1;
    while (t--) {
        solve();
    }

    return 0;
}
