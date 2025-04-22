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

#define FOR(i, a, b) for(int i = (a); i < (b); i++)
#define REP(i, n) FOR(i, 0, n)
#define ROF(i, a, b) for(int i = (b)-1; i >= (a); i--)

#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())


void solve() {
    ll n;
    cin >> n;
    vector<ll> v(n);
    vector<ll> dlina(n);
    ll ans = 1;
    ll cur_max = 0;

    for (ll& x : v) cin >> x;

    vector<ll> tail; // Вектор для хранения "хвостов" подпоследовательностей
    for (ll x : v) {
        auto it = lower_bound(tail.begin(), tail.end(), x);
        if (it == tail.end()) {
            tail.push_back(x);
        }
        else {
            *it = x;
        }
    }
    cout << tail.size(); // Длина tail равна длине LIS
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
