#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector<string> vec(n + 1);
    map<string, int> mp;
    for(int i = 1; i <= n; i++){
        string pokemon;
        cin >> pokemon;
        vec[i] = pokemon;
        mp[pokemon] = i;
    }

    for(int j = 0; j < m; j++){
        string str;
        cin >> str;

        if(isdigit(str[0])){
            int index = stoll(str);
            cout << vec[index] << '\n';
        }
        else{
            cout << mp[str] << '\n';
        }
    }
    
    return 0;
}