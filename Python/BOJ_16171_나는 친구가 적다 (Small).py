import sys

string_1 = sys.stdin.readline().rstrip()
string_changed = ''
string_2 = sys.stdin.readline().rstrip()

for i in string_1:
    if i.isdigit() == True:
        continue
    else:
        string_changed += i

if string_2 in string_changed:
    print(1)
else:
    print(0)