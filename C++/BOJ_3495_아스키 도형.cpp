#include<bits/stdc++.h>

using namespace std;

int n, m;
string board[100];

int main()
{	
	int ans = 0;
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		cin >> board[i];
		int sum = 0;
		for (int j = 0; j < m; j++) {
			if (board[i][j] == '/' || board[i][j] == '\\')
				sum++,ans+=1;
			if (sum % 2 == 1 && board[i][j] == '.')
				ans += 2;
		}
	}
	cout << ans / 2;
	
	return 0;
}