struct Point {float x, y;} p[10], t[10];
bool cmpx(Point i, Point j) {return i.x < j.x;}
bool cmpy(Point i, Point j) {return i.y < j.y;}
float DnC(int L, int R){
    if (L >= R) return 1e9;
    int M = (L + R) / 2;
    float d = min(DnC(L,M), DnC(M+1,R));
    int N = 0;
    for (int i=M;   i>=L && p[M].x - p[i].x < d; --i) t[N++] = p[i];
    for (int i=M+1; i<=R && p[i].x - p[M].x < d; ++i) t[N++] = p[i];
    sort(t, t+N, cmpy);
    for (int i=0; i<N-1; ++i)
        for (int j=1; j<=3 && i+j<N; ++j)
            d = min(d, distance(t[i], t[i+j]));
    return d;
}
float closest_pair(){
    sort(p, p+10, cmpx);
    return DnC(0, N-1);
}