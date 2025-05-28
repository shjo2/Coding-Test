#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    int num;
    vector<int> vec(n);
    for(int i = 0; i < n; i++){
        cin >> vec[i];
    }
    
    sort(vec.begin(), vec.end());

    int sum = 0;
    int count = 0;
    int left = 0;
    int right = n - 1;

    while(left < right){
        sum = vec[left] + vec[right];
        if(sum == m){
            count++;
            left++;
            right--;
        }
        else if(sum < m){
            left++;
        }
        else{
            right--;
        }
    }

    cout << count << endl;
    return 0;
}