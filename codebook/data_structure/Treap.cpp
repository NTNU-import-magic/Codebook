struct node{
    node *l,*r;
    int key,pri,size;
    node(int k):l(0),r(0),key(k),pri(rand()),size(1){}
    void up();
};
void node::up(){
    size=1;
    if(l)size+=l->size;
    if(r)size+=r->size;
}
node *merge(node *a,node *b){
    if(!a||!b)return a?a:b;
    if(a->pri<b->pri){
        a->r=merge(a->r,b);
        a->up();
        return a;
    }else{
        b->l=merge(a,b->l);
        b->up();
        return b;
    }
}
void split(node *o,node *&a,node *&b,int k){
    if(!o)a=b=0;
    else{
        if( o->key < k ){
            a=o;
            split(o->r,a->r,b,k);
        }else{
            b=o;
            split(o->l,a,b->l,k);
        }
        o->up();
    }
}
bool erase(node *&o,int k){
    if(!o)return 0;
    if( o->key == k ){
        node *t = o;
        o = merge(o->l,o->r);
        delete t;
        return 1;
    }
    node *&t= k < o->key ? o->l : o->r;
    if(erase(t,k))return o->up(),1;
    else return 0;
}
inline int size(node *o){
    return o ? o->size : 0;
}
int Rank(node *&root,int key){
    node *a, *b;
    split(root,a,b,key);
    int res = size(a);
    root = merge(a,b);
    return res;
}