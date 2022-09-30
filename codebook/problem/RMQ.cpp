// 單純遞迴並回傳值 (TLE)
// This code will get TLE absolutly
int SRMQ(int l, int r) {
    int mid = l + ((r - l) >> 1);
    if(l + 1 == r || l == r) return min(arr[l], arr[r]);
    else return min(SRMQ(l, mid), SRMQ(mid + 1, r));
}
// Sparse Table (稀疏表、ST 表)
const int max_lg = 20, max_arrlen = 200000;
int Log[max_arrlen + 5], F[max_arrlen + 5][max_lg + 5];
inline void build_logn(void) { // 建立 Log 表
    Log[1] = 0;
    Log[2] = 1;
    for(int i = 3; i < max_arrlen; i++) Log[i] = Log[i / 2] + 1;
    // REP1(i,3,max_arrlen) Log[i]=Log[i/2]+1;
}
inline void build_ST(int n) { // 預處理 ST 表
    REP1(j, 1, max_lg + 1)
    for(int i = 1; i + (1 << j) - 1 <= n; i++)
        F[i][j] = min(F[i][j - 1], F[i + (1 << (j - 1))][j - 1]);
}
inline void init(int n) {
    build_logn();
    REP1(i, 1, n + 1) cin >> F[i][0]; // Input
    build_ST(n);
}
signed main() {
    jizz;
    int n, q, a, b, log_j;
    cin >> n >> q;
    init(n);
    REP(i, q) {
        cin >> a >> b;
        int log_j = Log[b - a + 1];
        cout << min(F[a][log_j], F[b - (1 << log_j) + 1][log_j]) << "\n"; // 兩區間聯集的極值
    }
    return 0;
}
// 動態區間總和/極值（單點修改）
// pull
LL up(LL a, LL b) {
    return a + b; // 求區間總和
    // return min(a,b); // 求區間最小值
    // return max(a,b); // 求區間最大值
}
// 建樹
void buildTree(int l, int r, int idx) {
    if(l == r) {
        Tree[idx] = arr[l];
        return;
    }
    int mid = Mid(l, r);
    buildTree(l, mid, idx * 2 + 2);
    buildTree(mid + 1, r, idx * 2 + 1);
    Tree[idx] = up(Tree[idx * 2 + 2], Tree[idx * 2 + 1]); // 記得 pull
    return;
}
// 詢問
LL Query(int x, int y, int l, int r, int idx) {
    if(x == l && y == r) return Tree[idx];
    int mid = Mid(l, r);
    if(y <= mid) return Query(x, y, l, mid, idx * 2 + 2);
    if(x > mid) return Query(x, y, mid + 1, r, idx * 2 + 1);
    return up(Query(x, mid, l, mid, idx * 2 + 2), Query(mid + 1, y, mid + 1, r, idx * 2 + 1)); // 記得 pull
}
// 單點修改
void Update(int l, int r, int pos, int idx, LL val) {
    if(l == r) {
        Tree[idx] = val;
        return;
    }
    int mid = Mid(l, r);
    if(pos <= mid) Update(l, mid, pos, idx * 2 + 2, val);
    else if(pos > mid) Update(mid + 1, r, pos, idx * 2 + 1, val);
    Tree[idx] = up(Tree[idx * 2 + 2], Tree[idx * 2 + 1]); // 記得 pull
}
// [Dynamic Range Sum Queries] Solution
#define Mid(l,r) (l)+(((r)-(l))>>1)
LL arr[200005], Tree[800005];
LL up(LL a, LL b) {
    return a + b;
}
void buildTree(int l, int r, int idx) {
    if(l == r) {
        Tree[idx] = arr[l];
        return;
    }
    int mid = Mid(l, r);
    buildTree(l, mid, idx * 2 + 2);
    buildTree(mid + 1, r, idx * 2 + 1);
    Tree[idx] = up(Tree[idx * 2 + 2], Tree[idx * 2 + 1]);
    return;
}
LL Query(int x, int y, int l, int r, int idx) {
    if(x == l && y == r) return Tree[idx];
    int mid = Mid(l, r);
    if(y <= mid) return Query(x, y, l, mid, idx * 2 + 2);
    if(x > mid) return Query(x, y, mid + 1, r, idx * 2 + 1);
    return up(Query(x, mid, l, mid, idx * 2 + 2), Query(mid + 1, y, mid + 1, r, idx * 2 + 1));
}
void Update(int l, int r, int pos, int idx, LL val) {
    if(l == r) {
        Tree[idx] = val;
        return;
    }
    int mid = Mid(l, r);
    if(pos <= mid) Update(l, mid, pos, idx * 2 + 2, val);
    else if(pos > mid) Update(mid + 1, r, pos, idx * 2 + 1, val);
    Tree[idx] = up(Tree[idx * 2 + 2], Tree[idx * 2 + 1]);
}
signed main() {
    jizz;
    int n, q, det, k, u, a, b;
    cin >> n >> q;
    REP1(i, 1, n + 1) cin >> arr[i];
    buildTree(1, n, 0);
    while(q--) {
        cin >> det;
        if(det == 1) {
            cin >> k >> u;
            Update(1, n, k, 0, (LL)u);
        }
        else {
            cin >> a >> b;
            LL ans = Query(a, b, 1, n, 0);
            cout << ans << "\n";
        }
    }
    return 0;
}