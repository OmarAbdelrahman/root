#include <bits/stdc++.h>
using namespace std;

#define SIZE(a) (int) (a).size()

struct set_t
{
    vector<int> a;
    vector<pair<int, int>> commands;

    bool has(int x)
    {
        int cnt = binary_search(begin(a), end(a), x);
        for (auto p : commands) if (p.first == x) cnt += p.second;
        return cnt == 1;
    }

    bool add(int x)
    {
        if (has(x)) return false;
        commands.push_back({x, 1});
        return true;
    }

    bool remove(int x)
    {
        if (!has(x)) return false;
        commands.push_back({x, -1});
        return true;
    }

    int find(int x)
    {
        if (!has(x)) return -1;
        int cnt = lower_bound(begin(a), end(a), x) - begin(a);
        for (auto p : commands) if (p.first < x) cnt += p.second;
        return cnt + 1;
    }

    void rebuild()
    {
        if (SIZE(commands) * SIZE(commands) <= SIZE(a))
            return;
        for (int x : a) commands.push_back({x, 1});
        sort(begin(commands), end(commands));
        a.clear();
        int cnt = 0;
        for (int i = 0; i < (int) commands.size(); i++) {
            if (i > 0 && commands[i - 1].first != commands[i].first) {
                if (cnt == 1) a.push_back(commands[i - 1].first);
                cnt = 0;
            }
            cnt += commands[i].second;
        }
        if (cnt == 1) {
            a.push_back(commands.back().first);
        }
        commands.clear();
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int q, v;
    cin >> q;

    set_t s;
    while (q-- > 0) {
        string cmd;
        cin >> cmd >> v;
        if (cmd.front() == 'A') {
            cout << (s.add(v) ? "YES\n" : "NO\n");
        } else if (cmd.front() == 'R') {
            cout << (s.remove(v) ? "YES\n" : "NO\n");
        } else {
            cout << s.find(v) << '\n';
        }
        s.rebuild();
    }
}
