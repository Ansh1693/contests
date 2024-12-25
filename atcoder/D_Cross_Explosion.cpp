#include <bits/stdc++.h>
using namespace std;

#define int long long
#define nL "\n"

int H, W, Q;
vector<set<int>> rowWalls, colWalls;

void solve()
{
    cin >> H >> W >> Q;

    rowWalls.resize(H);
    colWalls.resize(W);

    for (int i = 0; i < H; ++i)
    {
        for (int j = 0; j < W; ++j)
        {
            rowWalls[i].insert(j);
            colWalls[j].insert(i);
        }
    }

    // Process queries
    for (int q = 0; q < Q; ++q)
    {
        int r, c;
        cin >> r >> c;
        --r, --c;

        if (rowWalls[r].find(c) != rowWalls[r].end())
        {
            rowWalls[r].erase(c);
            colWalls[c].erase(r);
        }
        else
        {
            auto itUp = colWalls[c].lower_bound(r);
            if (itUp != colWalls[c].begin())
            {
                --itUp;
                rowWalls[*itUp].erase(c);
                colWalls[c].erase(itUp);
            }

            auto itDown = colWalls[c].upper_bound(r);
            if (itDown != colWalls[c].end())
            {
                rowWalls[*itDown].erase(c);
                colWalls[c].erase(itDown);
            }

            auto itLeft = rowWalls[r].lower_bound(c);
            if (itLeft != rowWalls[r].begin())
            {
                --itLeft;
                colWalls[*itLeft].erase(r);
                rowWalls[r].erase(itLeft);
            }

            auto itRight = rowWalls[r].upper_bound(c);
            if (itRight != rowWalls[r].end())
            {
                colWalls[*itRight].erase(r);
                rowWalls[r].erase(itRight);
            }
        }
    }

    int remainingWalls = 0;
    for (int i = 0; i < H; ++i)
    {
        remainingWalls += rowWalls[i].size();
    }

    cout << remainingWalls << nL;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int tc = 1;
    // cin >> tc;  // Uncomment if multiple test cases
    while (tc--)
    {
        solve();
    }

    return 0;
}
