#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int length, target;
    int lo = 0, hi = 0, sum = 0, count = 0;
    
    cin >> length >> target;
    vector <int> num_arr(length);
    
    for (int i = 0; i < length; i++) {
        cin >> num_arr[i];
    }
    
    while (true) {
        if (sum >= target) {
            sum -= num_arr[lo++];
        } else if (hi == length) {
            break;
        } else {
            sum += num_arr[hi++];
        }
        if (sum == target) count ++;
    }
    
    cout << count << "\n";
    
    return 0;
}