// 增广路径是残存网络中一条s到t的路径
// 残存容量是增广路径上能为每条边增加的流量的最大值
// 不断地沿着增广路径增加路径上的流量, 直到残存网络中不再有任何增广路时就找到了最大流
int map[SIZE][SIZE];
int pre[SIZE]; //记录前一个访问的节点
bool visited[SIZE];
int a[SIZE]; //可改进量
bool bfs(int s, int t, int n) {
    memset(a, 0, sizeof(a));
    memset(visited, false, sizeof(visited));
    queue<int> q;
    q.push(s);
    a[s] = INF;
    visited[s] = true;
    while (!q.empty()) {
        int x = q.front();
        q.pop();
        for (int i = 0; i <= n; ++i) //todo
            if (!visited[i] && map[x][i]) {
                visited[i] = true;
                pre[i] = x;
                q.push(i);
                a[i] = min(a[x], map[x][i]);
            }
        if (visited[t])
            return true;
    }
    return false;
}
int maxFlow(int s, int t, int n) {
    int flow = 0;
    while (bfs(s, t, n)) {
        flow += a[t];
        for (int i = t; i != s; i = pre[i]) {
            map[pre[i]][i] -= a[t];
            map[i][pre[i]] += a[t];
        }
    }
    return flow;
}