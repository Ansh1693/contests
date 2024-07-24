#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ld long double

int findIndex(int x, int k, vector<int> &a, vector<int>&b){
    int left = 1, right = k;
            while (left < right) {
                int mid = left + (right - left) / 2;
                if (a[mid] < x) {
                    left = mid + 1;
                } else {
                    right = mid;
                }
            }
double ans = (double)b[left-1];
    int d = (x - a[left-1]);
    double totalDist = (double)(a[left]-a[left-1]);
    double totalTime = (double)(b[left]-b[left-1]);
    double dist = (double)d / totalDist;
    dist *= totalTime;
    ans += dist;

            // cout<<x<<":"<<ans<<" "<<a[left-1]<<" "<<d<<" "<<b[left]<<" "<<b[right]<<" "<<totalDist<<" "<<totalTime<<"\n";

            return (int) ans;
        
}
void solve(){
    int n,k,q;
    cin>>n>>k>>q;
    vector<int> a(k+1,0),b(k+1,0);
    for(int i=1;i<=k;i++){
        cin>>a[i];
        
        
    }
    for(int i=1;i<=k;i++){
        cin>>b[i];
    }
    int x;

    // for(int i=1;i<=k;i++){
    //     cout<<a[i]<<" "<<b[i]<<endl;
    // }
    for(int i=0;i<q;i++){
        cin>>x; 

        cout<<findIndex(x,k+1,a,b)<<" ";
    }

    cout<<"\n";


}
signed main()
{
    int t;
    cin>>t;
    while(t--)
    {
        solve();
    }
    return 0;
}