#include <bits/stdc++.h>
using namespace std;

// Function to calculate (base^exp) % mod using fast modular exponentiation
long long modExp(long long base, long long exp, long long mod) {
    long long result = 1;
    base = base % mod;
    while (exp > 0) {
        if (exp & 1)  // If exp is odd
            result = (result * base) % mod;
        exp = exp >> 1;  // exp = exp / 2
        base = (base * base) % mod;
    }
    return result;
}

// Function to calculate GCD
long long gcd(long long a, long long b) {
    return (b == 0) ? a : gcd(b, a % b);
}

// Function to find multiplicative inverse of e under modulo phi (Extended Euclidean Algorithm)
long long modInverse(long long e, long long phi) {
    long long t = 0, newt = 1;
    long long r = phi, newr = e;
    while (newr != 0) {
        long long q = r / newr;
        tie(t, newt) = make_tuple(newt, t - q * newt);
        tie(r, newr) = make_tuple(newr, r - q * newr);
    }
    if (r > 1) return -1; // No inverse exists
    if (t < 0) t += phi;
    return t;
}

int main() {
    // Step 1: Choose two primes
    long long p = 61, q = 53; // Example primes
    long long n = p * q;      // n = 3233
    long long phi = (p - 1) * (q - 1); // phi = 3120

    // Step 2: Choose public key e (1 < e < phi, gcd(e, phi) = 1)
    long long e = 17; // Common choice
    if (gcd(e, phi) != 1) {
        cout << "Invalid e, must be coprime with phi" << endl;
        return 0;
    }

    // Step 3: Find private key d (mod inverse of e mod phi)
    long long d = modInverse(e, phi);

    cout << "Public Key (e, n): (" << e << ", " << n << ")" << endl;
    cout << "Private Key (d, n): (" << d << ", " << n << ")" << endl;

    // Step 4: Encrypt a message
    long long msg = 123; // Example plaintext
    cout << "Original Message: " << msg << endl;

    long long encrypted = modExp(msg, e, n);
    cout << "Encrypted Message: " << encrypted << endl;

    // Step 5: Decrypt the message
    long long decrypted = modExp(encrypted, d, n);
    cout << "Decrypted Message: " << decrypted << endl;

    return 0;
}
