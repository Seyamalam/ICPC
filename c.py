def solve():
    n, k = map(int, input().split())
    xy = []
    for _ in range(n):
        xy.append(list(map(int, input().split())))

    ans = 0
    last_watered = [0] * n

    for day in range(1, k + 1):
        for i in range(n):
            if day - last_watered[i] > xy[i][0]:
                return float('inf')
            if day - last_watered[i] == xy[i][0]:
                last_watered[i] = day
                ans += 1
    return ans


t = int(input())
for i in range(1, t + 1):
    result = solve()
    print(f"Case {i}: {result}")