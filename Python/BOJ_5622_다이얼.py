import sys

word = sys.stdin.readline().rstrip()
time = 0

for i in word:
    if ord(i) >= 65 and ord(i) <= 67:
        time += 3
    elif ord(i) >= 68 and ord(i) <= 70:
        time += 4
    elif ord(i) >= 71 and ord(i) <= 73:
        time += 5
    elif ord(i) >= 74 and ord(i) <= 76:
        time += 6
    elif ord(i) >= 77 and ord(i) <= 79:
        time += 7
    elif ord(i) >= 80 and ord(i) <= 83:
        time += 8
    elif ord(i) >= 84 and ord(i) <= 86:
        time += 9
    elif ord(i) >= 87 and ord(i) <= 90:
        time += 10

print(time)