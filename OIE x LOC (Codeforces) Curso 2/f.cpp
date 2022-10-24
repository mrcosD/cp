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

vector<set<int>> graph;
vb visited;

void rec (int x) {
    if (visited[x]) return;

    visited[x] = 1;
    for (int a : graph[x]) {
        rec(a);
    }
}

void run_case () {
    int n, m;
    cin >> n >> m;

    graph.resize(n);

    int from, to;
    while (m--) {
        cin >> from >> to; from--; to--;

        graph[from].insert(to);
        graph[to].insert(from);
    }

    visited.resize(n, 0);

    int con = 0;
    for (int i = 0; i < n; i++) {
        if (visited[i]) continue;
        con++;
        rec(i);
    }
    cout << con << '\n';
}

int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int t = 1;
    // cin >> t;
    while (t--)
        run_case();
}