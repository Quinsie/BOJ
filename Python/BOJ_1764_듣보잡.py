import sys

n, m = map(int, sys.stdin.readline().split())
n_list = [sys.stdin.readline().rstrip() for _ in range(n)]
m_list = [sys.stdin.readline().rstrip() for _ in range(m)]

duplicate = list(set(n_list) & set(m_list))

print(len(duplicate))
for name in sorted(duplicate):
    print(name)