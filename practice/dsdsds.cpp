#include <bits/stdc++.h>
using namespace std;

int alphabetToNum(char c) {
    if (c >= 'a' && c <= 'z') {
        return (c - 'a' + 1) * 100;
    }
    else if (c >= 'A' && c <= 'Z') {
        return (c - 'A' + 1) * 10000;
    }
    else if (c >= '0' && c <= '9') {
        return c - '0';
    }
    else {
        return 10000;
    }
}

int main() {
    string s = "111BBBccc!@#$^*";

    int result = 0;
    for (char c : s) {
        result += alphabetToNum(c);
    }

    cout << result << endl;

    return 0;
}
