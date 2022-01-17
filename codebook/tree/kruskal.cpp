struct edge {
    int u, v, w;
    bool operator < (const edge &r) const {
        return w < r.w;
    }
};
int vn, en; // vertex num, edge num
vector<edge> ve;
vector<int> dsu;
int Find(int x) {
    if(x == dsu[x]) return x;
    return dsu[x] = Find(dsu[x]);
}
bool Union(int x, int y) {
    int a = Find(x), b = Find(y);
    if(a != b) {
        dsu[a] = b;
        return true;
    }
    return false;
}
int Kruskal() {
    for(int i = 0; i < vn; ++i) dsu.push_back(i);
    sort(ve.begin(), ve.end());
    int cnt = 0, ans = 0;
    for(int i = 0; i < en && cnt < vn; ++i) {
        if(Union(ve[i].u, ve[i].v)) {
            ans += ve[i].w;
            ++cnt;
        }
    }
    return ans;
}
