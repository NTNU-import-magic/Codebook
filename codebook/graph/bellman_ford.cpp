int vn; // vertex num
struct Edge {
    int idx, w;
};
vector<Edge> adj[maxv];
bool bellmanford(int s) { //return true if negative cycle exists;
    int cnt = 0;
    bool update = false;
    vector<int> dist(vn, INF);
    dist[s] = 0;
    do {
        if(++cnt == vn) return true;
        update = false;
        for(int u = 0; u < vn; ++u) {
            if(dist[u] == INF) continue;
            for(auto v : adj[u]) {
                if(dist[v.idx] > dist[u] + v.w) {
                    update = true;
                    dist[v.idx] = dist[u] + v.w;
                }
            }
        }
    } while(update);
    return false;
}