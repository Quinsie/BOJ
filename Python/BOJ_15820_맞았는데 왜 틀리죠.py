import sys

sample, system = map(int, sys.stdin.readline().split(' '))

count = 1
while count <= sample:
    a, b = map(int, sys.stdin.readline().split(' '))
    if a != b:
        print('Wrong Answer')
        break
    else:
        count += 1

while count > sample and count <= (sample + system):
    a, b = map(int, sys.stdin.readline().split(' '))
    if a != b:
        print('Why Wrong!!!')
        break
    else:
        count += 1

if count == sample + system + 1:
    print('Accepted')