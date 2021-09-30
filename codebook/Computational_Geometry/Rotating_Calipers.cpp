long long rotatingClaiper(vector<PT> p){ //計算最遠點對距離的平方
    int n=p.size(), t=1;
    long long ans=0;
    p.push_back(p[0]);
    for(int i=0;i<n;i++){
        PT now=p[i+1]-p[i]; //當前這條線的方向向量
        //找出距離邊 (p[i],p[i+1]) 最遠的點 p[t]
        while( now.cross(p[t+1]-p[i]) > now.cross(p[t]-p[i]) ) t=(t+1)%n;
        ans = max(ans, max((p[i]-p[t]).abs2(), (p[i+1]-p[t+1]).abs2()));
        //其實可以簡化成： ans = max(ans, (p[i]-p[t]).abs2() );
        //想一想為什麼?!
    }
    return ans;
}