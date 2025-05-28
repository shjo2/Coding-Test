#include <bits/stdc++.h>

using namespace std;

struct Pos{
    int y;
    int x;
};

int m, n;
vector<int> ret;
vector<vector<int>> board;
vector<vector<bool>> visited;
int dc[4] = {-1, 0, 1, 0};
int dr[4] = {0, 1, 0, -1};

int bfs(int y, int x){
    queue<Pos> q;
    q.push({y, x});
    visited[y][x] = true;
    int size = 0;

    while(!q.empty()){
        Pos now = q.front();
        q.pop();
        size++;

        for(int i = 0; i < 4; i++){
            int nx = now.x + dr[i];
            int ny = now.y + dc[i];
            
            if(ny >= 0 && ny < m && nx >= 0 && nx < n){
                if(board[ny][nx] == 0 && !visited[ny][nx]){
                    visited[ny][nx] = true;
                    q.push({ny, nx});
                }
            }
        }
    }

    return size;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int K;
    cin >> m >> n >> K;

    board.resize(m, vector<int>(n, 0));
    visited.resize(m, vector<bool>(n, false));

    for(int i = 0; i < K; i++){
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        for(int j = y1; j < y2; j++){
            for(int k = x1; k < x2; k++){
                board[j][k] = 1;
            }
        }
    }

    vector<int> areas;
    int count = 0;

    for(int r = 0; r < m; r++){
        for(int c = 0; c < n; c++){
            if(board[r][c] == 0 && !visited[r][c]){
                ret.push_back(bfs(r, c));
            }
        }
    }

    sort(ret.begin(), ret.end());
    cout << ret.size() << '\n';
    for(int a : ret) cout << a << " "; 

    return 0;
}