int DAG_longest(int u){
    // remember to init
    if(dp[u]){
        return dp[u];
    }
    if(sccG[u].size()==0){
        // Cnt: scc_id point amount
        return dp[u] = Cnt[u];
    }
    int maxu = 0;
    for(int i=1;i<=scc;++i){
        // sccG: shrink point adjList of scc graph
        for(auto j:sccG[u]){
            maxu = max(maxu, DAG_longest(j));
        }
    }
    return dp[u] = maxu + Cnt[u];
}
// main func
for (int i = 1; i <= vn; i++) {
    for(auto u:g[i]){ // g-> original graph
        if(belong[i] != belong[u]){ 
            // belong: see SCC template, it's shrink point
            int scc_id = belong[u];
            sccG[belong[i]].push_back(belong[u]);
        }
    }
}
for(int i=1;i<=scc;++i){
    Cnt[i] = sccV[i].size();
}
int maxu = 0;
for(int i=1;i<=scc;++i){
    maxu = max(maxu, DAG_longest(i));
}