#include <iostream>
#include <utility>
#include <algorithm>
#include <vector>

using namespace std;

class student {
    public:
        string name;
        int kor;
        int eng;
        int mat;
};

bool compare(student s1, student s2)
{
    if (s1.kor == s2.kor && s1.eng == s2.eng && s1.mat == s2.mat) return s1.name < s2.name;
    else if (s1.kor == s2.kor && s1.eng == s2.eng) return s1.mat > s2.mat;
    else if (s1.kor == s2.kor) return s1.eng < s2.eng;
    return s1.kor > s2.kor;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int num;
    student s;
    vector<student> arr;

    cin >> num;
    for (int i = 0; i < num; i++) {
        cin >> s.name >> s.kor >> s.eng >> s.mat;
        arr.push_back(s);
    }

    sort(arr.begin(), arr.end(), compare);
    for (int i = 0; i < num; i++) cout << arr[i].name << '\n';

    return 0;
}