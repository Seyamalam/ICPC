#include <bits/stdc++.h>
using namespace std;

string solve(int N, int P) {
    bool oddius_starts = (P == 1);
    
    if (N == 1) {
        return oddius_starts ? "Oddius" : "Evenius";
    }
    if (N == 2) {
        return oddius_starts ? "Evenius" : "Oddius";
    }
    

    if (N % 2 == 0) {
        return "Evenius";
    } else {
        return "Oddius";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int T;
    cin >> T;
    
    for (int t = 1; t <= T; t++) {
        int N, P;
        cin >> N >> P;
        
        cout << "Case " << t << ": " << solve(N, P) << "\n";
    }
    
    return 0;
}