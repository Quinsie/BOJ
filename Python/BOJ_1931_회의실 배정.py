# BOJ 1931번 : 회의실 배정

import sys

# input
conference = []
num = int(sys.stdin.readline())
for i in range(num):
    temp = list(map(int, sys.stdin.readline().split(' ')))
    conference.append(temp)

# progress
conference.sort(key = lambda x: (x[1], x[0]))   # 끝나는 시간으로 정렬

count = 1
end = conference[0][1]
for j in range(1, num):
    if conference[j][0] >= end:
        count += 1
        end = conference[j][1]

# output
print(count)