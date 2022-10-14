#include <iostream>
#include <vector>

using namespace std;

void solve()
{
    int n, len;
    char order;
    string str;
    vector <char> front, back;
    
    cin >> str >> n;
    len = str.size();
    for (int i = 0; i < len; i++) {
        front.emplace_back(str[i]);
    }
    
    for (int i = 0; i < n; i++) {
        cin >> order;
        cin.ignore();
        
        if (order == 'L') {
            if (front.size()) {
                back.push_back(front.back());
                front.pop_back();
            }
        } else if (order == 'D') {
            if (back.size()) {
                front.push_back(back.back());
                back.pop_back();
            }
        } else if (order == 'B') {
            if (front.size()) {
                front.pop_back();
            }
        } else if (order == 'P') {
            cin >> order;
            cin.ignore();
            front.push_back(order);
        }
    }
    
    len = front.size();
    for (int i = 0; i < len; i++) {
        cout << front[i];
    }
    len = back.size();
    for (int i = len - 1; i >= 0; i--) {
        cout << back[i];
    }
}

void optimize()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int main()
{
    optimize();
    solve();
    return 0;
}