# 2023.04.24.
# 단어 뒤집기 2

import sys

input = input()  
input = sys.stdin.readline()

# rstrip() => 우측 개행문자 제거
word = list(sys.stdin.readline().rstrip())

i = 0
s = 0

while i < len(word):
    # white space
    if word[i] == " ":
        i += 1
    # when encountering < move to the next letter
    elif word[i] == "<":
        while word[i] != ">":
            i += 1
        i += 1
    # if num or alphabet
    elif word[i].isalnum(): 
        s = i
        # until it is not num nor alphabet
        while i < len(word) and word[i].isalnum():
            i += 1
            
        # reverse each letter
        tmp = word[s:i] 
        tmp.reverse()      
        word[s:i] = tmp             

print("".join(word))
