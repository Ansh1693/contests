#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ld long double

int helper(int j,int N, int turn, vector<int>& arr , vector<vector<int>> &dp){
    if(j>=N){
        return 0;
    }

    if(dp[j][turn] != -1) return dp[j][turn];

    if(arr[j] == 0 && arr[j-1]==1){
        return dp[j][turn] = 1+helper(j+1,N,turn, arr,dp);
    }else if(!turn && arr[j-1] == 0 && arr[j]==1){
        return dp[j][turn]= helper(j+1,N,!turn,arr,dp);
     }else if(turn && arr[j-1] == 0 && arr[j]==1){
        return dp[j][turn]= 1+ helper(j+1,N,turn,arr,dp);
     }else{
        return helper(j+1,N,turn,arr,dp);
     }
}

void solve(){
    string s;
    cin>>s;
    int n=s.length();
    if(n==1){
        cout<<"1\n";
        return;
    }

    vector<int> arr(n);
    for(int i=0;i<n;i++){
        if(s[i]=='0') arr[i]=0;
        else arr[i]=1;
    }
    
    vector<vector<int>> dp(n,vector<int>(2,-1));

    int ans = 1+helper(1,n,0,arr,dp);

    cout<<ans<<"\n";
    
}
signed main()
{
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}