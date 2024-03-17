#include <bits/stdc++.h>
using namespace std;

void search(string pat, string txt) {
    int pat_length = pat.length();
    int txt_length = txt.length();

    for (int i = 0; i <= txt_length - pat_length; i++) {
        int j;
        for (j = 0; j < pat_length; j++) {
            if (txt[i + j] != pat[j]) {
                break;
            }
        }
        if (j == pat_length) {
            cout << "Pattern found at index " << i << endl;
        }
    }
    // Time Complexity: O((n - m + 1) * m)
    // Auxiliary Space: O(1)
    // quadratic time complexity
}

void improved_search(string pat, string txt) {
    int pat_length = pat.length();
    int txt_length = txt.length();

    int i = 0;
    while (i <= txt_length - pat_length) {
        int j;
        for (j = 0; j < pat_length; j++) {
            if (txt[i + j] != pat[j]) {
                break;
            }
        }
        if (j == pat_length) {
            cout << "Pattern found at index " << i << endl;
            i = i + pat_length;
        } else if (j == 0) {
            i = i + 1; 
            //j == 0 means I got a mismatch at the first character of the pattern, so I move the window by 1
        } else {
            i = i + j; 
            //j != 0  means I got a mismatch after some characters of the pattern, so I move the window by j
        }
    }
    // Used only when all characters of the pattern are distinct
    // Time Complexity: O(n)
    // Auxiliary Space: O(1)
    // linear time complexity
}

int main() {
    string txt = "AABAACAADAABAAABAA";
    string pat = "AABA";
    search(pat, txt);
    return 0;
}