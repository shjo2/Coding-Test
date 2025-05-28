#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int H, W;
    cin >> H >> W;

    char map[H][W];
    for(int i = 0; i < H; i++){
        for(int j = 0; j < W; j++){
            cin >> map[i][j];
        }
    }

    int result[H][W];
    for(int i = 0; i < H; i++){
        int timer = -1;
        for(int j = 0; j < W; j++){
            if(map[i][j] == 'c'){
                result[i][j] = 0;
                timer = 0;
            }
            else{
                if(timer != -1){
                timer++;
                result[i][j] = timer;
                }
                else{
                    result[i][j] = -1;
                }
            }
        }
    }

    for(int i = 0; i < H; i++){
        for(int j = 0; j < W; j++){
            cout << result[i][j] << " ";
        }
        cout << '\n';
    }

    return 0;
}