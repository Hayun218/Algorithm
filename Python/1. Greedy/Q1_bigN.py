n,m,k = map(int, input().split())

data = list(map(int, input().split()))

data.sort()

first = data[n-1]
second = data[n-2]

# 가장 큰 수가 더해지는 갯수 
count = int(m / (k+1)) * k
count += m % (k+1)

result = 0
result += (count) * first
result += (m-count) * second

print(result)

# ans = 0
#
# for i in range(m):
#     if (i+1) % k == 0:
#         ans += second
#     else:
#         ans += first
#
# print(ans)
