int exgcd(int a, int b, int &x, int &y) {
    if(b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    int r = exgcd(b, a % b, x, y);
    int t = x;
    x = y;
    y = t - a / b * y;
    return r;
}
int modInverse(int n, int P) {
    int x, y;
    exgcd(n, P, x, y);
    return (P + x % P) % P;
}