a = int(input()); b = int(input())

c = (a * (int(str(b)[2])))
d = (a * (int(str(b)[1])))
e = (a * (int(str(b)[0])))
total = c + (d * 10) + (e * 100)

print(c); print(d); print(e); print(total)