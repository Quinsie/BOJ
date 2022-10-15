import sys

def external(vector1, vector2):
    return (vector1[0] * vector2[1]) - (vector1[1] * vector2[0])

x1, y1, x2, y2 = map(int, sys.stdin.readline().split())
x3, y3, x4, y4 = map(int, sys.stdin.readline().split())

v_12 = (x2 - x1, y2 - y1)
v_23 = (x3 - x2, y3 - y2)
v_24 = (x4 - x2, y4 - y2)

v_34 = (x4 - x3, y4 - y3)
v_41 = (x1 - x4, y1 - y4)
v_42 = (x2 - x4, y2 - y4)

ccw_1234 = external(v_12, v_23) * external(v_12, v_24)
ccw_3412 = external(v_34, v_41) * external(v_34, v_42)

if ccw_1234 <= 0 and ccw_3412 <= 0:
    print(1)
else:
    print(0)