#include <bits/stdc++.h>
using namespace std;

#define getchar_unlocked getchar
#define putchar_unlocked putchar

#define int long long
#define ii pair<int, int>
#define vi vector<int>
#define vii vector<ii>
#define vvi vector<vi>
#define vvii vector<vii>

vi taken;
priority_queue<ii> pq; // Returns max, so we negate all numbers
vii graph

void process (int vtx) {
    taken[vtx] = 1;
    for (ii v : graph[vtx]) if (!taken[v.first]) pq.push(ii(-v.second, -v.first)); }

int prim (int V, int E) {
    taken.resize(V, 0);
    process(0);
    int mst_cost = 0, num_taken = 0;
    while (!pq.empty() && num_taken < V-1) {
        ii front = pq.top(); pq.pop();
        int u = -front.second, w = -front.first;
        if (!taken[u]) {
            num_taken++;
            mst_cost += w;
            process(u);
        }
    }

    return (num_taken == V-1) ? mst_cost : -1;
}

int32_t main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    
}