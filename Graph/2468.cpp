#include <bits/stdc++.h>

using namespace std;

struct Pos{
    int y;
    int x;
};

int n;
vector<vector<int>> board;
vector<vector<bool>> visited;
int dc[4] = {-1, 0, 1, 0};
int dr[4] = {0, 1, 0, -1};

void bfs(int r, int c, int rain_height){
    queue<Pos> q;
    q.push({r, c});
    visited[r][c] = true;

    while(!q.empty()){
        Pos now = q.front();
        q.pop();

        for(int i = 0; i < 4; i++){
            int ny = now.y + dc[i];
            int nx = now.x + dr[i];

            if(ny >= 0 && ny < n && nx >= 0 && nx < n && !visited[ny][nx] && board[ny][nx] >= rain_height){
                visited[ny][nx] = true;
                q.push({ny, nx});
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;

    board.resize(n, vector<int>(n));
    int max_height = 0;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> board[i][j];
            max_height = max(max_height, board[i][j]);
        }
    }

    int max_safe_areas = 0;

    for(int rain_height = 0; rain_height <= max_height; rain_height++){
        int safe_areas_count = 0;
        visited.assign(n, vector<bool>(n, false));

        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(!visited[i][j] && board[i][j] >= rain_height){
                    bfs(i, j, rain_height);
                    safe_areas_count++;
                }
            }
        }
        max_safe_areas = max(max_safe_areas, safe_areas_count);
    }

    cout << max_safe_areas << '\n';

    return 0;
}