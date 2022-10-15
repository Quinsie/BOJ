import sys
import math

def average(list):
    return round(sum(list) / len(list))

def middle(list):
    list.sort()
    return list[len(list) // 2]

def mode(list):
    check = [0 for _ in range(8001)]
    for i in list:
        check[i + 4000] += 1
    
    maximum = 0
    count = -4000
    max_list = []
    for j in check:
        if j == maximum:
            max_list.append(count)
        if j > maximum:
            max_list = []
            maximum = j
            max_list.append(count)
        count += 1
    
    if len(max_list) > 1:
        return(max_list[1])
    else:
        return(max_list[0])

def size(list):
    return (max(list) - min(list))

num = int(sys.stdin.readline())
num_list = []
for i in range(num):
    num_list.append(int(sys.stdin.readline()))

print(average(num_list))
print(middle(num_list))
print(mode(num_list))
print(size(num_list))