// 最大獨立集=所有頂點數-最小頂點覆蓋
int nx, ny;             // X的點數目、Y的點數目
int mx[100], my[100];   // X各點的配對對象、Y各點的配對對象
bool vy[100];           // 記錄Graph Traversal拜訪過的點
bool adj[100][100];
bool DFS(int x){
    for (int y=0; y<ny; ++y)
        if (adj[x][y] && !vy[y]){
            vy[y] = true;
            if (my[y] == -1 || DFS(my[y])){
                mx[x] = y; my[y] = x;
                return true;
            }
        }
    return false;
}
int bipartite_matching(){
    memset(mx, -1, sizeof(mx));
    memset(my, -1, sizeof(my));
    int c = 0;
    for (int x=0; x<nx; ++x){
            memset(vy, false, sizeof(vy));
            if (DFS(i)) c++;
        }
    return c;
}