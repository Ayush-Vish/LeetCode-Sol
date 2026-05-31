#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<bool> sieve(int maxN) {
    vector<bool> isPrime(maxN + 1, true);
    isPrime[0] = isPrime[1] = false;
    for (int i = 2; i * i <= maxN; ++i) {
        if (isPrime[i]) {
            for (int j = i * i; j <= maxN; j += i) {
                isPrime[j] = false;
            }
        }
    }
    return isPrime;
}

vector<int> getPrimes(const vector<bool>& isPrime) {
    vector<int> primes;
    for (int i = 2; i < isPrime.size(); ++i) {
        if (isPrime[i]) {
            primes.push_back(i);
        }
    }
    return primes;
}

int countSubtractorization(int N, const vector<int>& primes, const vector<bool>& isPrime) {
    int count = 0;
    for (int p : primes) {
        if (p > N) break;
        int q = N - p;
        if (q < p) break;  // Avoid double counting
        if (isPrime[q]) {
            count++;
        }
    }
    return count;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int T;
    cin >> T;
    
    vector<int> cases(T);
    int maxN = 0;
    for (int& N : cases) {
        cin >> N;
        maxN = max(maxN, N);
    }
    
    vector<bool> isPrime = sieve(maxN);
    vector<int> primes = getPrimes(isPrime);
    
    for (int i = 0; i < T; ++i) {
        int result = countSubtractorization(cases[i], primes, isPrime);
        cout << "Case #" << (i + 1) << ": " << result << '\n';
    }
    
    return 0;
}