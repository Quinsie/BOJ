import sys

input_num = sys.stdin.readline().rstrip()
num_list = [int(i) for i in input_num]
num_list.sort()
check = [False] * (len(num_list) + 1)
ans = ''; result = []

def recur(pos):
    global ans
    if pos == len(num_list):
        if int(ans) > int(input_num):
            if len(result) > 0:
                return
            else:
                result.append(ans)
                return
    
    temp = -1
    for i in range(len(num_list)):
        if check[i] == False and temp != num_list[i]:
            check[i] = True
            ans += str(num_list[i])
            temp = num_list[i]
            recur(pos + 1)
            check[i] = False
            ans = ans[:pos]

recur(0)
if len(result) > 0:
    print(result[0])
else:
    print(0)