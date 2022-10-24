// C++
#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>

#if __cplusplus >= 201103L
#include <array>
#include <atomic>
#include <chrono>
#include <condition_variable>
#include <forward_list>
#include <future>
#include <initializer_list>
#include <mutex>
#include <random>
#include <ratio>
#include <regex>
#include <scoped_allocator>
#include <system_error>
#include <thread>
#include <tuple>
#include <typeindex>
#include <type_traits>
#include <unordered_map>
#include <unordered_set>
#endif
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
    int n, m;
    cin >> n >> m;

    vvi v (n + 2, vi(m + 2, INF));
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> v[i][j];

    priority_queue<pair<int, pair<int, int>>> q;
    q.push({-0, {1, 1}});

    vvb vis (n + 2, vb(m + 2, 0));
    while (!q.empty()) {
        auto [cost, a] = q.top(); q.pop(); cost *= -1;
        auto [i, j] = a;

        if (v[i][j] == INF || vis[i][j]) continue;
        if (i == n && j == m) {
            cout << cost << '\n';
            return;
        }

        vis[i][j] = 1;

        q.push({-(cost + v[i + 1][j]), {i + 1, j}});
        q.push({-(cost + v[i - 1][j]), {i - 1, j}});
        q.push({-(cost + v[i][j + 1]), {i, j + 1}});
        q.push({-(cost + v[i][j - 1]), {i, j - 1}});
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int t = 1;
    // cin >> t;
    while (t--)
        run_case();
}