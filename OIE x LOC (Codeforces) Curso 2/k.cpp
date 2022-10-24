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

// Everything must be 0-indexed
struct segTree {
    int size;
    vector<int> sums;

    void init(int n) {
        size = 1;
        while (size < n) 
            size *= 2;
        sums.assign(2 * size, 0LL);
    }

    void build (vector<int> &a, int x, int lx, int rx) {
        if (rx - lx == 1) {
            if (lx < (int)a.size()) {
                sums[x] = a[lx];
            }
            return;
        }
        int m = (lx + rx) / 2;
        build(a, x * 2 + 1, lx, m);
        build(a, x * 2 + 2, m, rx);
        sums[x] = sums[2 * x + 1] + sums[2 * x + 2];
    }

    void build (vector<int> &a) {
        build(a, 0, 0, size);
    }

    void set (int i, int v, int x, int lx, int rx) {
        if (rx - lx == 1) {
            sums[x] = v;
            return;
        }
        int m = (lx + rx) / 2;
        if (i < m) {
            set(i, v, 2 * x + 1, lx, m);
        }
        else {
            set(i, v, 2 * x + 2, m, rx);
        }
        sums[x] = sums[2 * x + 1] + sums[2 * x + 2];
    }

    void set (int i, int v) {
        set(i, v, 0, 0, size);
    }

    int sum (int l, int r, int x, int lx, int rx) {
        if (lx >= r || l >= rx) return 0;
        if (lx >= l && rx <= r) return sums[x];
        int m = (lx + rx) / 2;
        int s1 = sum(l, r, 2 * x + 1, lx, m);
        int s2 = sum(l, r, 2 * x + 2, m, rx);
        return s1 + s2;
    }

    int sum (int l, int r) {
        return sum(l, r, 0, 0, size);
    }
};

void run_case () {
    int n, q;
    cin >> n >> q;

    segTree A, B; A.init(n); B.init(n);
    vi a, b;
    int X;
    bool change = 0;
    for (int i = 0; i < n; i++) {
        cin >> X;
        if (!change) {
            a.push_back(X);
            b.push_back(-X);
        }
        else {
            a.push_back(-X);
            b.push_back(X);
        }
        change = !change;
    }

    A.build(a);
    B.build(b);

    int t;
    while (q--) {
        cin >> t;
        if (t == 1) {
            int p, x;
            cin >> p >> x; p--;
            if (p % 2 == 0) {
                A.set(p, x);
                B.set(p, -x);
            } else {
                A.set(p, -x);
                B.set(p, x);
            }
        }
        else {
            int l, r;
            cin >> l >> r; l--; // r--;
            if (l % 2 == 0) {
                cout << A.sum(l, r) << '\n';
            } else {
                cout << B.sum(l, r) << '\n';
            }
        }
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int t = 1;
    // cin >> t;
    while (t--)
        run_case();
}