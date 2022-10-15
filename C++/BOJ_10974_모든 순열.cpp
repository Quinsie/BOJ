#include <iostream>
#include <vector>

using namespace std;

void recursive(int pos, int target, vector <int>& ans, vector <bool>& check) // target = n
{
    if (pos == target) { // base case
        for (int i = 0; i < target; i++) { // 정답 출력용 배열 요소를 하나씩 출력
            cout << ans[i] << ' ';
        }
        cout << '\n';
        return;
    }
    
    for (int i = 0; i < target; i++) { // 함수 안에서 숫자를 하나씩 검사
        if (check[i] == false) { // 만약 현재 검사중인 숫자를 사용하지 않았다면
            ans[pos] = i + 1; // 정답 출력용 배열에 숫자를 넣어주고
            check[i] = true; // 숫자 사용 여부 배열에 체크를 해 준다
            recursive(pos + 1, target, ans, check); // 재귀 시작
            ans[pos] = 0; // 정답 출력용 배열을 비워주고
            check[i] = false; // 체크를 풀어준다
        }
    }
    
    
}

int main()
{
    int n; // 목표하는 숫자 (BASE CASE에 활용)
    cin >> n;
    
    vector <int> ans(n, 0); // 정답 출력용 배열
    vector <bool> check(n, false); // 숫자 사용 여부 체크 배열
    
    recursive(0, n, ans, check)   ;
    return 0;
}
