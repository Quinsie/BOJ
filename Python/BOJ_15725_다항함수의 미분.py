import sys

formula = sys.stdin.readline().rstrip()

formula = formula.split('x')
if len(formula) == 1:
    print(0)
else:
    if len(formula[0]) == 0:
        print(1)
    elif formula[0] == '-':
        print(-1)
    else:
        print(int(formula[0]))