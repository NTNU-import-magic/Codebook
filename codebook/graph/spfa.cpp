void spfa(int s){
    fill(dist,dist+vn,INF); dist[s]=0;
    vector<int> cnt(vn,0); vector<bool> inq(vn,0);
    queue<int> q; q.push(s); inq[s]=true;
    while(!q.empty()){
        int u=q.front(); q.pop();
        inq[u]=false;
        for(auto v:adj[u]){
            if(dist[v.idx]>dist[u]+v.w){
                if(++cnt[v.idx]>=vn) return true;
                dist[v.idx]=dist[u]+v.w;
                if(!inq[v.idx]) inq[v.idx]=true, q.push(v.idx);
            }
            
        }
    }
}