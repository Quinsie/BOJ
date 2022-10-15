import sys

def isPrime(n):
    if n < 2:
        return False
    if n == 2:
        return True
    if n % 2 == 0:
        return False
    for i in range(3,101,2):
        if i * i > n:
            return True
        if n % i == 0:
            return False
    return True

while True:
    line = sys.stdin.readline().rstrip()
    parts = line.split(' ')
    letters = [ord(parts[0][0])-65,ord(parts[0][1])-65,ord(parts[0][2])-65]
    num = int(parts[1])

    if line == "END 0000":
        break

    while not isPrime(num):
        num += 1
        if num == 10000:
            num = 0
            letters[2] += 1
        if letters[2] == 26:
            letters[2] = 0
            letters[1] += 1
        if letters[1] == 26:
            letters[1] = 0
            letters[0] += 1

    print("%c%c%c %04d" % (chr(letters[0]+65),chr(letters[1]+65),chr(letters[2]+65),num))