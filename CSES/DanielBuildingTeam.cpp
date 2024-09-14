#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N, M;
    cin >> N >> M;
    vector<vector<int>> friendship(N + 1, vector<int>(1, 0));
    vector<int> grouplist(N + 1, 0);
    vector<bool> checked(N + 1, false);
    for (int i = 0; i < M; i++)
    {
        int a, b;
        cin >> a >> b;
        friendship[a].push_back(b);
        friendship[b].push_back(a);
    }
    queue<pair<int, int>> awaitingsearch;
    for (int i = 0; i < N; i++)
    {
        if (friendship[i].empty() == false)
            awaitingsearch.push({i, 1});
        // pupil (i) goes to g1
        // all friends with (i) goes to g2
        while (awaitingsearch.empty() == false)
        {
            int pupil = awaitingsearch.front().first, group = awaitingsearch.front().second, ngroup = 1;
            awaitingsearch.pop();
            if (group == 1) ngroup = 2;

            if (grouplist[pupil] == group) continue;
            else if (grouplist[pupil] != 0)
            {
                cout << "IMPOSSIBLE";
                return 0;
            }
            else grouplist[pupil] = group;
            
            for (int everything : friendship[pupil])
            {
                if ((checked[everything] == false) && (everything != 0))
                    awaitingsearch.push({everything, ngroup});
            }
            friendship[pupil].resize(0);
            checked[pupil] = true;
        }
    }

    grouplist.erase(grouplist.begin());
    for (int everything : grouplist)
    {
        cout << everything << " ";
    }
}