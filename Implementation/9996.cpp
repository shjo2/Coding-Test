#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    string pattern;
    cin >> pattern;
    
    vector<string> input_string;

    for(int i = 0; i < n; i++){
        string temp;
        cin >> temp;
        input_string.push_back(temp);
    }

    // 첫 글자와 마지막 글자 체크
    int index = pattern.find("*");
    string prefix = pattern.substr(0, index);
    string suffix = pattern.substr(index + 1);

    for(const auto& word : input_string){
        if(word.length() >= prefix.length() + suffix.length() && prefix == word.substr(0, prefix.size()) && suffix == word.substr(word.size() - suffix.size())){
            cout << "NE" << '\n';
        }
        else{
            cout << "DA" << '\n';
        }
    }

    return 0;
}