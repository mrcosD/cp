struct UnionFind {
    vi p, rank, size;
    UnionFind (int N) {
        p.resize(N, 0); rank.resize(N, 0); size.resize(N, 1);
        for (int i = 0; i < N; i++) p[i] = i;
    }

    int findSet (int i) { return (p[i] == i) ? i : (p[i] = findSet(p[i])); }

    bool isSameSet (int i, int j) { return findSet(i) == findSet(j); }

    void unionSet (int i, int j) {
        if (!isSameSet(i, j)) {
            int x = findSet(i), y = findSet(j);
            if (rank[x] > rank[y]){ p[y] = x; size[x] += size[y];}
            else {                  p[x] = y; size[y] += size[x];
                                    if (rank[x] == rank[y]) rank[y]++; } } }

int getsize (int i) { return size[findSet(i)]; }
};
