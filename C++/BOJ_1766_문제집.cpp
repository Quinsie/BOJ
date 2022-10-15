#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef vector<vector<int>> vvi;
typedef vector<int> vi;

void func(vvi &problem, vi &pointed, int pb, int info)
{
    int p;
    priority_queue<int, vi, greater<int>> pq;

    for(int i = 1; i <= pb; i++) {
        if(pointed[i] == 0) {
            pq.push(i);
        }
    }
    for(int i = 1; i <= pb; i++) {
        p = pq.top();
        pq.pop();
        cout << p << ' ';

        for(auto point : problem[p]) {
            pointed[point]--;
            if(pointed[point] == 0)
                pq.push(point);
        }
    }

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int from, to, pb, info;
    vvi problem;
    vi pointed;

    cin >> pb >> info;
    problem.assign(pb + 1, vi());
    pointed.assign(pb + 1, 0);

    for(int i = 0; i < info; i++) {
        cin >> from >> to;
        problem[from].emplace_back(to);
        pointed[to]++;
    }

    func(problem, pointed, pb, info);

    return 0;
}