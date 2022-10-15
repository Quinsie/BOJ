import sys

num = int(sys.stdin.readline())
queue = []

for i in range(num):
    order = sys.stdin.readline().rstrip().split()

    if len(order) == 1:
        if order[0] == 'pop':
            if len(queue) > 0:
                print(queue[0])
                del queue[0]
            else:
                print(-1)
        
        elif order[0] == 'size':
            print(len(queue))
        
        elif order[0] == 'empty':
            if len(queue) == 0:
                print(1)
            else:
                print(0)
        
        elif order[0] == 'front':
            if len(queue) > 0:
                print(queue[0])
            else:
                print(-1)
        
        elif order[0] == 'back':
            if len(queue) > 0:
                print(queue[len(queue) - 1])
            else:
                print(-1)
    
    if len(order) == 2:
        queue.append(order[1])