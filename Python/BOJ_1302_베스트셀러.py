import sys

num = int(sys.stdin.readline())
book = []
for i in range(num):
    book.append(sys.stdin.readline().rstrip())

book.sort()

count = 1; max = 0; name = book[0]
for j in range(len(book) - 1):
    if book[j + 1] == book[j]:
        count += 1
    elif book[j + 1] != book[j]:
        count = 1
    
    if count > max:
        max = count
        name = book[j]
    
print(name)