typedef long long ll;
typedef pair<int, int> P;
#define PI acos(-1.0)
const int maxn = 1e5 + 100, maxm = 1e5 + 100, inf = 0x3f3f3f3f, mod = 1e9 + 7;
const ll INF = 1e18 + 7;
struct edge {
    int from, to, cap, flow;
};
struct Dinic {
    int n, m, s, t;
    vector<edge>es;
    vector<int>G[maxn];
    bool vis[maxn];
    int dist[maxn], iter[maxn];
    void init(int n, int m) {
        this->n = n;
        this->m = m;
        for(int i = 0; i <= n + 5; i++) G[i].clear();
        es.clear();
    }
    void addedge(int from, int to, int cap) {
        es.push_back((edge) {
            from, to, cap, 0
        });
        es.push_back((edge) {
            to, from, 0, 0
        });
        int x = es.size();
        G[from].push_back(x - 2);
        G[to].push_back(x - 1);
    }
    bool BFS() {
        memset(vis, 0, sizeof(vis));
        queue <int> Q;
        vis[s] = 1;
        dist[s] = 0;
        Q.push(s);
        while(!Q.empty()) {
            int u = Q.front();
            Q.pop();
            for (int i = 0; i < G[u].size(); i++) {
                edge &e = es[G[u][i]];
                if (!vis[e.to] && e.cap > e.flow) {
                    vis[e.to] = 1;
                    dist[e.to] = dist[u] + 1;
                    Q.push(e.to);
                }
            }
        }
        return vis[t];
    }
    int DFS(int u, int f) {
        if(u == t || f == 0) return f;
        int flow = 0, d;
        for(int &i = iter[u]; i < G[u].size(); i++) {
            edge &e = es[G[u][i]];
            if(dist[u] + 1 == dist[e.to] && (d = DFS(e.to, min(f, e.cap - e.flow))) > 0) {
                e.flow += d;
                es[G[u][i] ^ 1].flow -= d;
                flow += d;
                f -= d;
                if (f == 0) break;
            }
        }
        return flow;
    }
    int Maxflow(int s, int t) {
        this->s = s, this->t = t;
        int flow = 0;
        while(BFS()) {
            memset(iter, 0, sizeof(iter));
            flow += DFS(s, inf);
        }
        return flow;
    }

} Dinc;
int in[maxn], out[maxn];
int sign[maxn];
int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    /**有源匯點*/
    int s, t;
    scanf("%d%d", &s, &t);
    memset(in, 0, sizeof(in));
    memset(out, 0, sizeof(out));
    Dinc.init(n, m);
    for (int i = 1; i <= m; i++) {
        int u, v, l, r;
        scanf("%d %d %d %d", &u, &v, &l, &r);
        out[u] += l;
        in[v] += l;
        sign[i] = l;
        Dinc.addedge(u, v, r - l);
    }
    /**最小流限制有源匯點*/
    Dinc.addedge(t, s, inf);
    /**最小流限制，新增源點0，匯點n+1*/
    int all = 0, sum = 0;
    for(int i = 1; i <= n; i++) {
        if(in[i] > out[i]) {
            Dinc.addedge(0, i, in[i] - out[i]);
            all += in[i] - out[i];
        }
        else if(in[i] < out[i]) {
            Dinc.addedge(i, n + 1, out[i] - in[i]);
            sum += (in[i] - out[i]);
        }
    }
    if(Dinc.Maxflow(0, n + 1) != all) puts("NO");
    else {
        puts("YES");
        /**有源匯點*/
        sum = -Dinc.es[2 * m + 1].flow;
        Dinc.es[2 * m + 1].flow = 0;
        Dinc.es[2 * m].flow = 0;
        Dinc.es[2 * m].cap = 0;
        sum += Dinc.Maxflow(s, t);
        printf("%d\n", sum);
        /**無源匯點：可以理解成水管相連，每根水管的水流入量等於流出量，所有水管形成循環*/
        for(int i = 0; i < m * 2; i += 2)
            printf("%d\n", Dinc.es[i].flow + sign[i / 2 + 1]); ///每根水管的流量情況
    }
    return 0;
}
