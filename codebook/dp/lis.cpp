// DP
const int N = 100;
int s[N], length[N];
int LIS() {
    for (int i=0; i<N; i++) length[i] = 1;
    for (int i=0; i<N; i++)
        for (int j=0; j<i; j++)
            if (s[j] < s[i])
                length[i] = max(length[i], length[j] + 1);
    int l = 0;
    for (int i=0; i<N; i++) l = max(l, length[i]);
    return l;
}
// Robinson-Schensted-Knuth Algorithm
int LIS(vector<int>& s) {
    if (s.size() == 0) return 0;
    vector<int> v;
    v.push_back(s[0]);
    for (int i=1; i<s.size(); ++i) {
        int n = s[i];
        if (n > v.back()) v.push_back(n);
        else *lower_bound(v.begin(), v.end(), n) = n;
    }
    return v.size();
}