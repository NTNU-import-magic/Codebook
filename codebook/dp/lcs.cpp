// DP
const int N1 = 7, N2 = 5;
int s1[N1+1] = {0, 2, 5, 7, 9, 3, 1, 2};
int s2[N2+1] = {0, 3, 5, 3, 2, 8};
int length[N1+1][N2+1];
int LCS() {
    for (int i=0; i<=N1; i++) length[i][0] = 0;
    for (int j=0; j<=N2; j++) length[0][j] = 0;
    for (int i=1; i<=N1; i++)
        for (int j=1; j<=N2; j++)
            if (s1[i] == s2[j]) length[i][j] = length[i-1][j-1] + 1;
            else length[i][j] = max(length[i-1][j], length[i][j-1]);
    return length[N1][N2];
}
// Hunt-Szymanski Algorithm
int LCS(string &s1, string &s2) {
    vector<int> p[128]; // 假設字元範圍為 0 ~ 127
    for (int i = 0; i < s2.size(); ++i)
        p[s2[i]].push_back(i);
    vector<int> v;
    v.push_back(-1);
    for (int i = 0; i < s1.size(); ++i)
        for (int j = p[s1[i]].size() - 1; j >= 0; --j) {
            int n = p[s1[i]][j];
            if (n > v.back()) v.push_back(n);
            else *lower_bound(v.begin(), v.end(), n) = n;
        }
    return v.size() - 1;
}