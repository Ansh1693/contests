#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double

int getQuad(int a){
    if(a>=1 && a<4) return 1;
    else if(a>=4 && a<7) return 2;
    else if(a>=7 && a<10) return 3;
    return 4;
}   

void solve(){
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    
    int t = min(a,b);
    b = max(a,b);
    a=t;

    bool point1 = false;
    bool point2 = false;

    for(int i=a;i<=b;i++){
        if(i==c) point1= true;
        if(i==d) point2 = true;
    }

    if((point1 && point2) || (!point1 && !point2)){
        cout<<"NO\n";
    }else{ cout<<"YES\n";}

}

int main()
{
    ll t;
    cin>>t;
    while(t--) {
        solve();
    }
    return 0;
}