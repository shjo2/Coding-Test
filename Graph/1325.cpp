#include <bits/stdc++.h>

using namespace std;

vector<int> adj[10001];
bool visited[10001];

int bfs(int start, int total){
    queue<int> q;

    for(int i = 1; i <= total; i++){
        visited[i] = false;
    }

    q.push(start);
    visited[start] = true;
    int count = 1;

    while(!q.empty()){
        int current = q.front();
        q.pop();

        for(int i : adj[current]){
            if(!visited[i]){
                visited[i] = true;
                q.push(i);
                count ++;
            }
        }
    }
    return count;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n >> m;

    for(int i = 0; i < m; i ++){
        int a, b;
        cin >> a >> b;
        adj[b].push_back(a);
    }

    vector<int> counts(n + 1, 0);
    int max_num = 0;

    for(int i = 1; i <= n; i++){
        counts[i] = bfs(i, n);
        if(counts[i] > max_num){
            max_num = max(max_num, counts[i]);
        }
    }

    vector<int> result;
    for(int i = 1; i <= n; i++){
        if(counts[i] == max_num){
            result.push_back(i);
        }
    }

    if (!result.empty()) {
        for (size_t i = 0; i < result.size() - 1; ++i) { 
            cout << result[i] << " ";
        }
        cout << result.back();
    }
    cout << "\n";

    return 0;
}