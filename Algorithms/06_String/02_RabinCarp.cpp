#include <bits/stdc++.h>
using namespace std;

#define d 256

void RBsearch(string pat, string txt, int q) {
    int h = 1;
    int pat_length = pat.length();
    int txt_length = txt.length();
    int i, j;

    for (i = 0; i < pat_length - 1; i++) {
        h = (h * d) % q; // h = (d^(m-1)) % q
        cout << h << " ";
    }
    cout << endl;

    int p = 0; // hash value for pattern
    int t = 0; // hash value for txt
    for (i = 0; i < pat_length; i++) {
        p = (d * p + pat[i]) % q;
        t = (d * t + txt[i]) % q;
    }
    cout << "Hash value for pattern: " << p << endl;
    cout << "Hash value for txt: " << t << endl;
    cout << endl;

    for (i = 0; i <= txt_length - pat_length; i++) {
        if (p == t) {
            for (j = 0; j < pat_length; j++) {
                if (txt[i + j] != pat[j]) {
                    break;
                }
            }
            if (j == pat_length) {
                cout << "Pattern found at index " << i << endl;
            }
        }
        if (i < txt_length - pat_length) {
            t = (d * (t - txt[i] * h) + txt[i + pat_length]) % q;
            if (t < 0) {
                t = t + q;
            }
            cout << "Hash value for txt: " << t << endl;
        }
    }
}

int main() {
    string txt = "abdabcbabc";
    string pat = "abc";
    int q = 101; // A prime number
    RBsearch(pat, txt, q);
    return 0;
}