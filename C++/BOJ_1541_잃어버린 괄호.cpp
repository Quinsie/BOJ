#include <iostream>
#include <string>

using namespace std;
 
int main()
{
    int result = 0;
    string num, input;
    bool flag = false;
    cin >> input;
 
    for (int i = 0; i <= input.size(); i++) {   
        if (input[i] == '-' || input[i] == '+' || i==input.size()) {
            if (flag) {
                result -= stoi(num);
                num = "";
            } else {
                result += stoi(num);
                num = "";
            }
        } else {
            num += input[i];
        }
        if (input[i] == '-') {
            flag = true;
        }    
    }    
    cout << result;

    return 0;
}