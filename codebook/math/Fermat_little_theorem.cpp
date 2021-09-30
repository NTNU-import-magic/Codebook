LL pow(LL a,LL p,LL mod){
    if(a%mod==0) return 0;
    LL ret=1ll%mod;
    for(LL cur=a;p;cur=cur*cur%mod,p>>=1)
        if(p&1ll)
            ret=ret*cur%mod;
    return ret;
}
int main(){
    const LL prime=11;
    for(LL a=1, inva;a<prime;++a){
        inva=pow(a,prime-2,prime);
        printf("a=%2lld, a^1=a^(p-2)=%2lld,a*a^(p-2)=%lld\n",a,inva,a*inva%prime);
    }
}