#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    int good_word_count = 0;
    for(int i = 0; i < n; i++){
        string s;
        cin >> s;

        vector<char> vec;
        for(char ch : s){
            if(!vec.empty() && vec.back() == ch){
                vec.pop_back();
            }
            else{
                vec.push_back(ch);
            }
        }

        if(vec.empty()){
            good_word_count++;
        }
    }
    

    cout << good_word_count << '\n';

    return 0;
}