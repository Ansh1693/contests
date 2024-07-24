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

void solve()
{
    int n;
    string s;
    cin >> n;
    cin >> s;

    if (s[0] == s[n - 1] && s[0] == '1')
    {
        cout << "YES\n";
        return;
    }

    string a = "";
    int i = 0;
    int maxLen = 0;
    while (i < n)
    {
        if (s[i] == '1')
        {
            int curr = 0;
            while (i < n && s[i] == '1')
            {
                a.pb(s[i]);
                curr++;
                i++;
            }

            maxLen = max(curr,maxLen);
            if(maxLen>2) break;
        }else{            
            while(i<n && s[i] == '0'){
                i++;
            }

            a.pb('0');
        }
    }

    if(maxLen>2){
        cout << "YES\n";
        return;
    }

    int cnt1=0,cnt0=0;

    for(auto it: a){
        if(it == '1') cnt1++;
        else cnt0++;
    }

    if(cnt1>cnt0){
        cout << "YES\n";
    }else{
        cout << "NO\n";
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