#include <bits/stdc++.h>
using namespace std;

/* 
      LPS -Array : concept is the longest prefix which matches the suffix.
      KMP Algorithm for Pattern Matching
*/

// Function to compute the LPS array
void computeLPSArray(string pat, int M, vector<int>& lps) {
    int len = 0; // length of the previous longest prefix suffix
    lps[0] = 0; // lps[0] is always 0

    int i = 1;
    while (i < M) {
        if (pat[i] == pat[len]) {
            len++;
            lps[i] = len;
            i++;
        } else {
            if (len != 0) {
                len = lps[len - 1];
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }
}

// KMP search algorithm
void KMPSearch(string pat, string txt) {
    int M = pat.length();
    int N = txt.length();

    // Create lps[] that will hold the longest prefix suffix values for pattern
    vector<int> lps(M);

    // Preprocess the pattern (calculate lps[] array)
    computeLPSArray(pat, M, lps);

    int i = 0; // index for txt[]
    int j = 0; // index for pat[]
    while (i < N) {
        if (pat[j] == txt[i]) {
            j++;
            i++;
        }

        if (j == M) {
            cout << "Found pattern at index " << i - j << endl;
            j = lps[j - 1];
        } else if (i < N && pat[j] != txt[i]) {
            if (j != 0) {
                j = lps[j - 1];
            } else {
                i++;
            }
        }
    }
}

int main() {
    string txt = "ABABDABACDABABCABAB";
    string pat = "ABABCABAB";
    KMPSearch(pat, txt);
    return 0;
}