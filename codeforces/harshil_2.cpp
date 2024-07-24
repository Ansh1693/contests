#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double

void solve(vector<string> &auth, vector<vector<string>> &req)
{
    unordered_map<string, int> mp;
    for (auto it : auth)
    {
        mp[it] = 1;
    }

    vector<string> ans;

    for (auto it : req)
    {
        if (it[0] == "GET")
        {
            int i = 12;
            while (i < it.size())
            {
                if (it[1][i] == '?')
                {
                    break;
                }

                i++;

                string token = "";

                while (i < it.size() && it[1][i] != '=')
                {
                    i++;
                }

                i++;

                while (i < it.size() && it[1][i] != '&')
                {
                    token += it[1][i];
                    i++;
                }

                i++;

                if (mp[token] != 1)
                {
                    ans.push_back("INVALID");
                }
                else
                {
                    string ans1 = "VALID";
                    ans1 += ",";

                    while (i < it.size())
                    {

                        if (it[1][i] == '=' || it[1][i] == '&')
                        {
                            ans1.push_back(',');
                        }
                        else
                        {
                            ans1.push_back(it[1][i]);
                        }

                        i++;
                    }
                    ans.push_back(ans1);
                }
            }
        }
        else if (it[0] == "POST")
        {
            int i = 12;
            while (i < it.size())
            {
                if (it[1][i] == '?')
                {
                    break;
                }

                i++;

                string token = "";

                while (i < it.size() && it[1][i] != '=')
                {
                    i++;
                }

                i++;

                while (i < it.size() && it[1][i] != '&')
                {
                    token += it[1][i];
                    i++;
                }

                i++;

                string name = "";

                while (i < it.size() && it[1][i] != '=')

                {
                    name += it[1][i];
                    i++;
                }

                if (mp[token] != 1)
                {
                    ans.push_back("INVALID");
                }
                else
                {
                    string ans1 = "VALID";
                    ans1 += ",";

                    while (i < it.size())
                    {

                        if (it[1][i] == '=' || it[1][i] == '&')
                        {
                            ans1.push_back(',');
                        }
                        else
                        {
                            ans1.push_back(it[1][i]);
                        }

                        i++;
                    }
                    ans.push_back(ans1);
                }
            }
        }
    }
}

int main()
{
    return 0;
}