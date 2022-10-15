test_data = int(input()) # 몇 번 테스트 할 지 인풋받기
test_data_list = []
for i in range(test_data): # 인풋받은 숫자만큼 테스트 데이터를 받아 리스트에 저장
    temp = list(map(int, input().split(' ')))
    test_data_list.append(temp)

for j in range(test_data):
    if test_data_list[j][2] % test_data_list[j][0] == 0:
        floor = test_data_list[j][0]
        room = test_data_list[j][2] // test_data_list[j][0]
    
    else:
        floor = test_data_list[j][2] % test_data_list[j][0]
        room = (test_data_list[j][2] // test_data_list[j][0]) + 1

    target_room = (floor * 100) + room
    print(target_room)