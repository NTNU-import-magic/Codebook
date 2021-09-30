struct vec{
    int x,y;
    vec operator-(vec a){return vec{x-a.x,y-a.y};}
    int cross(vec a){return x*a.y-y*a.x;}
};
bool comp(const vec &a, const vec &b){return a.x < b.x || (a.x == b.x && a.y < b.y);}
vector<vec> &convex(vector<vec> &pt){
    sort(pt.begin(),pt.end(),comp);
    vector<vec> &conv = *(new vector<vec>);
    int top=0;
    for(size_t i=0;i<pt.size();i++){ // lower hull
        while(top >= 2 && (conv[top-1]-conv[top-2]).cross(pt[i]-conv[top-2]) <= 0){
            conv.pop_back();
            top--;
        }
        conv.emplace_back(pt[i]); top++;
    }
    for(int i=int(pt.size())-2,t=top+1;i>=0;i--){// upper hull
        while(top >= t && (conv[top-1]-conv[top-2]).cross(pt[i]-conv[top-2]) <= 0){
            conv.pop_back();
            top--;
        }
        conv.emplace_back(pt[i]); top++;
    }
    if(pt.size()>1){conv.pop_back();}
    return conv;
}
double shoe_lace(vector<vec> &conv){
    int sum = 0;
    int sz = int(conv.size());
    for(int i = 0 ; i < sz ; ++i){
        sum += (conv[i].cross(conv[(i+1)%sz]));
    }
    return double(abs(sum))/double(2);
}