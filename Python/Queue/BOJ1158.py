

N,K = map(int,input().split())

people = list(range(1, N+1))
ans = list()

while len(people) > 1:
    ans.append(people.pop(K))
    


print(ans)
