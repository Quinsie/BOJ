import sys

string = sys.stdin.readline().rstrip()
char = 'U'
compress = ''

for i in string:
    if i == char:
        compress += i

        if char == 'U':
            char = 'C'
        elif char == 'P':
            char = 'C'
        elif char == 'C':
            if 'UCPC' in compress:
                break
            else:
                char = 'P'

if 'UCPC' in compress:
    print('I love UCPC')
else:
    print('I hate UCPC')