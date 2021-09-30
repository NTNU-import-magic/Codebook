class StTree{
private:
    long long l,r,m;
    StTree *lchild, *rchild;
public:
    int val;
    StTree(long long l,long long r){this->l = l; this->r = r; this->m = (l+r)/2; this->val = 0;this->lchild=nullptr;this->rchild=nullptr;};
    void modify(long long i){
        if(l == r && i == l){
            val++;
            return;
        }
        if(i > m){
            if(rchild == nullptr) rchild = new StTree(m+1,r);
            rchild->modify(i);
        }
        else{
            if(lchild == nullptr) lchild = new StTree(l,m);
            lchild->modify(i);
        }
        val = ((lchild != nullptr)?lchild->val:0) + ((rchild != nullptr)?rchild->val:0);
    }
    int query(long long L,long long R){
        if(l >= L && r <= R) return val;
        if(l < L && r > R) return 0;
        return ((lchild != nullptr)?lchild->query(L,R):0) + ((rchild != nullptr)?rchild->query(L,R):0);
    }
};