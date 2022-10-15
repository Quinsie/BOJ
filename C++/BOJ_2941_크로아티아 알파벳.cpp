#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int index;
    string str;
    vector<string> croatia = { "c=", "c-", "dz=", "d-", "lj", "nj", "s=", "z=" };
    
    cin >> str;
    for (int i = 0; i < croatia.size(); i++) {
        while(1) {
            index = str.find(croatia[i]);
            if (index == string::npos) break;
            str.replace(index, croatia[i].length(), "@");
        }
    }
    cout << str.length();

    return 0;
}
