#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int INF = 10e7;
const int MAX = 20001;

class Node {
public:
    int w, idx;
    bool operator < (const Node& other) const {
        return w > other.w;
    }
};

void solve()
{
    int V, E, K, u, v, w;
    vector <Node> graph[MAX];

    cin >> V >> E >> K;
    while (E--)
    {
        cin >> u >> v >> w;
        graph[u].push_back({w, v});
    }

    vector<int> cache(V + 1, INF);
    cache[K] = 0;
    priority_queue<Node> pq;
    pq.push({0, K});


    while (!pq.empty())
    {
        Node curr = pq.top();
        pq.pop();
        if (curr.w > cache[curr.idx])
            continue;

        for (const auto &next : graph[curr.idx])
        {
            if (next.w + curr.w < cache[next.idx])
            {
                cache[next.idx] = next.w + curr.w;
                pq.push({cache[next.idx], next.idx});
            }
        }
    }

    for (int i = 1; i <= V; i++)
    {
        if (cache[i] == INF)
            cout << "INF" << '\n';
        else
            cout << cache[i] << '\n';
    }

}

void optimize()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int main()
{
    optimize();
    solve();
    return 0;
}