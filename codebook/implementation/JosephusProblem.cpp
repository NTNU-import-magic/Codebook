/// n 個人，查 m 個數
int JosephusProblem(int n, int m) {
    if(n<1 || m<1) return -1;
    vector<int> f(n+1, 0);
    for(unsigned i=2; i<=n; ++i)
        f[i] = (f[i-1]+m) % i;
    return f[n];
}