#include <iostream>

using namespace std;

int n,res;
bool map[15][15];

bool isPossible(int row, int col) {
    int x = row-1; int y = col;
    while(x>=0){
        if(map[x][y]) return false;
        x-=1;
    }
    x = row-1; y = col-1;
    while(x>=0 && y>=0){
        if(map[x][y]) return false;
        x-=1;
        y-=1;
    }
    x = row-1; y = col+1;
    while(x>=0 && y<n){
        if(map[x][y]) return false;
        x-=1;
        y+=1;
    }
    return true;
}

void DFS(int row) {
    if(row==n) { 
        res++;
    } else {
        for(int col=0;col<n;col++) {
            if(!map[row][col] && isPossible(row,col)) {
                map[row][col]=true;
                DFS(row+1);
                map[row][col]=false;
            }
        }
    }
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    DFS(0);
    cout<<res;
}