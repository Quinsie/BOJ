import sys

num = int(sys.stdin.readline())

count = 0
for i in range(num):
    word = sys.stdin.readline().rstrip()
    spell = []; switch = False
    for j in range(len(word) - 1):
        if word[j + 1] != word[j] and word[j + 1] not in spell:
            spell.append(word[j])
        elif word [j + 1] != word[j] and word[j + 1] in spell:
            switch = True
            break

    if switch == False:
        count += 1

print(count)