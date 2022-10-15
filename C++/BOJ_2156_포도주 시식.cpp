#include<iostream>
#include<algorithm>

using namespace std;

int drink[10001];
int dp[100001];
int N;

int main(){
    cin >> N;
    
    for(int i = 1; i<=N; i++){
        cin >> drink[i]; 
    }
    dp[1] = drink[1];
    dp[2] = drink[1] + drink[2];
    
    for(int i = 3; i<=N; i++){
        dp[i] = max(dp[i-1],max(dp[i-3]+drink[i-1]+drink[i],dp[i-2]+drink[i]));
    }
    
    cout << dp[N];
    
}