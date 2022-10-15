#include <iostream>
#include <algorithm>

using namespace std;
 
class point 
{
    public:
    long long x, y;

    point () {
        x = 0; y = 0;
    }
    point (long long a, long long b) {
        x = a; y = b;
    }
    ~point() {}

    bool operator== (const point& other) {
        if (this -> x == other.x && this -> y == other.y) return true;
        else return false;
    }
    bool operator<= (const point& other) {
        if (this -> x <= other.x && this -> y <= other.y) return true;
        else return false;
    }
};

void swap_point(point& a, point& b)
{
    point temp;
    temp = a;
    a = b;
    b = temp;
}

void find_intersection(point a, point b, point c, point d)
{
	double px = (a.x * b.y - a.y * b.x) * (c.x - d.x) - (a.x - b.x) * (c.x * d.y - c.y * d.x);
	double py = (a.x * b.y - a.y * b.x) * (c.y - d.y) - (a.y - b.y) * (c.x * d.y - c.y * d.x);
	double p = (a.x - b.x) * (c.y - d.y) - (a.y - b.y) * (c.x - d.x);

	if (p == 0) {
		if (b == c && a <= c) cout << b.x << " " << b.y << '\n';
		else if (a == d && c <= a) cout << a.x << " " << a.y << '\n';
	} else {
		double x = px / p;
		double y = py / p;

		cout << fixed;
		cout.precision(20);
		cout << x << " " << y;
	}
}
 
int ccw(point a, point b, point c) {
	long long ret = (b.x - a.x)*(c.y - a.y) - (b.y - a.y)*(c.x - a.x);
 
	if (ret > 0) return 1;
	else if (ret < 0) return -1;
	else return 0;
}

void optimize()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int main()
{
    long long ccw1, ccw2;
    point l1[2],l2[2];

	cin >> l1[0].x >> l1[0].y >> l1[1].x >> l1[1].y;
	cin >> l2[0].x >> l2[0].y >> l2[1].x >> l2[1].y;
 
    ccw1 = ccw(l1[0], l1[1], l2[0]) * ccw(l1[0], l1[1], l2[1]);
	ccw2 = ccw(l2[0], l2[1], l1[0]) * ccw(l2[0], l2[1], l1[1]);

	if (ccw1 <= 0 && ccw2 <= 0) {
		if (ccw1 == 0 && ccw2 == 0) {
			if (l1[0].x == l2[0].x) {
				if (l1[0].y > l1[1].y) swap(l1[0], l1[1]);
				if (l2[0].y > l2[1].y) swap(l2[0], l2[1]);
				if (l1[0].y <= l2[1].y && l2[0].y <= l1[1].y) {
                    cout << 1 << '\n';
                    find_intersection(l1[0], l1[1], l2[0], l2[1]);
                } else cout << 0 << '\n';
			} else {
				if (l1[0].x > l1[1].x) swap(l1[0], l1[1]);
				if (l2[0].x > l2[1].x) swap(l2[0], l2[1]);
				if (l1[0].x <= l2[1].x && l2[0].x <= l1[1].x) {
                    cout << 1 << '\n';
                    find_intersection(l1[0], l1[1], l2[0], l2[1]);
                } else cout << 0 << '\n';
			}
		} else {
            cout << 1 << '\n';
            find_intersection(l1[0], l1[1], l2[0], l2[1]);
        }
	} else cout << 0 << '\n';

	return 0;
}