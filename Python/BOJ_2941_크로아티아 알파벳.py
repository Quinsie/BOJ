import sys

string = sys.stdin.readline().rstrip()
croatia = ['c=', 'c-', 'dz=', 'd-', 'lj', 'nj', 's=', 'z=']

for i in croatia:
    string = string.replace(i, '@')
print(len(string))