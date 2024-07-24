

#include <iostream>
#include <vector>

using namespace std;

int handle(int curr, int dir, int n)
{
    int next;

    if (dir == 1)
    {
        next = (curr % n) + 1;
    }
    else
    {
        next = (curr - 2 + n) % n + 1;
    }

    return next;
}

void solve()
{
    int n, k;
    cin >> n >> k;

    string his;
    cin >> his;

    int curr = 1;
    int dir = 1;

    for (char ch : his)
    {
        switch (ch)
        {
        case 'U':
            curr = handle(curr, dir, n);
            break;
        case 'S':
            curr = handle(curr, dir, n);
            curr = handle(curr, dir, n);
            break;
        case 'R':
            dir *= -1;
            curr = handle(curr, dir, n);
            break;
        }
    }

    cout << curr << endl;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
