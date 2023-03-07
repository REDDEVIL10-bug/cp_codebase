#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

//modular arithmetic
inline void normal(ll &a,ll mod){ a%=mod; (a<0) && (a+=mod);}
inline ll modAdd(ll a,ll b, ll mod){ a%=mod,b%=mod;normal(a,mod),normal(b,mod);return (a+b)%mod; }
inline ll modMul(ll a,ll b, ll mod){ a%=mod, b%=mod; normal(a,mod),normal(b,mod);return (a*b)%mod;}
inline ll modSub(ll a,ll b, ll mod){ a%=mod, b%=mod; normal(a,mod),normal(b,mod); a-=b; normal(a,mod); return a;}
inline ll modPow(ll b,ll p,ll mod){ ll r=1;while(p){if(p&1) r=modMul(r,b,mod);b=modMul(b,b,mod);p>>=1;}return r;}
inline ll modInv(ll a,ll mod){ return modPow(a,mod-2,mod);}
inline ll modDiv(ll a,ll b,ll mod){ return modMul(a,modInv(b,mod),mod);}

const int N= 5e5+5;
int ans[N];

int binary_search(int low,int high,ll arr[],ll search){
    int ans=0;
    while(low<=high){
        int mid=(low+high)/2;
        if(arr[mid]>=search){
            ans=mid;
            high=mid-1;
        }else{
            low=mid+1;
        }
    }
    return ans;
}
void solve(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        ll arr[n+2];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        ll search;cin>>search;
        cout<<binary_search(0,n-1,arr,search);
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}