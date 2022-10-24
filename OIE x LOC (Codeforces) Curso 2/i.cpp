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

vi v;
vi ans;

bool find (int n, int sum) {
    if (sum % 2 == 1) return 0;

    vvb a(sum / 2 + 1, vb(n + 1, 0));

    for (int j = 0; j < n; j++)
        a[0][j] = 1;

    for (int i = 1; i <= sum / 2; i++) {
        for (int j = 1; j <= n; j++) {
            a[i][j] = a[i][j - 1];
            if (!a[i][j] && i >= v[j - 1]) {
                a[i][j] = a[i - v[j - 1]][j - 1];
            }
        }
    }

    return a[sum / 2][n];
}

bool done = 0;

void dp (int t, vb u) {
    if (!t) {
        done = 1;
        return;
    }

    for (int i = 0; i < v.size(); i++) {
        if (!u[i] && t >= v[i]) {
            u[i] = 1;
            dp(t - v[i], u);
            if (done) {
                ans.push_back(i);
                return;
            }
        }
    }
}

void run_case () {
    int n;
    cin >> n;

    int sum = 0;

    v.resize(n);
    for (int &x : v)  {
        cin >> x;
        sum += x;
    }


    if (!find(n, sum)) {
        cout << "NO" << '\n';
        return;
    }
    else {
        cout << "YES" << "\n";
        vb u(n + 1, 0);
        dp(sum / 2, u);
        sort(ans.begin(), ans.end());
        cout << ans.size() << '\n';
        for (int x : ans) cout << x + 1 << ' ';
        cout << '\n';
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int t = 1;
    // cin >> t;
    while (t--)
        run_case();
}