#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

vector<vector<int>> tree;
vector<int> a, b, c;

// Function to perform DFS and check for a winner
string dfs(int node, int parent)
{
    unordered_set<int> positions;

    // Store the current positions of A, B, and C
    positions.insert(a[node]);
    positions.insert(b[node]);
    positions.insert(c[node]);

    string winner = "";

    // Check if any player is at the same position
    if (positions.size() == 1)
    {
        if (a[node] == b[node])
            winner = "B";
        else if (b[node] == c[node])
            winner = "C";
        else if (c[node] == a[node])
            winner = "A";
        return winner;
    }

    // Iterate through the neighbors of the current node
    for (int neighbor : tree[node])
    {
        if (neighbor != parent)
        {
            // Recursively explore the subtree
            string subWinner = dfs(neighbor, node);

            // If a winner is found in the subtree, return it
            if (!subWinner.empty())
                return subWinner;
        }
    }

    // No winner found in the subtree
    return "";
}

int main()
{
    int n; // Number of vertices
    cin >> n;

    // Initialize the tree
    tree.resize(n + 1);
    a.resize(n + 1);
    b.resize(n + 1);
    c.resize(n + 1);

    // Input the initial positions of A, B, and C
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i] >> b[i] >> c[i];
    }

    // Input the edges of the tree
    for (int i = 1; i < n; ++i)
    {
        int u, v;
        cin >> u >> v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }

    // Start DFS from the root (assuming 1 is the root)
    string result = dfs(1, 0);

    // Output the result
    if (result.empty())
    {
        cout << "DRAW\n";
    }
    else
    {
        cout << result << " wins\n";
    }

    return 0;
}
