#include <bits/stdc++.h>
using namespace std;

const int MOD = 998244353;

// Fast modular exponentiation
int64_t power(int64_t base, int64_t exp, int64_t modulus) {
    base %= modulus;
    int64_t result = 1;
    while (exp > 0) {
        if (exp & 1) result = (result * base) % modulus;
        base = (base * base) % modulus;
        exp >>= 1;
    }
    return result;
}

// Modular multiplicative inverse using Fermat's little theorem
int64_t mod_inverse(int64_t a, int64_t m) {
    return power(a, m-2, m);
}

// Calculate nCr modulo MOD
int64_t nCr(int n, int r) {
    if (r > n) return 0;
    if (r == 0 || r == n) return 1;
    
    vector<int64_t> fact(n + 1);
    fact[0] = 1;
    for (int i = 1; i <= n; i++) {
        fact[i] = (fact[i-1] * i) % MOD;
    }
    
    return (fact[n] * mod_inverse((fact[r] * fact[n-r]) % MOD, MOD)) % MOD;
}

void solve(int N) {
    vector<int64_t> red(N), green(N);
    
    // Read weights of red and green apples
    for (int i = 0; i < N; i++) cin >> red[i];
    for (int i = 0; i < N; i++) cin >> green[i];
    
    vector<int64_t> result(N + 1);
    
    // For each K from 1 to N
    for (int K = 1; K <= N; K++) {
        int64_t P = 0, Q = power(2, K, MOD);
        
        // Calculate expected value for selecting K boxes
        for (int mask = 0; mask < (1 << N); mask++) {
            if (__builtin_popcount(mask) != K) continue;
            
            int64_t sum = 0;
            // For each selected box
            for (int j = 0; j < N; j++) {
                if (mask & (1 << j)) {
                    // Add both red and green apple weights with probability 1/2
                    sum = (sum + ((red[j] + green[j]) * mod_inverse(2, MOD))) % MOD;
                }
            }
            
            // Add to numerator
            P = (P + sum) % MOD;
        }
        
        // Calculate final result as P * Q^(-1)
        result[K] = (P * mod_inverse(Q, MOD)) % MOD;
    }
    
    // Print results
    for (int i = 1; i <= N; i++) {
        cout << result[i];
        if (i < N) cout << " ";
    }
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N;
    cin >> N;
    solve(N);
    
    return 0;
}