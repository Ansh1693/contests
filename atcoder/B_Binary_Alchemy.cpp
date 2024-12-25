#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int N;
    cin >> N;

    vector<vector<int>> A(N + 1, vector<int>(N + 1));
    for (int i = 1; i <= N; ++i)
    {
        for (int j = 1; j <= i; ++j)
        {
            cin >> A[i][j];
        }
    }

    int current = 1;

    for (int i = 1; i <= N; ++i)
    {
        if (current >= i)
        {
            current = A[current][i];
        }
        else
        {
            current = A[i][current];
        }
    }

    cout << current << endl;

    return 0;
}
