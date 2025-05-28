#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> adj_list;
int root_node = -1;
vector<bool> is_deleted;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    adj_list.resize(n);
    is_deleted.resize(n, false);

    for(int i = 0; i < n; i++){
        int parent;
        cin >> parent;
        if(parent == -1){
            root_node = i;
            continue;
        }else{
            adj_list[parent].push_back(i);
        }
    }

    int node_delete;
    cin >> node_delete;

    if(node_delete == root_node){
        cout << 0 << '\n';
        return 0;
    }

    stack<int> stk;
    stk.push(node_delete);
    is_deleted[node_delete] = true;
    while(!stk.empty()){
        int node = stk.top();
        stk.pop();
        for(int child : adj_list[node]){
            is_deleted[child] = true;
            stk.push(child);
        }
    }

    int leaf_count = 0;
    for(int i = 0; i < n; i++){
        if(!is_deleted[i]){
            bool is_leaf = true;
            for(int child : adj_list[i]){
                if(!is_deleted[child]){
                    is_leaf = false;
                    break;
                }
            }
            if(is_leaf){
                leaf_count++;
            }
        }
    }

    cout << leaf_count << '\n';

    return 0;
}