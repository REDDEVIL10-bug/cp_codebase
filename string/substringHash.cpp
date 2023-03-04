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

const int maxN= 2e5+5;
ll dp[2][maxN+5];
int n; string s;

void get_hash1() {
    const ll p = 31, m = 1e9 + 7;
    ll hash_value = 0;
    ll p_pow = 1;
    for(int i = 0; i < n; i++) {
        hash_value = (hash_value + (s[i] - 'a' + 1) * p_pow) % m;
        p_pow = (p_pow * p) % m;
        dp[0][i] = hash_value;
    }
}
void get_hash2() {
    const ll p = 37, m = 1e9 + 9;
    ll hash_value = 0;
    ll p_pow = 1;
    for(int i = 0; i < n; i++) {
        hash_value = (hash_value + (s[i] - 'a' + 1) * p_pow) % m;
        p_pow = (p_pow * p) % m;
        dp[1][i] = hash_value;
    }
}
ll generate(int i, ll p, ll mod,int ind){
    ll result=0,suffix=0;
    if(i!=0){
        result=dp[ind][i-1];
    }
    suffix=dp[ind][n-1]-dp[ind][i+1];
    suffix=modDiv(suffix,p,mod);
    result=modAdd(result,suffix,mod);

    return result;
}

void solve(){
    int t;cin>>t;
    while(t--){
        cin>>n;
        cin>>s;
        get_hash1();
        get_hash2();
        set<pair<ll,ll> > se;
        ll m1=1e9+7,m2=1e9+9;
        for(int i=0;i<n-1;i++){
            ll fh=generate(i,31*31,1e9+7,0);
            ll sh=generate(i,37*37,1e9+9,1);
            se.insert(make_pair(fh,sh));
        }
        cout<<se.size()<<endl;
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}