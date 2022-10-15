import sys

e, s, m = map(int, sys.stdin.readline().split())

while True:
    if e == s and s == m and e == m:
        break

    small = min(e, s, m)
    if small == e:
        e += 15
    elif small == s:
        s += 28
    elif small == m:
        m += 19

print(e)