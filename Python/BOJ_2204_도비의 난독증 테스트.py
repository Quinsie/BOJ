import sys

while True:
    n = int(sys.stdin.readline())
    if n == 0:
        break

    word = []
    for i in range(n):
        temp = sys.stdin.readline().rstrip()
        temp2 = temp.upper()
        word.append([temp2, temp])
    word.sort()

    print(word[0][1])