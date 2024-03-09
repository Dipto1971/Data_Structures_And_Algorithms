#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(string s, int start, int end){
    if(start >= end) return true;
    return (s[start] == s[end]) 
    && isPalindrome(s, start+1, end-1);
    // time complexity: O(n)
    // auxiliary space complexity: O(n)
    // Tail recursive? -> No
}

int main(){
    string s = "ababa";
    cout << isPalindrome(s, 0, s.size()-1) << endl;
    return 0;
}