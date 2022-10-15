import sys

num = int(sys.stdin.readline())
for i in range(num):
    name, score = sys.stdin.readline().rstrip().split()
    if int(score) >= 97:
        score = 'A+'
    elif int(score) >= 90:
        score = 'A'
    elif int(score) >= 87:
        score = 'B+'
    elif int(score) >= 80:
        score = 'B'
    elif int(score) >= 77:
        score = 'C+'
    elif int(score) >= 70:
        score = 'C'
    elif int(score) >= 67:
        score = 'D+'
    elif int(score) >= 60:
        score = 'D'
    else:
        score = 'F'
    
    print('%s %s' %(name, score))