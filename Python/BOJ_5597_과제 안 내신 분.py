import sys

student = []
for i in range(28):
    student.append(int(sys.stdin.readline()))

student.sort()

count = 1
no_homework = []
for j in student:
    if j != count:
        if j - count == 2:
            no_homework.append(j - 2)
            no_homework.append(j - 1)
            break
        else:
            no_homework.append(j - 1)
            count += 2
            continue

    else:
        count += 1

if len(no_homework) == 2:
    print(no_homework[0])
    print(no_homework[1])

elif len(no_homework) == 1:
    print(no_homework[0])
    print(30)

else:
    print(29)
    print(30)