#include <iostream>
#include <unordered_set>
#include <vector>

int main()
{
    int m;
    std::cin >> m;

    std::unordered_set<int> multiset_values;
    std::vector<int> powers_of_two;

    for (int i = 0; i < 30; ++i)
    {
        powers_of_two.push_back(1 << i);
    }

    for (int i = 0; i < m; ++i)
    {
        int t, v;
        std::cin >> t >> v;

        if (t == 1)
        {
            for (int j = 0; j < powers_of_two.size(); ++j)
            {
                int value = powers_of_two[j] * v;
                multiset_values.insert(value);
            }
        }
        else
        {
            bool possible = false;
            for (int subset_sum : multiset_values)
            {
                if (multiset_values.count(v - subset_sum) > 0)
                {
                    possible = true;
                    break;
                }
            }

            std::cout << (possible ? "YES" : "NO") << std::endl;
        }
    }

    return 0;
}
