#include <bits/stdc++.h>

using namespace std;

int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> board(n, vector<int>(m));
    for(int i = 0; i < n; i ++){
        for(int j = 0; j < m; j++){
            cin >> board[i][j];
        }
    }

    int time = 0;
    int cheese_count_previous = 0;

    while(true){
        int cheese_count_hour = 0;
        bool cheese_exist = false;

        for(int i = 0; i < n; i ++){
            for(int j = 0; j < m; j++){
                if(board[i][j] == 1){
                    cheese_count_hour ++;
                    cheese_exist = true;
                }
            }
        }

        if(!cheese_exist){
            break;
        }

        cheese_count_previous = cheese_count_hour;

        vector<vector<bool>> visited_air(n, vector<bool>(m, false));
        queue<pair<int, int>> q;
        q.push({0, 0});
        visited_air[0][0] = true;

        while(!q.empty()){
            int y = q.front().first;
            int x = q.front().second;
            q.pop();

            for(int i = 0; i < 4; i ++){
                int ny = y + dy[i];
                int nx = x + dx[i];

                if(ny < 0 || ny >= n || nx < 0 || nx >= m){
                    continue;
                }

                if(visited_air[ny][nx] || board[ny][nx] == 1){
                    continue;
                }

                visited_air[ny][nx] = true;
                q.push({ny, nx});
            }
        }

        vector<pair<int, int>> melt_cheese;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(board[i][j] == 1){
                    int air_count = 0;
                    for(int dir = 0; dir < 4; dir++){
                        int ny_adj = i + dy[dir];
                        int nx_adj = j + dx[dir];

                        if(ny_adj < 0 || ny_adj >= n || nx_adj < 0 || nx_adj >= m){
                            continue;
                        }

                        if(visited_air[ny_adj][nx_adj]){
                            air_count++;
                        }
                    }

                    if(air_count >= 1){
                        melt_cheese.push_back({i, j});
                    }
                }
            }
        }

        if(!melt_cheese.empty()){
            time++;
            for(auto& cheese : melt_cheese){
                board[cheese.first][cheese.second] = 0;
            }
        } else if(cheese_exist){
            break;
        }
    }

    cout << time << '\n';
    cout << cheese_count_previous << '\n';

    return 0;
}