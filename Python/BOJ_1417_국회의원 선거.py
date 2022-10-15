import sys

competitor = int(sys.stdin.readline()) - 1
dasom = int(sys.stdin.readline())
competitor_list = []
for i in range(competitor):
    competitor_list.append(int(sys.stdin.readline()))

count = 0
if len(competitor_list) > 0:
    while dasom <= max(competitor_list):
        competitor_list.sort(reverse = True)
        dasom += 1
        competitor_list[0] -= 1
        count += 1

print(count)