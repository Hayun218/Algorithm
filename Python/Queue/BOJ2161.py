
num = int(input())

card = list(range(1, num+1))
qu = []


i = 1
while len(card) > 1 :
    qu.append(card[0])
    card = card[2:] + [card[1]]
qu.append(card[0])

print(*qu)


## My Code~
# num = int(input())

# list = []
# qu = []

# for i in range(1, num+1):
#     list.append(i)

# i = 1
# while(True):
#     if len(list) == 0:
#         break
#     qu.append(list.pop(0))
    
#     if len(list) == 0:
#         break
#     list.append(list.pop(0))

# print(*qu)