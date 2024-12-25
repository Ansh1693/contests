#include <bits/stdc++.h>
using namespace std;
#define f(i, n) for (int i = 0; i < n; i++)
#define fo(i, x, n) for (int i = x; i < n; i++)
#define fr(i, k, n) for (int i = k; i >= n; i--)
#define int long long
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define all(x) x.begin(), x.end()
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
typedef map<int, int> mii;
const int mod = 1e9 + 7;

bool solve2(vi &arr, int L, int R, int m)
{
    int curr_min = *min_element(arr.begin() + L, arr.begin() + R + 1);
    return curr_min != m;
}

void solution()
{
    int n, k;
    cin >> n >> k;

    vector<array<int, 3>> v(k);
    f(i, k)
    {
        cin >> v[i][0] >> v[i][1] >> v[i][2];
        v[i][0]--;
        v[i][1]--;
    }

    vi arr(n);
    f(i, n) arr[i] = i + 1;

    bool flag = true;
    for (auto &c : v)
    {
        int L = c[0], R = c[1], m = c[2];

        if (!solve2(arr, L, R, m))
        {
            bool flag2 = false;
            if (m + 1 <= n)
            {
                // if(m+1<n)
                vi temp = arr;
                fo(i, L, R + 1)
                {
                    if (temp[i] <= m)
                        temp[i] = m + 1;
                }
                bool flag3 = true;
                for (auto &it : v)
                {
                    if (it == c)
                        break;
                    if (!solve2(temp, it[0], it[1], it[2]))
                    {
                        flag3 = false;
                        break;
                    }
                }

                if (flag3)
                {
                    arr = temp;
                    flag2 = true;
                }
            }
            if (!flag2 && m > 1)
            {
                fo(i, L, R + 1)
                {
                    vi temp = arr;
                    temp[i] = m - 1;

                    bool flag3 = true;
                    for (auto &it : v)
                    {
                        if (&it == &c)
                            break;

                        if (!solve2(temp, it[0], it[1], it[2]))
                        {
                            flag3 = false;
                            break;
                        }
                    }
                    // flag2 = false;
                    if (flag3)
                    {
                        arr = temp;
                        flag2 = true;
                        break;
                    }
                }
            }
            //  flag = false;
            if (!flag2)
            {
                flag = false;
                break;
            }
        }
    }

    if (!flag)
    {
        cout << -1;
        return;
    }

    f(i, n) { cout << arr[i] << " "; }
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    cin >> t;
    while (t--)
    {
        solution();
        cout << endl;
    }
    return 0;
}