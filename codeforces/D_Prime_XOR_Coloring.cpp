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
vector<bool> prime;
vector<int> color;
void primeGen()
{
    int n = 2e5;
    prime = vector<bool>(n + 1, true);
    prime[0] = prime[1] = false;
    for (int i = 2; i * i <= n; i++)
    {
        if (prime[i])
        {
            for (int j = i * i; j <= n; j += i)
                prime[j] = false;
        }
    }
}

void colors(int n)
{
    color = vi(n + 1, -1);
    color[1] = 1;
    int curr = 1;
    loop(i, 0, n)
    {
        for (int j = i + 1; j < n; j++)
        {
            int xorVal = (i + 1) ^ (j + 1);
            cout << i + 1 << " " << j + 1 << "=" << xorVal << nL;

            if (prime[xorVal])
            {

                if (color[i + 1] == curr)
                {
                    curr++;
                }
                color[j + 1] = curr;
            }
            else
            {
                color[j + 1] = color[i + 1];
            }

            if (j - i >= 2)
                j++;
        }
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

    // primeGen();
    vi in(tc);
    int maxi = 0;
    loop(i, 0, tc)
    {
        cin >> in[i];
        maxi = max(maxi, in[i]);
    }

    // colors(maxi);
    loop(i, 0, tc)
    {
        if (in[i] > 5)
        {

            cout << 4 << nL;
            int tot = 0;
            loop(j, 0, in[i])
            {
                tot %= 4;
                tot++;
                cout << tot << " ";
            }
            cout << nL;
        }
        else if (in[i] == 1)
        {
            cout << 1 << nL;
            cout << "1" << nL;
        }
        else if (in[i] == 2)
        {
            cout << 2 << nL;
            cout << "1 2" << nL;
        }
        else if (in[i] == 3)
        {
            cout << 2 << nL;
            cout << "1 2 2" << nL;
        }
        else if (in[i] == 4)
        {
            cout << 3 << nL;
            cout << "1 2 2 3" << nL;
        }
        else if (in[i] == 5)
        {
            cout << 3 << nL;
            cout << "1 2 2 3 3" << nL;
        }
    }

    return 0;
}