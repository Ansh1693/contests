#include <bits/stdc++.h>
using namespace std;
#define int long long
#define nL "\n"
#define pb push_back
#define mk make_pair
#define F first
#define S second
#define all(x) (x).begin(), (x).end()
#define forEqual(i, a, b) for (int i = a; i <= b; i++)
#define loop(i, a, b) for (int i = a; i < b; i++)
#define rloop(i, a, b) for (int i = b - 1; i >= a; i--)
#define sortall(x) sort(all(x))
#define PI 3.1415926535897932384626
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pii;
typedef unordered_set<int> usi;
typedef set<int> si;
typedef unordered_map<int, int> umii;
typedef unordered_map<string, int> umsi;
typedef unordered_map<int, bool> umib;
typedef unordered_map<string, bool> umsb;
typedef unordered_map<string, vi> umsvi;
typedef unordered_map<int, vi> umivi;
typedef map<int, int> mii;
const int mod = 1e9 + 7;

bool distributeInstructions(const string &s, int n, string &rover, string &helicopter)
{
    int netX = 0, netY = 0;

    for (char c : s)
    {
        if (c == 'N')
            netY++;
        else if (c == 'S')
            netY--;
        else if (c == 'E')
            netX++;
        else if (c == 'W')
            netX--;
    }

    if (abs(netX) % 2 != 0 || abs(netY) % 2 != 0)
    {
        return false;
    }

    int halfNetX = netX / 2;
    int halfNetY = netY / 2;

    int currentX = 0,
        currentY = 0;
    bool roverHasInstruction = false, helicopterHasInstruction = false;

    for (char c : s)
    {
        if (c == 'N')
        {
            if (currentY < halfNetY)
            {
                rover += c;
                currentY++;
                roverHasInstruction = true;
            }
            else
            {
                helicopter += c;
                helicopterHasInstruction = true;
            }
        }
        else if (c == 'S')
        {
            if (currentY > -halfNetY)
            {
                rover += c;
                currentY--;
                roverHasInstruction = true;
            }
            else
            {
                helicopter += c;
                helicopterHasInstruction = true;
            }
        }
        else if (c == 'E')
        {
            if (currentX < halfNetX)
            {
                rover += c;
                currentX++;
                roverHasInstruction = true;
            }
            else
            {
                helicopter += c;
                helicopterHasInstruction = true;
            }
        }
        else if (c == 'W')
        {
            if (currentX > -halfNetX)
            {
                rover += c;
                currentX--;
                roverHasInstruction = true;
            }
            else
            {
                helicopter += c;
                helicopterHasInstruction = true;
            }
        }
    }

    if (!roverHasInstruction || !helicopterHasInstruction)
    {
        return false;
    }

    return true;
}

void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;

    string rover = "", helicopter = "";

    if (distributeInstructions(s, n, rover, helicopter))
    {
        cout << rover << nL;
        cout << helicopter << nL;
    }
    else
    {
        cout << "NO" << nL;
    }
}
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // #ifndef ONLINE_JUDGE
    // freopen("div7.in", "r", stdin);
    // freopen("div7.out", "w", stdout);
    // #endif
    int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; t++)
    {
        // cout << "Case #" << t << ": ";
        solve();
    }
    return 0;
}