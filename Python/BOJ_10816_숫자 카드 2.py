import sys
import collections

card = int(sys.stdin.readline())
card_list = list(map(int, sys.stdin.readline().split()))

num = int(sys.stdin.readline())
num_list = list(map(int, sys.stdin.readline().split()))

card_counter = collections.Counter(card_list)

for i in num_list:
    print(card_counter[i], end = ' ')