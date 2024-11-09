#include <bits/stdc++.h>
using namespace std;

struct Wire {
    long long int u, v;
    long long int isp;
    long long int idx;
};

struct Point {
    long long int x, y;
    Point(long long int x = 0, long long int y = 0) : x(x), y(y) {}
};

bool intersect(const Point& p1, const Point& p2, const Point& p3, const Point& p4) {
    auto orientation = [](const Point& p, const Point& q, const Point& r) {
        long long int val = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);
        if (val == 0) return 0;
        return (val > 0) ? 1 : 2;
    };

    auto onSegment = [](const Point& p, const Point& q, const Point& r) {
        return q.x <= max(p.x, r.x) && q.x >= min(p.x, r.x) &&
               q.y <= max(p.y, r.y) && q.y >= min(p.y, r.y);
    };

    int o1 = orientation(p1, p2, p3);
    int o2 = orientation(p1, p2, p4);
    int o3 = orientation(p3, p4, p1);
    int o4 = orientation(p3, p4, p2);

    if (o1 != o2 && o3 != o4) return true;

    if (o1 == 0 && onSegment(p1, p3, p2)) return true;
    if (o2 == 0 && onSegment(p1, p4, p2)) return true;
    if (o3 == 0 && onSegment(p3, p1, p4)) return true;
    if (o4 == 0 && onSegment(p3, p2, p4)) return true;

    return false;
}

void solve() {
    long long int N, M;
    cin >> N >> M;
    vector<long long int> X(N), Y(N);

    for (long long int i = 0; i < N; i++) {
        cin >> X[i] >> Y[i];
    }

    vector<Wire> wires;
    for (long long int i = 0; i < M; i++) {
        long long int u, v, isp;
        cin >> u >> v >> isp;
        u--; v--;
        wires.push_back({u, v, isp, i + 1});
    }

    vector<vector<long long int>> graph(M);
    for (long long int i = 0; i < M; i++) {
        for (long long int j = i + 1; j < M; j++) {
            if (wires[i].isp != wires[j].isp) {
                Point p1(X[wires[i].u], Y[wires[i].u]);
                Point p2(X[wires[i].v], Y[wires[i].v]);
                Point p3(X[wires[j].u], Y[wires[j].u]);
                Point p4(X[wires[j].v], Y[wires[j].v]);

                if (intersect(p1, p2, p3, p4)) {
                    graph[i].push_back(j);
                    graph[j].push_back(i);
                }
            }
        }
    }

    vector<long long int> match(M, -1);
    vector<bool> used(M);

    function<bool(long long int)> try_kuhn = [&](long long int v) {
        if (used[v]) return false;
        used[v] = true;
        for (long long int u : graph[v]) {
            if (match[u] == -1 || try_kuhn(match[u])) {
                match[u] = v;
                return true;
            }
        }
        return false;
    };

    for (long long int v = 0; v < M; v++) {
        fill(used.begin(), used.end(), false);
        try_kuhn(v);
    }

    long long int min_wires = 0;
    vector<long long int> to_remove;
    for (long long int i = 0; i < M; i++) {
        if (match[i] != -1) min_wires++;
    }
    min_wires /= 2;

    cout << min_wires << "\n";

    if (min_wires > 0) {
        vector<bool> visited(M, false);
        for (long long int i = 0; i < M; i++) {
            if (!visited[i] && match[i] != -1) {
                to_remove.push_back(wires[i].idx);
                visited[i] = visited[match[i]] = true;
            }
        }

        for (long long int i = 0; i < to_remove.size(); i++) {
            cout << to_remove[i];
            if (i < to_remove.size() - 1) cout << " ";
        }
        cout << "\n";
    } else {
        cout << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    long long int T;
    cin >> T;
    for (long long int t = 1; t <= T; t++) {
        cout << "Case #" << t << ":\n";
        solve();
    }
    return 0;
}
