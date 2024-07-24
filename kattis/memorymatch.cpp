#include <bits/stdc++.h>

using namespace std;

class MemoryMatch
{
private:
    int cards;
    unordered_map<string, int> ones;
    unordered_set<string> twos;

    void updateKnowledgeSingle(int c, string p)
    {
        if (ones.find(p) != ones.end())
        {
            if (ones[p] != c)
            {
                ones.erase(p);
                twos.insert(p);
                cards--;
            }
        }
        else if (twos.find(p) == twos.end())
        {
            ones[p] = c;
            cards--;
        }
    }

    void discard(string p)
    {
        if (twos.find(p) != twos.end())
        {
            twos.erase(p);
        }
        else if (ones.find(p) != ones.end())
        {
            ones.erase(p);
            cards--;
        }
        else
        {
            cards -= 2;
        }
    }

public:
    MemoryMatch(int n) : cards(n) {}

    void flip(int c1, int c2, string p1, string p2)
    {
        if (p1 == p2)
        {
            discard(p1);
        }
        else
        {
            updateKnowledgeSingle(c1, p1);
            updateKnowledgeSingle(c2, p2);
        }
    }

    int known()
    {
        int k = twos.size();
        if (cards == 2 && ones.empty())
        {
            k++;
        }
        else if (cards == ones.size())
        {
            k += cards;
        }
        return k;
    }
};

int main()
{
    int n, k;
    cin >> n >> k;
    MemoryMatch mm(n);
    for (int i = 0; i < k; i++)
    {
        int c1, c2;
        string p1, p2;
        cin >> c1 >> c2 >> p1 >> p2;
        mm.flip(c1, c2, p1, p2);
    }
    cout << mm.known() << endl;
    return 0;
}
