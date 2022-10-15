#include <bits/stdc++.h>

using namespace std;

const long long MAX = 10e8;
const int dx[4] = { 0, 1 , 0, -1 };
const int dy[4] = { 1, 0, -1, 0 };

class info {
public:
	long long sx, sy, dir, len;
};

void solve()
{
    long long limit, order, val, result;
    long long cx, cy, cd, nx, ny, temp;
    long long sx, sy, len, dir, ex, ey;
    bool finish;
    char c;
    info tmp;
    vector <info> v;
    
	cin >> limit >> order;
    
	finish = false;
	result = 0;
	cx = 0; cy = 0; cd = 1;
    
	for (int i = 0; i <= order; i++) {
		if (i != order)
			cin >> val >> c;
		else if (i == order)
			val = MAX;
		if (finish) continue;
		temp = MAX;

		nx = cx + dx[cd] * val;
		ny = cy + dy[cd] * val;
		if (nx < -limit) 		temp = min(temp, cx - (-limit) + 1);
		else if (nx > limit) 	temp = min(temp, limit - cx + 1);
		else if (ny < -limit) 	temp = min(temp, cy - (-limit) + 1);
		else if (ny > limit) 	temp = min(temp, limit - cy + 1);

		if (v.size() > 0) {
			for (int j = 0; j < v.size() - 1; j++) {
				sx = v[j].sx; sy = v[j].sy;
				len = v[j].len; dir = v[j].dir;
				ex = sx + dx[dir] * len; ey = sy + dy[dir] * len;

				if (cd == 0) {
					if (dir == 0 && cx == sx && cy <= sy && sy <= ny) 
						temp = min(temp, sy - cy);
					else if (dir == 1 && sx <= cx && cx <= ex && cy <= sy && sy <= ny) 
						temp = min(temp, sy - cy);
					else if (dir == 2 && cx == sx && cy <= ey && ey <= ny) 
						temp = min(temp, ey - cy);
					else if (dir == 3 && ex <= cx && cx <= sx && cy <= ey && ey <= ny) 
						temp = min(temp, ey - cy);
				}
				else if (cd == 1) {
					if (dir == 0 && cx <= sx && sx <= nx && sy <= cy && cy <= ey) 
						temp = min(temp, ex - cx);
					else if (dir == 1 && cy == sy && cx <= sx && sx <= nx) 
						temp = min(temp, sx - cx);		
					else if (dir == 2 && cx <= sx && sx <= nx && ey <= ny && ny <= sy)
						temp = min(temp, sx - cx);

					else if (dir == 3 && cy == sy && cx <= ex && ex <= nx)
						temp = min(temp, ex - cx);
				}
				else if (cd == 2) {
					if (dir == 0 && cx == sx && ny <= ey && ey <= cy)
						temp = min(temp, cy - ey);
					else if (dir == 1 && sx <= cx && cx <= ex && ny <= sy && sy <= cy)
						temp = min(temp, cy - ey);
					else if (dir == 2 && cx == sx && ny <= sy && sy <= cy)
						temp = min(temp, cy - sy);
					else if (dir == 3 && ny <= sy && sy <= cy && ex <= cx && cx <= sx)
						temp = min(temp, cy - sy);
				}
				else if (cd == 3) {
					if (dir == 0 && sy <= cy && cy <= ey && nx <= ex && ex <= cx)
						temp = min(temp, cx - sx);
					else if (dir == 1 && sy == cy && nx <= ex && ex <= cx)
						temp = min(temp, cx - ex);
					else if (dir == 2 && nx <= sx && sx <= cx && ey <= cy && cy <= sy)
						temp = min(temp, cx - ex);
					else if (dir == 3 && sy == cy && nx <= sx && sx <= cx)
						temp = min(temp, cx - sx);
				}
			}
		}
		if (temp != MAX) {
			finish = true;
			result += temp;
		}
		else {
			tmp.dir = cd;
			tmp.sx = cx;
			tmp.sy = cy;
			tmp.len = val;
			v.push_back(tmp);
			cx = nx;
			cy = ny;

			if (c == 'L') cd = (cd + 3) % 4;
			else cd = (cd + 1) % 4;
			result += val;			
		}
	}
	cout << result << '\n';
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