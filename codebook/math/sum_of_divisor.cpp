//参考 POJ 1845
//里面有一种求1+p+p^2+p...^3+p^n的方法。
//需要素数筛选和合数分解的程序，需要先调用 getPrime();
long long pow_m(long long a, long long n) {
    long long ret = 1;
    long long tmp = a % MOD;
    while(n) {
        if(n & 1)ret = (ret * tmp) % MOD;
        tmp = tmp * tmp % MOD;
        n >>= 1;
    }
    return ret;
}
//计算1+p+p^2+...+p^n
long long sum(long long p, long long n) {
    if(p == 0)return 0;
    if(n == 0)return 1;
    if(n & 1) {
        return ((1 + pow_m(p, n / 2 + 1)) % MOD * sum(p, n / 2) % MOD) % MOD;
    }
    else return ((1 + pow_m(p, n / 2 + 1)) % MOD * sum(p, n / 2 - 1) + pow_m(p, n / 2) % MOD) % MOD;
}
//返回A^B的约数之和 % MOD
long long solve(long long A, long long B) {
    getFactors(A);
    long long ans = 1;
    for(int i = 0; i < fatCnt; i++) {
        ans *= sum(factor[i][0], B * factor[i][1]) % MOD;
        ans %= MOD;
    }
    return ans;
}