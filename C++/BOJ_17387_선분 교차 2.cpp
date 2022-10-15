#include <iostream>
#include <algorithm>

using namespace std;
 
class POINT 
{
    public:
        long long x, y;
};
 
int ccw(POINT a, POINT b, POINT c) {
	long long int ret = (b.x - a.x)*(c.y - a.y) - (b.y - a.y)*(c.x - a.x);
 
	if (ret > 0) return 1;
	else if (ret < 0) return -1;
	else return 0;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    POINT l1[2],l2[2];

	cin >> l1[0].x >> l1[0].y >> l1[1].x >> l1[1].y;
	cin >> l2[0].x >> l2[0].y >> l2[1].x >> l2[1].y;
 
	long long int ccw1 = ccw(l1[0], l1[1], l2[0]) * ccw(l1[0], l1[1], l2[1]);
	long long int ccw2 = ccw(l2[0], l2[1], l1[0]) * ccw(l2[0], l2[1], l1[1]);
	if (ccw1 <= 0 && ccw2 <= 0) {
		if (ccw1 == 0 && ccw2 == 0) {
			if (l1[0].x == l2[0].x) {
				if (l1[0].y > l1[1].y) swap(l1[0], l1[1]);
				if (l2[0].y > l2[1].y) swap(l2[0], l2[1]);
				if (l1[0].y <= l2[1].y && l2[0].y <= l1[1].y) cout << 1;
				else cout << 0;
			} else {
				if (l1[0].x > l1[1].x) swap(l1[0], l1[1]);
				if (l2[0].x > l2[1].x) swap(l2[0], l2[1]);
				if (l1[0].x <= l2[1].x && l2[0].x <= l1[1].x) cout << 1;
				else cout << 0;
			}
		} else cout << 1;
	} else cout << 0;

	return 0;
}