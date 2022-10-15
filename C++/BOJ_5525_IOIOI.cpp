#include <iostream>
#include <string>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m, ans = 0, count = 0;
    string word;

    cin >> n >> m >> word;

    for(int i = 1; i < word.size(); i++){
        count = 0;
        if (word[i - 1] == 'I') {
            while(word[i] == 'O' && word[i + 1] == 'I'){
                i += 2;
                count++;
                if(count == n){ 
                    count--;
                    ans++;
                }
            }
        }
    }
    cout << ans <<'\n';

    return 0;
}