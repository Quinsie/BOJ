#include <iostream>
#include <vector>

using namespace std;

void solve()
{
    int ans, length;
    string str;
    vector <char> stack;
	
	cin >> str;
    ans = 0;
    length = str.size();
	for (int i = 0; i < length; i++) {
		if (str[i] == '(') {
			stack.push_back(str[i]);
		} else if (str[i] == ')' && str[i - 1] == '(') {
			stack.pop_back();
			ans += stack.size();
		} else {
			ans++;
			stack.pop_back();
		}
	}
	cout << ans << '\n';
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