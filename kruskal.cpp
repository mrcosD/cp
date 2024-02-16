/* Kruskal's MST algorithm. Union-Find is required */
int kruskal (int V, int E) {
    int u, v, w;
    vector<pair<int, ii>> graph;
    for (int i = 0; i < E; i++) {
        cin >> u >> v >> w;
        graph.push_back(make_pair(w, ii(u, v)));
    }
    sort(graph.begin(), graph.end());

    int mst_cost = 0, num_taken = 0;

    UnionFind UF (V);
    for (int i = 0; i < E && num_taken < V-1; i++) {
        pair<int, ii> front = graph[i];
        if (!UF.isSameSet(front.second.first, front.second.second)) {
            num_taken++;
            mst_cost += front.first;
            UF.unionSet(front.second.first, front.second.second);
    } }
    return (mst_cost == V-1) ? mst_cost : -1; } 