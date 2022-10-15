import sys

line, brand = map(int, sys.stdin.readline().split())
package = []; piece = []

for i in range(brand):
    a, b = map(int, sys.stdin.readline().split())
    package.append(a); piece.append(b)

need_package = line // 6
need_piece = line % 6

if need_piece * min(piece) > min(package):
    print((need_package + 1) * min(package))
elif min(piece) * 6 < min(package):
    print(line * min(piece))
else:
    print(need_package * min(package) + need_piece * min(piece))