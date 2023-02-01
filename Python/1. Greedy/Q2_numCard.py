n,m = map(int, input().split())

ans = 0

for i in range(n):
    data = list(map(int, input().split()))

    min_value = min(data)
    ans = max(ans, min_value)

print(ans)
