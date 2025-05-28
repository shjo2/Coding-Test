#include <bits/stdc++.h>

using namespace std;

int n;
vector<vector<int>> arr;

string quadTree(int y, int x, int size){
    bool isSame = true;
    int first = arr[y][x];
    for(int i = y; i < y + size; i++){
        for(int j = x; j < x + size; j++){
            if(arr[i][j] != first){
                isSame = false;
                break;
            }
        }
        if(!isSame) break;
    }

    if(isSame){
        return string(1, '0' + first);
    }

    string result = "(";
    int half = size / 2;
    result += quadTree(y, x, half);
    result += quadTree(y, x + half, half);
    result += quadTree(y + half, x, half);
    result += quadTree(y + half, x + half, half);
    result += ")";

    return result;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    arr.resize(n, vector<int>(n));

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> arr[i][j];
        }
    }

    cout << quadTree(0, 0, n) << '\n';

    return 0;
}