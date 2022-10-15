import sys

deque = []
repeat = int(sys.stdin.readline())
for i in range(repeat):
    order = sys.stdin.readline().rstrip().split()

    if order[0] == 'push_back':
        deque.append(int(order[1]))

    elif order[0] == 'push_front':
        deque.insert(0, int(order[1]))

    elif order[0] == 'pop_front':
        if len(deque) == 0:
            print(-1)
        else:
            print(deque[0])
            del deque[0]

    elif order[0] == 'pop_back':
        if len(deque) == 0:
            print(-1)
        else:
            print(deque[len(deque) - 1])
            del deque[len(deque) - 1]
    
    elif order[0] == 'size':
        print(len(deque))
    
    elif order[0] == 'empty':
        if len(deque) == 0:
            print(1)
        else:
            print(0)
    
    elif order[0] == 'front':
        if len(deque) == 0:
            print(-1)
        else:
            print(deque[0])
    
    elif order[0] == 'back':
        if len(deque) == 0:
            print(-1)
        else:
            print(deque[len(deque) - 1])