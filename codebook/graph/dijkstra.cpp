int vn; // vertex num
struct Edge {
    int idx, w;
    bool operator < (const Edge &r) const {
        return w > r.w;
    }
};
vector<Edge> adj[maxv];
void dijkstra(int s) {
    vector<bool> vis(vn, false);
    vector<int> dist(vn, INF);
    dist[s] = 0;
    priority_queue<Edge> pq;
    pq.emplace(0, s);
    while(!pq.empty()) {
        int u = pq.top().idx;
        pq.pop();
        if(vis[u]) continue;
        vis[u] = true;
        for(auto v : adj[u]) {
            if(dist[v.idx] > dist[u] + v.w) {
                dist[v.idx] = dist[u] + v.w;
                pq.emplace(dist[v.idx], v.idx);
            }
        }
    }
}