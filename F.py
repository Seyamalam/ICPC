def gcd(a, b):
    while b:
        a, b = b, a % b
    return a

def solve():
    x, y, z = map(int, input().split())
    
    num = x * y * z
    den = x + y + z

    g = gcd(num, den)
    num //= g
    den //= g
    
    print(f"{num}/{den}")


t = int(input())
for _ in range(t):
    solve()