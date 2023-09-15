const int MAXN = 10000000;
bool check[MAXN + 10];
int phi[MAXN + 10];
int prime[MAXN + 10];
int tot;//素数的个数
void phi_and_prime_table(int N) {
    memset(check, false, sizeof(check));
    phi[1] = 1;
    tot = 0;
    for(int i = 2; i <= N; i++) {
        if( !check[i] ) {
            prime[tot++] = i;
            phi[i] = i - 1;
        }
        for(int j = 0; j < tot; j++) {
            if(i * prime[j] > N)break;
            check[i * prime[j]] = true;
            if( i % prime[j] == 0) {
                phi[i * prime[j]] = phi[i] * prime[j];
                break;
            }
            else {
                phi[i * prime[j]] = phi[i] * (prime[j] - 1);
            }
        }
    }
}