int dist[MAX_V][MAX_V];
for(int k = 0; k < vn; ++k)
    for(int i = 0; i < vn; ++i)
        for(int j = 0; j < vn; ++j)
            dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);