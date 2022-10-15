#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n, left, right, mid;
    vector <int> arr, LIS;
    
    cin >> n;
    arr.assign(n + 1, 0);
    LIS.push_back(0);
    
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }
    
    for (int i = 1; i <= n; i++) {
        // 현재 최장부분에 저장된 숫자보다 검사중인 숫자가 크다면
        if (arr[i] > LIS[LIS.size() - 1]) {
            // 검사중인 숫자를 LIS의 끝에 추가
            // 현재 LIS벡터의 길이는 현재 최장 증가 부분 수열의 길이
            LIS.push_back(arr[i]);
        } else { // 크지 않다면 이분탐색으로 들어갈 부분을 찾아줌
          left = 0; right = LIS.size();
          
          while (left < right) {
              mid = (left + right) / 2;
              
              if (LIS[mid] < arr[i]) {
                  left = mid + 1;
              } else {
                  right = mid;
              }
          }
          
          LIS[right] = arr[i];
        }
    }
    
    cout << LIS.size() - 1 << '\n';

    return 0;
}
