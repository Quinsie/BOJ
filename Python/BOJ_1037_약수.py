# BOJ 1037번 : 약수

# input
num = int(input())
aliquot = list(map(int, input().split(' ')))

# progress
aliquot.sort()
if len(aliquot) % 2 == 0:   # 약수 개수가 짝수인 경우
    result = aliquot[0] * aliquot[-1]
else:
    result = (aliquot[len(aliquot) // 2]) ** 2

# output
print(result)