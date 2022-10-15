import sys
import collections

queue = collections.deque()

case = int(sys.stdin.readline())
for i in range(case):
    order = sys.stdin.readline().rstrip().split()
    
    if order[0] == 'push':
        queue.append(int(order[1]))
    
    elif order[0] == 'pop':
        if queue:
            print(queue.popleft())
        else:
            print(-1)
    
    elif order[0] == 'size':
        print(len(queue))
    
    elif order[0] == 'empty':
        if queue:
            print(0)
        else:
            print(1)
    
    elif order[0] == 'front':
        if queue:
            print(queue[0])
        else:
            print(-1)
    
    elif order[0] == 'back':
        if queue:
            print(queue[len(queue) - 1])
        else:
            print(-1)