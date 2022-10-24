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
    string s, t;
    cin >> s >> t;

    int n = s.length();

    int i;
    for (i = 0; i < n; i++) {
        if (s[n - 1] == t[n - 1 - i]) {
            bool igual = true;
            for (int j = 0; j < n - i - 1; j++) {
                if (s[i + j] != t[j]) {
                    igual = false;
                    break;
                }
            }
            
            if (igual) {
                cout << "Yes\n" << i << '\n';
                return;
            }
        }
        if (s[i] != t[n - 1 - i]) {
            for (int j = 0; j < n; j++) {
                if (s[j + i] != t[j]) {
                    cout << "No\n";
                    return;
                }
                if (j + i == n - 1) {
                    cout << "Yes" << '\n';
                    cout << n - 1 - i << '\n';
                    return;
                }
            }
        }
    }

    cout << "Yes" << '\n';
    cout << (s!=t) << '\n';
}

int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int t = 1;
    // cin >> t;
    while (t--)
        run_case();
}