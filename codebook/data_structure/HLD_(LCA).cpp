inline void build_link(int root,int n){
    pa[root]=-1;
    for(int i=1;i<=n;++i){/*假設節點編號是1~n*/
        if(~pa[i]&&max_son[pa[i]]==i)continue;
        for(int j=i;j!=-1;j=max_son[j])link_top[j]=i;
    }
}
inline int find_lca(int a,int b){
    while(link_top[a]!=link_top[b]){
        if(dep[link_top[a]]>dep[link_top[b]])a=pa[link_top[a]];
        else b=pa[link_top[b]];
    }
    return dep[a]<dep[b]?a:b;
}