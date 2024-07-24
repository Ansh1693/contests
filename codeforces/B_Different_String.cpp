#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double

void solve(){
string s;
        cin>>s;
        ll n=s.size();
        if(n==1){
            cout<<"NO\n";
            return;
        }
        for(ll i = 1;i<n;i++){
            if(s[i-1]!=s[i]) {swap(s[i-1],s[i]);
            cout<<"YES\n";
            cout<<s<<"\n";
            return;
            }
        }

        cout<<"NO\n";
}
int main()
{
    ll t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}