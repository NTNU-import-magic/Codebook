int CRT(int a[], int m[], int n) {
    int M = 1, ans = 0;
    for(int i = 1; i <= n; ++i) M *= m[i];
    for(int i = 1; i <= n; ++i) {
        int x, y;
        int Mi = M / m[i];
        exgcd(Mi, m[i], x, y);
        ans = (ans + Mi * x * a[i]) % M;
    }
    if(ans < 0) ans += M;
    return ans;
}