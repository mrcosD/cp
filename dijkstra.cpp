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


struct Edge {
    int v;  // Vertex that we're traveling to
    int c;  // Cost to travel

    Edge () {};

    Edge (int vertex, int cost) {
        v = vertex;
        c = cost;
    }

    /* Max to min sorting, useful for priority queues */
    bool operator< (const Edge& edge2) const {
        return edge2.c < c;
    }
};


vector<vector<Edge>> graph;
vi tCost;        // TAMANO MAXIMO INDICADO POR EL PROBLEMA

int V, E;


/* Dijkstra's algotithm. Remember to make it undirected (or not) */
void dijkstra () {
    tCost[1] = 0;    // Travelning to v 1 has cost 0

    priority_queue<Edge> q;
    q.push(Edge(1, 0));


    Edge edge;
    while (!q.empty()) {

        /* Analizamos la primera calle de la cola y lo borramos */
        edge = q.top();
        q.pop();


        /* Si lo que nos cuesta utilizar este enlace es menor o igual a lo que ya teniamos, quizas nos interese */
        if (edge.c <= tCost[edge.v]) {

            /* Recorremos todos los vertices hasta los que podemos llegar desde este */
            for (Edge e : graph[edge.v]) {

                /* Si lo que nos cueste este v (mas el c del que venimos) es menor a lo que ya teniamos, establecemos un nuevo minimo*/
                if (e.c + edge.c < tCost[e.v]) {

                    /* Actualizamos el nuevo c y metemos a la cola */
                    tCost[e.v] = e.c + edge.c;
                    q.push(Edge(e.v, tCost[e.v]));
                }
            }
        }
    }
}

int32_t main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

/*
5 6
1 2 5
1 3 2
2 4 3
1 4 7
3 4 1
3 5 9
*/

    while (cin >> V >> E) {
        graph.resize(V + 1); tCost.resize(V + 1, INT32_MAX);

        int from, to, cost;
        for (int i = 0; i < E; i++) {
            cin >> from >> to >> cost;
            graph[from].push_back(Edge(to, cost));
            graph[to].push_back(Edge(from, cost));
        }


        dijkstra();

        for (int i = 1; i <= V; i++) cout << tCost[i] << '\n';
    }
}