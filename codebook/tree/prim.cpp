struct edge {
    int idx, w;
    bool operator < (const edge &r) const {
        return w > r.w;
    }
};
int prim() {
    int vn; // vertex num
    vector<edge> adj[vn];
    int ans = 0;
    priority_queue<edge> pq;
    vector<bool> vis(vn, false);
    vis[0] = true;
    for(auto v : adj[0]) pq.emplace(v);
    while(!pq.empty()) {
        edge mn = pq.top();
        pq.pop();
        if(vis[mn.idx]) continue;
        vis[mn.idx] = true;
        ans += mn.w;
        for(auto v : adj[mn.idx]) pq.emplace(v);
    }
}