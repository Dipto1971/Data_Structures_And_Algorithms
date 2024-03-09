#include <bits/stdc++.h>
using namespace std;

void generateSubsets(string s, string current, int i){
    if(i == s.length()){
        cout << current << endl;
        return;
    }
    generateSubsets(s, current, i+1);
    generateSubsets(s, current + s[i], i+1);
}

int main(){
    string s = "abc";
    generateSubsets(s, "", 0);
    return 0;
}