#define lowbit(x) (x&-x)
int bit[MAXN],n;
void modify(int x,int d){
    // A[x] += d
    for(;x<=n;x+=lowbit(x)) bit[x] += d;
}
long long query(int x){
    // 查詢[1~x]的總和
    long long sum=0;
    for(;x;x-=lowbit(x)) sum += bit[x];
    return sum;
}