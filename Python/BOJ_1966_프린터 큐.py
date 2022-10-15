import sys
 
t = int(sys.stdin.readline())
for i in range(t):
    q = []
    N,M = map(int,sys.stdin.readline().split())
    queue = list(map(int,sys.stdin.readline().split()))
    for i in queue:
        q.append(i)
    p = M
    cnt = 0
    while(True):
        if(max(q) == q[0]):
            q.pop(0)
            cnt += 1
            if(p == 0):
                print(cnt)
                break
            else:
                p -= 1
                if(p < 0):
                    p = len(q)-1
        else:
            p -= 1
            if(p < 0):
                p = len(q)-1
            q.append(q.pop(0))