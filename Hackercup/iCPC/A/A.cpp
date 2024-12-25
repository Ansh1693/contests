#include <bits/stdc++.h>

using namespace std;

class DSU
{
    vector<int> parent, size;
    int n;

public:
    DSU(int n)
    {
        this->n = n;
        parent.resize(n);
        size.resize(n);
        for (int i = 0; i < n; i++)
        {
            parent[i] = i;
            size[i] = 1;
        }
    }

    int find(int x)
    {
        if (parent[x] == x)
            return x;
        return parent[x] = find(parent[x]);
    }

    void unite(int x, int y)
    {
        int s1 = find(x);
        int s2 = find(y);
        if (s1 != s2)
        {
            if (size[s1] < size[s2])
                swap(s1, s2);
            parent[s2] = s1;
            size[s1] += size[s2];
        }
    }

    bool same(int x, int y)
    {
        return find(x) == find(y);
    }
};

int main()
{
    int n;
    cin >> n;
    DSU dsu(n);

    return 0;
}