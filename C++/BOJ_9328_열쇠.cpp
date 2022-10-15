#include <bits/stdc++.h>
using namespace std;

int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};

int H, W;
vector<vector<char>> arr;
vector<vector<bool>> visited;
vector<bool> have_key;
vector<vector<pair<int,int>>> doors;

int result;

void DFS(int y, int x) {
   if ((y<0) || (y>=H) || (x<0) || (x>=W)) return;
   if (visited[y][x]) return;

   if (arr[y][x] == '.') true;
   else if (arr[y][x] == '*') return;
   else if (arr[y][x] == '$') result ++;
   else if ('a' <= arr[y][x] && arr[y][x] <= 'z') {
      int door = arr[y][x] - 'a' + 'A';
      have_key[door] = true;
      for (auto &u : doors[door]) {
         DFS(u.first, u.second);
      }
   }
   else if (!have_key[arr[y][x]]) {
      doors[arr[y][x]].push_back({y, x});   
      return;
   }
   visited[y][x] = true;

   for (int i=0; i<4; i++) {
      int ny = y + dy[i];
      int nx = x + dx[i];
      DFS(ny, nx);
   }
}

void solve() {
   result = 0;

   cin >> H >> W;
   arr.assign(H, vector<char>(W));
   visited.assign(H, vector<bool>(W, false));
   have_key.assign(128, false);
   doors.clear(); doors.resize(128);

   for (int i=0; i<H; i++) {
      string s; cin >> s;
      for (int j=0; j<W; j++) {
         arr[i][j] = s[j];
      }
   }
   string s; cin >> s;
   if (s != "0") {
      for (auto &u : s) {
         int door = u - 'a' + 'A';
         have_key[door] = true;
      }
   }

   for (int i=0; i<H; i++) 
   for (int j=0; j<W; j++) {
      if (i==0 || i==H-1 || j==0 || j==W-1) DFS(i, j);
   }

   cout << result << '\n';
}

int main()
{
   ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);   
   int tc; cin >> tc;
   while(tc-- > 0) solve();

   return 0;
}