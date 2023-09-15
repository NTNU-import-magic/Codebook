int euler[3000001];
void getEuler() {
    memset(euler, 0, sizeof(euler));
    euler[1] = 1;
    for(int i = 2; i <= 3000000; i++)
        if(!euler[i])
            for(int j = i; j <= 3000000; j += i) {
                if(!euler[j]) euler[j] = j;
                euler[j] = euler[j] / i * (i - 1);
            }
}