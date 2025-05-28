#include <bits/stdc++.h>

using namespace std;

int main(){
    vector<int> v(9);

    for(int i = 0; i < v.size(); i++){
        cin >> v[i];
    }

    sort(v.begin(), v.end());

    do{
        int sum = 0;

        for(int i = 0; i < 7; i++)
            sum += v[i];

        if(sum == 100){
            sort(v.begin(), v.begin() + 7);

            for(int i = 0; i < 7; i++)
                cout << v[i] << '\n';
            break;
        }
    }while(next_permutation(v.begin(), v.end()));
    
    return 0;
}