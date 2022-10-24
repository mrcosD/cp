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



void run_case () {
    int n;
    cin >> n;

    int l = 1, r = n, m = 0;
    while (l <= r) {
        m = (l + r) / 2;

        int sum = 0;
        for (int i = 1; i <= m; i++) sum += m / i;

        if (sum >= n) r = m - 1;
        else l = m + 1;
    }

    cout << l << '\n';
}

int32_t main() {
    // ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int t = 1;
    // cin >> t;
    while (t--)
        run_case();
}