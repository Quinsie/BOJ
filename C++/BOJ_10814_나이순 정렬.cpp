#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

class information {
    public:
        int age, number;
        string name;
};

bool compare(information a, information b)
{
    if (a.age == b.age) return a.number < b.number;
    return a.age < b.age;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int num;
    information info;
    vector<information> arr;

    cin >> num;
    for (int i = 0; i < num; i++) {
        cin >> info.age >> info.name;
        info.number = i;
        arr.emplace_back(info);
    }

    sort(arr.begin(), arr.end(), compare);
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i].age << ' ' << arr[i].name << '\n';
    }
    
    return 0;
}