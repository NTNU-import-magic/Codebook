int price[5] = {5, 2, 6, 11, 17};
bool c[1000+1]; //int c[1000+1];
void change(int m) {
    memset(c, false, sizeof(c));
    c[0] = true;
    for (int i = 0; i < 5; ++i)
        for (int j = price[i]; j <= m; ++j)
            c[j] ||= c[j-price[i]];
            // c[j] += c[j-price[i]];
    if (c[m]) cout << "湊得到";
    else cout << "湊不到";
    // cout << "湊得價位" << m;
    // cout << "湊法總共" << c[m] << "種";
}