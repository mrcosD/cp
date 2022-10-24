#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ii pair<int, int>
#define vi vector<int>
#define vii vector<ii>
#define vvi vector<vi>
#define vvii vector<vii>
#define vb vector<bool>
#define vvb vector<vb>

// mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
// #define uid(a, b) uniform_int_distribution<int>(a, b)(rng)

const int MOD = 1000000007;
const int mod = 998244353;
const int INF = 1e18;
const char nl = '\n';

vii f;
void factor (int n) {
    int initN = n;
    for (int a = 2; a * a <= initN; a++) {
        if (n % a == 0) {
            int times = 0;
            while (n % a == 0) {
                times++;
                n /= a;
            }

            f.push_back({a, times});
        }
    }

    if (n > 1)
        f.push_back({n, 1});
}

void run_case () {
    int n;
    cin >> n;

    factor(n);

    if ((f.size() == 1 && f[0].second == 2) || (f.size() == 2 && f[0].second == 1 && f[1].second == 1)) {
        cout << "YES\n";
    }
    else cout << "NO\n";
}

int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int t = 1;
    // cin >> t;
    while (t--)
        run_case();
}