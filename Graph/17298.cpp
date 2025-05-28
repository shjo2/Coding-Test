#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    vector<int> arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    vector<int> result(n, -1);
    stack<int> s;
    for(int i = 0; i < n; i++){
        while(!s.empty() && arr[s.top()] < arr[i]){
            result[s.top()] = arr[i];
            s.pop();
        }
        s.push(i);
    }

    for(int i = 0; i < n; i++){
        cout << result[i];
        if(i < n - 1){
            cout << " ";
        }
    }
    cout << '\n';

    return 0;
}