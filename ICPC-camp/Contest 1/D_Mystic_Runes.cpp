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
int n, m;
string s[100005];
string a[200005];
unordered_map<char, int> mp;

class TrieNode
{
public:
    char data;
    TrieNode *children[10];
    bool isTerminal;
    int cnt;

    // constructor
    TrieNode(char ch)
    {
        data = ch;
        for (int i = 0; i < 10; i++)
        {
            children[i] = NULL;
        }
        isTerminal = false;
        cnt = 0;
    }
};

class Trie
{
public:
    TrieNode *root;

    // constructor
    Trie()
    {
        this->root = new TrieNode('\0');
    }

    void insertUtil(TrieNode *root, string word)
    {
        // base case
        if (word.length() == 0)
        {
            root->isTerminal = true;
            return;
        }

        // assuming that word will be UPPERCASE
        int index = word[0] - '0';
        TrieNode *child;

        // when child is present
        if (root->children[index] != NULL)
        {
            child = root->children[index];
            child->cnt++;
        }
        // when child not present
        else
        {
            child = new TrieNode(word[0]);
            root->children[index] = child;
            child->cnt++;
        }

        // recursion sambhal lega
        insertUtil(child, word.substr(1));
    }

    int searchUtil(TrieNode *root, string word)
    {
        // base case

        TrieNode *node = root;

        for (auto ch : word)
        {
            if (ch == '0' || ch == '1')
            {
                return 0;
            }

            int index = ch - '0';
            TrieNode *child = node->children[index];
            if (child == NULL)
            {
                return 0;
            }
            node = child;
        }

        return node->cnt;
    }

    // FUNCTION FOR INSERTION IN A TRIE
    void insertWord(string word)
    {
        insertUtil(root, word);
    }

    // FUNCTION FOR SEARCHING IN A TRIE
    int searchWord(string word)
    {
        return searchUtil(root, word);
    }

    // FUNCTION FOR REMOVAL IN A TRIE
};

void solve()
{
    Trie t;
    cin >> n >> m;
    loop(i, 0, n)
    {
        cin >> s[i];
        for (int j = 0; j < s[i].size(); j++)
        {
            s[i][j] = mp[s[i][j]] + '0';
        }
        t.insertWord(s[i]);
    }
    loop(i, 0, m)
    {
        cin >> a[i];
        cout << t.searchWord(a[i]) << nL;
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
    // cin >> tc;
    mp['a'] = 2;
    mp['b'] = 2;
    mp['c'] = 2;
    mp['d'] = 3;
    mp['e'] = 3;
    mp['f'] = 3;
    mp['g'] = 4;
    mp['h'] = 4;
    mp['i'] = 4;
    mp['j'] = 5;
    mp['k'] = 5;
    mp['l'] = 5;
    mp['m'] = 6;
    mp['n'] = 6;
    mp['o'] = 6;
    mp['p'] = 7;
    mp['q'] = 7;
    mp['r'] = 7;
    mp['s'] = 7;
    mp['t'] = 8;
    mp['u'] = 8;
    mp['v'] = 8;
    mp['w'] = 9;
    mp['x'] = 9;
    mp['y'] = 9;
    mp['z'] = 9;
    for (int t = 1; t <= tc; t++)
    {
        // cout << "Case #" << t << ": ";
        solve();
    }
    return 0;
}