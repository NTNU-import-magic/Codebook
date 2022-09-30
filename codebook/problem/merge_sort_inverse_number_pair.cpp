#define MAX 100000
int tmp[MAX];
long long mergeSort(int *arr, unsigned len){
    if(len <= 1) return 0;
    unsigned llen = len /2, rlen = len - llen;
    int *left = arr, *right = arr+llen;
    long long ret = mergeSort(left,llen) + mergeSort(right, rlen);
    unsigned li=0,ri=0,i=0;
    long long flag=0;
    while(li < llen && ri < rlen){
        if(left[li] <= right[ri]){
            tmp[i++] = left[li++];
            ret += flag;
        }
        else{
            tmp[i++] = right[ri++];
            flag++;
        }
    }
    while(li < llen){
        tmp[i++] = left[li++];
        ret += flag;
    }
    while(ri < rlen){
        tmp[i++] = right[ri++];
        // flag++;
    }
    memcpy(arr,tmp,sizeof(int)*len);
    return ret;
}