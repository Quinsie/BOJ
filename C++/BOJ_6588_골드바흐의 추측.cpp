#include <iostream>
#include <cmath>

using namespace std;

bool prime_num_discriminator(int input) {
	for (int i = 2; i <= sqrt(input); i++) {
		if (input%i == 0)return false;
	}
	return true;
}

void solve()
{
    int input = 1;
	int a, b;
	bool suc = false;
	
	while (input) {
		cin >> input;
		for (int i = 1; i < input / 2; i++) {
			a = 2 * i + 1;
			b = input - a;
			if (prime_num_discriminator(a) and prime_num_discriminator(b)) {
				cout << input << " = " << a << " + " << b << "\n";
				suc = true;
				break;
			}
		}
		if (!suc) cout << "Goldbach's conjecture is wrong\n";
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