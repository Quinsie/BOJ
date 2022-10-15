import sys

def eratos(n):
    table = [True] * 1003002
    table[0] = False; table[1] = False

    for i in range(2, int(1003001 ** 0.5) + 1):
        if table[i] == True:
            for j in range(i + i, 1003002, i):
                table[j] = False
    
    return [k for k in range(n, 1003002) if table[k] == True]

num = int(sys.stdin.readline())
eratos_num = eratos(num)
for i in eratos_num:
    temp = str(i)
    count = 0
    for j in range((len(temp) // 2) + 1):
        if temp[j] != temp[len(temp) - j - 1]:
            break
        else:
            count += 1
    if count == len(temp) // 2 + 1:
        print(temp)
        break