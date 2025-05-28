#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;

    while(t--){
        int n, m, k;
        cin >> n >> m >> k;

        vector<vector<int>> field(n, vector<int>(m, 0));

        for(int i = 0; i < k; i++){
            int x, y;
            cin >> x >> y;
            field[y][x] = 1;
        }

        int count = 0;
        vector<vector<bool>> visited(n, vector<bool>(m, false));

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(field[i][j] == 1 && !visited[i][j]){
                    count++;

                    queue<pair<int, int>> q;
                    q.push({i, j});
                    visited[i][j] = true;
                    int dy[4] = {-1, 0, 1, 0};
                    int dx[4] = {0, 1, 0, -1};

                    while(!q.empty()){
                        pair<int, int> now = q.front();
                        q.pop();
                        int y = now.first;
                        int x = now.second;

                        for(int i = 0; i < 4; i++){
                            int ny = y + dy[i];
                            int nx = x + dx[i];

                            if(ny < 0 || ny >= n || nx < 0 || nx >= m){
                                continue;
                            }

                            if(field[ny][nx] == 1 && !visited[ny][nx]){
                                q.push({ny, nx});
                                visited[ny][nx] = true;
                            }
                        }
                    }
                }
            }
        }

        cout << count << '\n';
    }

    return 0;
}