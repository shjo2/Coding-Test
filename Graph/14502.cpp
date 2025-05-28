#include <bits/stdc++.h>

using namespace std;

int N, M;
vector<vector<int>> mp;
vector<pair<int, int>> space;
int safe_area = 0;

int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};

void bfs(vector<vector<int>>& current_map){
    queue<pair<int, int>> q;

    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            if(current_map[i][j] == 2){
                q.push({i, j});
            }
        }
    }

    while(!q.empty()){
        pair<int, int> current = q.front();
        q.pop();
        int r = current.first;
        int c = current.second;

        for(int i = 0; i < 4; i++){
            int nr = r + dr[i];
            int nc = c + dc[i];

            if (nr >= 0 && nr < N && nc >= 0 && nc < M){
                if(current_map[nr][nc] == 0){
                    current_map[nr][nc] = 2;
                    q.push({nr, nc}); 
                }
            }
        }
    }
}

int calculate_safe_area(vector<vector<int>>& current_map){
    int count = 0;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            if(current_map[i][j] == 0){
                count++;
            }
        }
    }

    return count;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    mp.resize(N, vector<int>(M));

    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cin >> mp[i][j];

            if(mp[i][j] == 0){
                space.push_back({i, j});
            }
        }
    }

    if(space.size() >= 3){
        vector<int> combination(space.size());
        fill(combination.begin(), combination.end(), 1);
        fill(combination.begin() + 3, combination.end(), 0);

        sort(combination.begin(), combination.end());

        do{
            vector<vector<int>> current_map = mp;

            for(int i = 0; i < space.size(); i++){
                if(combination[i] == 1){
                    current_map[space[i].first][space[i].second] = 1;
                }
            }

            bfs(current_map);
            safe_area = max(safe_area, calculate_safe_area(current_map));

        }while(next_permutation(combination.begin(), combination.end()));
    }
    
    cout << safe_area << '\n';

    return 0;
}