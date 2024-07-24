#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
int main()
{
    ll t;
    cin>>t;
    while(t--){
        ll x,y;
        cin>>x>>y;

        if(x>y){
            cout<<y<<" "<<x<<"\n";
        }else if(y>x){
            cout<<x<<" "<<y<<"\n";
        }else{
            cout<<y<<" "<<x<<"\n";
        }
    } 
    return 0;
}