const int N = 100, W = 100000;
int cost[N], weight[N], c[W + 1];
void knapsack(int n, int w) {
    memset(c, 0, sizeof(c));
    for (int i = 0; i < n; ++i)
        for (int j = w; j - weight[i] >= 0; --j) // 0/1 背包
        // for (int j = weight[i]; j <= w; ++j) 無限背包
            c[j] = max(c[j], c[j - weight[i]] + cost[i]);
    cout << "最高的價值為" << c[w];
}