#include <iostream>
#include <queue>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int num, temp;
    bool flag = false;
    queue <int> que;

    cin >> num;
    for (int i = 1; i <= num; i++) que.push(i);
    while(que.size() != 1) {
        if (!flag) {
            que.pop();
            flag = true;
            continue;
        }
        else {
            temp = que.front();
            que.pop();
            que.push(temp);
            flag = false;
        }
    }
    cout << que.front();
    
    return 0;
}
