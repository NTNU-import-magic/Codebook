getFactors(n);
int ret = n;
for(int i = 0; i < fatCnt; i++) {
    ret = ret / factor[i][0] * (factor[i][0] - 1);
}