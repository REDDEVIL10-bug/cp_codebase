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

void solve(){
    
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}