/*Exercise 5:
Write a program that compresses a string by deleting all space characters in the string.
Solve the problem using Queue*/

#include <bits/stdc++.h>
using namespace std;

string compressedStr(string s) {
    string cmprsdstr = "";
    queue<char> q;

    for (char ch : s) {
        if (ch != ' ') {
            q.push(ch);
        }
    }

    while (!q.empty()) {
        cmprsdstr += q.front();
        q.pop();
    }

    return cmprsdstr;
}

int main() {
    cout << "Enter the string: ";
    string s;
    getline(cin, s);

    string compressedString = compressedStr(s);
    cout << "Compressed string: " << compressedString << endl;

    return 0;
}
