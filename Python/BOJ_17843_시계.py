import sys

case = int(sys.stdin.readline())
for i in range(case):
    hour, minute, second = map(int, sys.stdin.readline().split())
    minute += second / 60
    hour += minute / 60
    
    angle_h = hour * 30
    angle_m = minute * 6
    angle_s = second * 6

    h_m = min(abs(angle_h - angle_m), abs((max(angle_h, angle_m) - 360) - min(angle_h, angle_m)))
    m_s = min(abs(angle_m - angle_s), abs((max(angle_m, angle_s) - 360) - min(angle_m, angle_s)))
    s_h = min(abs(angle_s - angle_h), abs((max(angle_s, angle_h) - 360) - min(angle_s, angle_h)))
    
    print(min(h_m, m_s, s_h))