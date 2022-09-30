#define lowbit(x) (x&-x)
using ll = long long;
struct BIT{
    vector<ll> v;
    void modify(ll x,ll val){
        for(;x<v.size();x+=lowbit(x))
            v[x]+=val;
    }
    ll query(ll x){
        ll t=0;
        for(;x;x-=lowbit(x))
            t+=v[x];
        return t;
    }
};
int main(){
    ll cnt=0,ans=0,rnk=1,num=1;
    BIT sum;
    vector<ll> v(n); // n: 長度
    set<ll> s;
    map<ll,ll> m;
    for(ll i=0;i<n;i++) cin>>v[i],s.insert(v[i]);
    for(auto e:s) m[e]=rnk++;
    for(auto &e:v) e=m[e];
    sum.v.resize(s.size()+1,0);
    for(ll i=0;i<n;i++){
        ans+=cnt++-sum.query(v[i]);
        sum.modify(v[i],1);
    } cout<<ans<<'\n';
}