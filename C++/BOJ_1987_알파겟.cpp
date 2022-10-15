#include <iostream>
#include <vector>

using namespace std;

typedef vector<vector<char>> vvc;

const int dx[4]={0,0,1,-1};
const int dy[4]={1,-1,0,0};

void dfs(vvc &table, bool *alp, int x, int y, int r, int c, int &count, int &max){
    int nx, ny;
    if (max<count) max=count;

    for (int i=0; i<4; i++){
        nx = x+dx[i];
        ny = y+dy[i];

        if (nx >= 0 && nx < r && ny >= 0 && ny < c){
            if (!alp[(int)table[nx][ny]-65]){
                alp[(int)table[nx][ny]-65] = true;
                count++;
                dfs(table, alp, nx, ny, r, c, count, max);
                count--;
                alp[(int)table[nx][ny]-65] = false;
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int r, c, count=1, max=0;
    vvc table;
    bool alp[26] = {false, };

    cin >> r >> c;
    table.assign(r,vector<char>(c));

    for (int i=0; i<r; i++){
        for (int j=0; j<c; j++){
            cin >> table[i][j];
        }
    }

    alp[((int)table[0][0])-65] = true;

    dfs(table, alp, 0, 0, r, c, count, max);
    cout << max << "\n";

    return 0;
}