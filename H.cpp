#include <bits/stdc++.h>
using namespace std;

const int MOD = 998244353;

int64_t power(int64_t base, int64_t exp) {
    base %= MOD;
    int64_t result = 1;
    while (exp > 0) {
        if (exp & 1) result = (result * base) % MOD;
        base = (base * base) % MOD;
        exp >>= 1;
    }
    return result;
}

int64_t solve(int N, int M, int K) {

    int64_t horizontal_edges = (N - 1) * M;
    int64_t vertical_edges = N * (M - 1);
    int64_t total_edges = horizontal_edges + vertical_edges;
    
    int64_t result = K;
    result = (result * power(K - 1, total_edges)) % MOD;
    
    return result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int T;
    cin >> T;
    
    while (T--) {
        int N, M, K;
        cin >> N >> M >> K;
        cout << solve(N, M, K) << "\n";
    }
    
    return 0;
}