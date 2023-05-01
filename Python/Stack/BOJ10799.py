import sys

input = list(sys.stdin.readline())
stick = []
prev = None


i = 0
cnt = 0
ans = 0
for i in range(len(input)):
    if input[i] == '(':
        stick.append(input[i])
    # laser
    elif input[i] == ')' and prev == '(':
        stick.pop()
        ans += len(stick)
    # closing
    elif input[i] == ')' and prev == ')':
        ans += 1
        stick.pop()

    prev = input[i]

print(ans)