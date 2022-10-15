#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string plus_string(string a, string b) {
    int sum, plus, short_len, long_len;
    bool flag;
    string result;

    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());

    if (a.size() >= b.size()) { // a is longer
        long_len = a.size(); short_len = b.size();
        flag = true; 
    } else { // b is longer
        long_len = b.size(); short_len = a.size();
        flag = false;
    }

    sum = 0; plus = 0;
    result = "";
    for (int i = 0; i < long_len; i++) {
        if (i < short_len) sum = ((int)a[i] - 48) + ((int)b[i] - 48) + plus;
        else {
            if (flag) sum = ((int)a[i] - 48) + plus;
            else sum = ((int)b[i] - 48) + plus;
        }

        if (sum < 0) sum += 48;
        if (sum > 9) plus = 1;
        else plus = 0;

        result += to_string(sum % 10);
    }

    if (plus) result += "1";

    reverse(result.begin(), result.end());
    return result;
}

void solve()
{
    string a, b;
    cin >> a >> b;
    cout << plus_string(a, b) << '\n';
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