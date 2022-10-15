#include <iostream>
#include <vector>

using namespace std;

typedef vector<vector<int>> vvi;

void dfs(vvi& grape, vector<bool> &check, int now){
    int temp;
    check[now]=true;

    for (int i=0; i<grape[now].size(); i++){
        temp=grape[now][i];
        if (!check[temp]){
            dfs(grape, check, temp);
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int node, line, start, end, count=0;
    vvi grape;
    vector <bool> check;
    cin >> node >> line;

    grape.assign(node,vector<int>());
    check.assign(node, false);

    for (int i=0; i<line; i++){
        cin >> start >> end;
        start--; end--;
        grape[start].emplace_back(end);
        grape[end].emplace_back(start);
    }

    for (int i=0; i<node; i++){
        if (!check[i]){
            count++;
            dfs(grape, check, i);
        }
    }
    cout<<count<<"\n";
    return 0;
}