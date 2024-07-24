#include <bits/stdc++.h>
using namespace std;
#define ll long long

signed main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        ll num_batsmen, num_bowlers;
        cin >> num_batsmen >> num_bowlers;

        vector<ll> batsmen_skills(num_batsmen);
        vector<ll> bowlers_skills(num_bowlers);

        for (auto &batsman : batsmen_skills)
            cin >> batsman;

        for (auto &bowler : bowlers_skills)
            cin >> bowler;

        if (num_batsmen < 4 || num_bowlers < 4 || num_batsmen + num_bowlers < 11)
        {
            cout << "-1\n";
            continue;
        }

        sort(batsmen_skills.begin(), batsmen_skills.end(), greater<ll>());
        sort(bowlers_skills.begin(), bowlers_skills.end(), greater<ll>());

        ll total_skill = 0;

        for (ll i = 0; i < 4; i++)
        {
            total_skill += batsmen_skills[i] + bowlers_skills[i];
        }

        ll idx_batsmen = 4, idx_bowlers = 4;
        for (ll k = 0; k < 3; k++)
        {
            if (idx_batsmen < num_batsmen && idx_bowlers < num_bowlers)
            {
                if (batsmen_skills[idx_batsmen] > bowlers_skills[idx_bowlers])
                {
                    total_skill += batsmen_skills[idx_batsmen];
                    idx_batsmen++;
                }
                else
                {
                    total_skill += bowlers_skills[idx_bowlers];
                    idx_bowlers++;
                }
            }
            else if (idx_batsmen < num_batsmen)
            {
                total_skill += batsmen_skills[idx_batsmen];
                idx_batsmen++;
            }
            else
            {
                total_skill += bowlers_skills[idx_bowlers];
                idx_bowlers++;
            }
        }

        cout << total_skill << endl;
    }
    return 0;
}
