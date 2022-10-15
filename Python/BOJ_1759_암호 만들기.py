import sys

length, char = map(int, sys.stdin.readline().split())
char_list = sys.stdin.readline().rstrip().split()
char_list.sort()

check = [False] * (char + 1)
ans = [' ' for _ in range(length)]
ascii_ans = [0 for _ in range(length)]
vowel = ['a', 'e', 'i', 'o', 'u']

def recur(pos):
    if pos == length:
        vowel_cnt = 0; non_vowel_cnt = 0
        for i in ans:
            if i in vowel:
                vowel_cnt += 1
            else:
                non_vowel_cnt += 1
        
        if vowel_cnt >= 1 and non_vowel_cnt >= 2:
            for j in ans:
                print(j, end = '')
            print()
        
        return
    
    for k in range(char):
        if ord(char_list[k]) < max(ascii_ans):
            continue
        if check[k] == False:
            check[k] = True
            ans[pos] = char_list[k]
            ascii_ans[pos] = ord(char_list[k])
            recur(pos + 1)
            check[k] = False
            ans[pos] = ' '
            ascii_ans[pos] = 0

recur(0)