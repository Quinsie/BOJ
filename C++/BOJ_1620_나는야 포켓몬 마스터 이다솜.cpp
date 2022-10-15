#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int input, output, temp_int;
    string temp;
    unordered_map <string, int> pokemon_si;
    unordered_map <int, string> pokemon_is;

    cin >> input >> output;
    for (int i = 0; i < input; i++) {
        cin >> temp;
        pokemon_si.insert({temp, i + 1});
        pokemon_is.insert({i + 1, temp});
    }
    for (int i = 0; i < output; i++) {
        cin >> temp;
        if (isdigit(temp[0]) == true) {
            temp_int = stoi(temp);
            cout << pokemon_is[temp_int] << "\n";
        }
        else {
            cout << pokemon_si[temp] << "\n";
        }
    }
    return 0;
}