#include <bits/stdc++.h>
using namespace std;

#define getchar_unlocked getchar
#define putchar_unlocked putchar

#define int long long
#define ii pair<int, int>
#define vi vector<int>
#define vii vector<ii>

/* Greatest common divisor of... */
int gcd (int a, int b) {
    if (b > a) swap(a, b);

    if (a % b == 0) return b;

    return gcd(b, a % b);
}

/* IMPORTANT
 * To calculate gcd or mcm of several numbers: gcd(a, gcd(b, c)) or mcm(a, mcm(b, c))
*/

/* Minimum common multiple of... */
int mcm (int a, int b) {
    return (a * b / gcd(a, b));
}


int32_t main() {
    cout << mcm(200, mcm(75, 100)) << '\n';
}