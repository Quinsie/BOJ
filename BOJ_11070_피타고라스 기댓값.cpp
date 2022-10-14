#include <bits/stdc++.h>

using namespace std;

double pitagoras_expect(double plus, double minus)
{
    if (plus == 0.0 && minus == 0.0) return 0.0;
    return (plus * plus) / (plus * plus + minus * minus);
}

void solve()
{
    int n, m; // team, game
    int a, b;
    double p, q; // team a, b, a got p scores, b got q scores
    vector <double> res;
    vector <pair <double, double>> score_table;

    cin >> n >> m;
    res.assign(n, 0.0);
    score_table.assign(n, pair <double, double> (0.0, 0.0));

    for (int i = 0; i < m; i++) {
        cin >> a >> b >> p >> q;
        a--; b--;

        score_table[a].first += p; score_table[a].second += q;
        score_table[b].first += q; score_table[b].second += p;
    }

    for (int i = 0; i < n; i++) {
        res[i] = pitagoras_expect(score_table[i].first, score_table[i].second);
    }

    sort(res.begin(), res.end());

    cout << (int)(res[n - 1] * 1000.0) << '\n';
    cout << (int)(res[0] * 1000.0) << '\n';
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
    int t; cin >> t; while (t--) solve();
    return 0;
}