#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
const int dx[] = {-1, 1, 0, 0, 0, 1, 1, -1, -1};
const int dy[] = {0, 0, -1, 1, 0, 1, -1, 1, -1};

struct State {
    int x, y;
    bool has_diffuser;
    int cost;
    
    bool operator>(const State& other) const {
        return cost > other.cost;
    }
};

void solve() {
    int N, M, X, Y;
    cin >> N >> M >> X >> Y;
    
    vector<string> grid(N);
    for (int i = 0; i < N; i++) {
        cin >> grid[i];
    }
    
    vector<vector<int>> cell_cost(N, vector<int>(M));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> cell_cost[i][j];
        }
    }
    
    vector<vector<vector<int>>> dp(N, vector<vector<int>>(M, vector<int>(2, INF)));
    
    priority_queue<State, vector<State>, greater<State>> pq;
    
    pq.push({0, 0, false, 0});
    dp[0][0][0] = 0;
    
    while (!pq.empty()) {
        State curr = pq.top();
        pq.pop();
        
        int x = curr.x, y = curr.y;
        bool has_diff = curr.has_diffuser;
        
        if (curr.cost > dp[x][y][has_diff]) continue;
        
        for (int dir = 0; dir < 8; dir++) {
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            
            if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
            
            bool is_safe = true;
            if (grid[nx][ny] == '#') {
                if (!has_diff) continue;
                is_safe = false;
            }
            
            int new_cost = curr.cost + cell_cost[nx][ny];
            if (!is_safe) new_cost += Y; // Cost of using diffuser
            
            if (dp[nx][ny][has_diff && is_safe] > new_cost) {
                dp[nx][ny][has_diff && is_safe] = new_cost;
                pq.push({nx, ny, has_diff && is_safe, new_cost});
            }
            
            if (!has_diff && is_safe) {
                new_cost = curr.cost + X + cell_cost[nx][ny];
                if (dp[nx][ny][1] > new_cost) {
                    dp[nx][ny][1] = new_cost;
                    pq.push({nx, ny, true, new_cost});
                }
            }
        }
    }
    
    int result = min(dp[N-1][M-1][0], dp[N-1][M-1][1]);
    if (result == INF) result = -1;
    
    cout << result << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        cout << "Case " << t << ": ";
        solve();
    }
    
    return 0;
}