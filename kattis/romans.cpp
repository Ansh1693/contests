#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
int miles_to_paces(double miles)
{
    const int roman_paces_per_mile = 1000;
    const int modern_feet_per_mile = 5280;
    const int roman_feet_per_mile = 4854;

    double roman_paces = (miles * modern_feet_per_mile) / roman_feet_per_mile * roman_paces_per_mile;
    int rounded_paces = round(roman_paces);
    return rounded_paces;
}

int main()
{
    double miles;
    cin >> miles;
    int result = miles_to_paces(miles);
    cout << result << std::endl;
    return 0;
}