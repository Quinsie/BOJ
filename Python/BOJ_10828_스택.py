import sys

num = int(sys.stdin.readline())
stack = []

for i in range(num):
    order = sys.stdin.readline().rstrip().split()

    if len(order) == 1:
        if order[0] == 'pop':
            if len(stack) > 0:
                print(stack[0])
                del stack[0]
            else:
                print(-1)
        
        elif order[0] == 'size':
            print(len(stack))
        
        elif order[0] == 'empty':
            if len(stack) == 0:
                print(1)
            else:
                print(0)
        
        elif order[0] == 'top':
            if len(stack) > 0:
                print(stack[0])
            else:
                print(-1)
    
    if len(order) == 2:
        stack.insert(0, order[1])