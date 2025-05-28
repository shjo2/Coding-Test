#include <bits/stdc++.h>

using namespace std;

struct Pos{
    int y, x;
};

int n, m;
int adj[101][101];
int dist[101][101];
int dc[4] = {-1, 0, 1, 0};
int dr[4] = {0, 1, 0, -1};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    
    for(int i = 0; i < n; i++){
        string str;
        cin >> str;
        for(int j = 0; j < m; j++){
            adj[i][j] = str[j] - '0';
        }
    }    

    queue<Pos> q;

    if(adj[0][0] == 1){
        q.push({0, 0});
        dist[0][0] = 1;
    }

    while(!q.empty()){
        Pos nowPos = q.front();
        q.pop();
        
        for(int i = 0; i < 4; i++){
            int ny = nowPos.y + dc[i];
            int nx = nowPos.x + dr[i];

            if(ny < 0 || ny >= n || nx < 0 || nx >= m){
                continue;
            }

            if(adj[ny][nx] == 1 && dist[ny][nx] == 0){
                dist[ny][nx] = dist[nowPos.y][nowPos.x] + 1;
                q.push({ny, nx});
            }
        }
    }

    cout << dist[n - 1][m - 1] << '\n';

    return 0;
}