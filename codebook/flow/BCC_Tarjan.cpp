void dfs(int u,int pa=-1){//u當前點，pa父親 
    int v,child=0;
    low[u]=vis[u]=++Time;
    st[top++]=u;
    for(size_t i=0;i<G[u].size();++i){
        if(!vis[v=G[u][i]]){
            dfs(v,u),++child;
            low[u]=std::min(low[u],low[v]);
            if(vis[u]<=low[v]){
                is_cut[u]=1;
                bcc[++bcc_cnt].clear();
                int t;
                do{
                    bcc_id[t=st[--top]]=bcc_cnt;
                    bcc[bcc_cnt].push_back(t);
                }while(t!=v);
                bcc_id[u]=bcc_cnt;
                bcc[bcc_cnt].push_back(u);
            }
        }
        else if(vis[v]<vis[u]&&v!=pa)//反向邊 
            low[u]=std::min(low[u],vis[v]);
    }
    if(pa==-1&&child<2) is_cut[u]=0;//u是dfs樹的根要特判
}
inline void bcc_init(int n){
    Time=bcc_cnt=top=0;
    for(int i=1;i<=n;++i){
        G[i].clear();
        vis[i]=0;
        is_cut[i]=0;
        bcc_id[i]=0;
    }
}