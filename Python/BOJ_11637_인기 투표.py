import sys

case = int(sys.stdin.readline())
for i in range(case):
    pick = int(sys.stdin.readline())
    pick_list = []
    for i in range(pick):
        pick_list.append(int(sys.stdin.readline()))

    win = max(pick_list)
    winner = pick_list.index(win)
    picks = sum(pick_list)

    count = 0
    for j in pick_list:
        if j == win:
            count += 1
        if count > 1:
            break
    
    if count != 1:
        print('no winner')
    else:
        if win > (picks / 2):
            print('majority winner %d' %(winner + 1))
        else:
            print('minority winner %d' %(winner + 1))