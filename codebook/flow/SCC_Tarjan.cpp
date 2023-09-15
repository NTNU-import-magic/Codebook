const int MAX_N = 10005;
vector<int> g[MAX_N],sccV[MAX_N];
int tt = 0, dfn[MAX_N], low[MAX_N], vn, en;
stack<int> s;
int belong[MAX_N];
bool in_stack[MAX_N];
int scc = 0;
void dfs(int u, int p)
{
    dfn[u] = low[u] = tt++;
    s.push(u);
    in_stack[u] = true;
    for (int i = 0; i < (int)g[u].size(); i++) {
        const int &v = g[u][i];
        if (dfn[v] == -1) {
            dfs(v, u);
            low[u] = min(low[u], low[v]);
        } else {
            if (in_stack[v])
                low[u] = min(low[u], dfn[v]);
        }
    }
    if (dfn[u] == low[u]) {
        scc++;
        while (1) {
            int v = s.top();
            s.pop();
            belong[v] = scc;
			sccV[scc].push_back(v);
            in_stack[v] = false;
            if (u == v)
                break;
        }
    }
}
void init(){
	tt = scc = 0;
	while(!s.empty()){
		s.pop();
	}
	for(int i=0;i<MAX_N;++i){
		g[i].clear();
		sccV[i].clear();
		dfn[i] = -1;
		low[i] = -1;
		belong[i] = 0;
		in_stack[i] = false;
	}
}
// remember it's direct graph
// for (int i = 1; i <= vn; i++) {
//     if (dfn[i] == -1) {
//         dfs(i, -1);
//     }
// }