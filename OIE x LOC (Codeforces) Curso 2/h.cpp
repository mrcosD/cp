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

int n, m;
vvb t;
int ans = 0;


void run_case () {
    cin >> n >> m;


    t.resize(n, vb(m));

    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < m; j++) {
            t[i][j] = (s[j] == '.' ? 0 : 1);
        }
    }

    
    vvi v (n, vi(m));
    v[n - 1][m - 1] = 1;
    for (int i = n - 1; i >= 0; i--) {
        for (int j = m - 1; j >= 0; j--) {
            if (!t[i][j]) {
                if (i + 1 < n) v[i][j] = (v[i][j] + v[i + 1][j]) % MOD;
                if (j + 1 < m) v[i][j] = (v[i][j] + v[i][j + 1]) % MOD;
                if (i - 1 >= 0) v[i][j] = (v[i][j] + v[i - 1][j]) % MOD;
                if (j - 1 >= 0) v[i][j] = (v[i][j] + v[i][j - 1]) % MOD; 
            }
        }
    }

    cout << v[0][0] << '\n';

    // for (int i = 0; i < n; i++){ 
    //     for (int j = 0; j < m; j++) {
    //         cout << v[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }
}

int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int t = 1;
    // cin >> t;
    while (t--)
        run_case();
}