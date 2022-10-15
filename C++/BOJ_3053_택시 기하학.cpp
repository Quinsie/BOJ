#include <iostream>
using namespace std;

const long double PI = 3.1415926535897932;

int main()
{
    ios::sync_with_stdio(NULL);
    cin.tie(NULL);
    cout.tie(NULL);
    
	double r;
	cin >> r;

	cout << fixed;
	cout.precision(6);
	cout << r * r*PI << "\n" << 2 * r*r << "\n";
}