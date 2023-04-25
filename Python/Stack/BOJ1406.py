# 2023년 4월 25일
# Cursor를 기준으로 List 두개로 만들어서 구분! => 신박한 아이디어!

import sys

msg1 = list(sys.stdin.readline().rstrip())
msg2 = list()

num = int(input())

for _ in range(0, num):
    com = list(sys.stdin.readline().split())

    # cursor to left
    if com[0] == 'L':
        if msg1:
            msg2.append(msg1.pop())

    # cursor to right
    elif com[0] == 'D':
        if msg2:
            msg1.append(msg2.pop())

    # remove left one
    elif com[0] == 'B':
        if msg1:
            msg1.pop()

    # add to left 
    elif com[0] == 'P':
        msg1.append(com[1])

msg1.extend(reversed(msg2))
print(''.join(msg1))