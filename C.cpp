#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solve() {
    long long int n, k;
    cin >> n >> k;
    vector<vector<long long int>> xy(n, vector<long long int>(2));
    for (long long int i = 0; i < n; ++i) {
        cin >> xy[i][0] >> xy[i][1];
    }

    long long int ans = 0;
    vector<long long int> last_watered(n, 0);

    for (long long int day = 1; day <= k; ++day) {
        for (long long int i = 0; i < n; ++i) {
            if (day - last_watered[i] > xy[i][0]) {
                return -1;
            }
            if (day - last_watered[i] == xy[i][0]) {
                last_watered[i] = day;
                ans++;
            }
        }
    }
    return ans;
}

int main() {
    int t;
    cin >> t;
    for (long long int i = 1; i <= t; ++i) {
        long long int result = solve();
        if (result == -1) {
            cout << "Case " << i << ": " << "0" << endl;
        }
        else{
            cout << "Case " << i << ": " << result << endl;
        }

    }
    return 0;
}
