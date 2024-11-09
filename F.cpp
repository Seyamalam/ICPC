#include <bits/stdc++.h>
using namespace std;

int64_t gcd(int64_t a, int64_t b)
{
    while (b)
    {
        a %= b;
        swap(a, b);
    }
    return a;
}

pair<int64_t, int64_t> reduce_fraction(int64_t num, int64_t den)
{
    int64_t g = gcd(abs(num), abs(den));
    return {num / g, den / g};
}

void solve()
{
    int64_t x, y, z;
    cin >> x >> y >> z;
    int64_t a2 = x * x;
    int64_t b2 = y * y;
    int64_t c2 = z * z;
    int64_t num = a2 + b2 + c2;
    int64_t den = 36;
    auto result = reduce_fraction(num, den);
    cout << result.first << "/" << result.second << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
