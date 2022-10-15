import sys

p1_x, p1_y = map(int, sys.stdin.readline().split())
p2_x, p2_y = map(int, sys.stdin.readline().split())
p3_x, p3_y = map(int, sys.stdin.readline().split())

v_p1p2 = (p2_x - p1_x, p2_y - p1_y)
v_p2p3 = (p3_x - p2_x, p3_y - p2_y)

external = (v_p1p2[0] * v_p2p3[1]) - (v_p1p2[1] * v_p2p3[0])

if external > 0:
    print(1)
elif external == 0:
    print(0)
else:
    print(-1)