#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define input freopen("1.txt","r",stdin);
#define output freopen("output.txt","w",stdout);
#define ll long long int
#define pb push_back
#define eb emplace_back
#define vi vector<int>
#define vii vector<vi>
#define vl vector<ll>
#define vll vector<vl>
#define pll pair<ll,ll>
#define mp make_pair
#define vpl vector<pll> 
using namespace std;
 
const int p=1e9+7;
const int maxn=2e5+2;

inline int mul(int a,int b) { 
    ll x= (a*1ll*b);
    if(x>=p) return x%p;
    return x;
}

bool cmp1(int a, int b) {
    return abs(a)>abs(b);   // positive product
}

void solve() {
    int N, K; cin>>N>>K;
    int A[N], neg;
    for(int i=0;i<N;i++) cin>>A[i];

    sort(A,A+N,&cmp1);
    neg=0; 
    int lp=-1, ln=-1, np=N, nn=N;
    
    for(int i=0;i<K;i++) {
        if(A[i]<0) {
            neg++; ln=i;
        }
        else lp=i;
    }

    int ans=1;
    bool F=false;

    if(ln==-1 || (neg&1)==0) {
        // do the product of absolute values;
        for(int i=0;i<K;i++) ans=mul(ans,abs(A[i]));
    }
    else {
        if(lp==-1) {
            // find next positive or zero and simply replace with last negative
            for(int i=K;i<N;i++) {
                if(A[i]>=0) {
                    np=i; break; 
                }
            }

            if(np<N) {
                for(int i=0;i<ln;i++) ans=mul(ans,abs(A[i]));
                ans=mul(ans,A[np]);
            }
            else F=true;
        }
        else {
            // find next negative and next positive and compare the cross product 
            // keep the highest one 
            for(int i=K;i<N;i++) {
                if(A[i]>=0) {
                    np=i; break; 
                }
            }
            for(int i=K;i<N;i++) {
                if(A[i]<0) {
                    nn=i; break; 
                }
            }
            if(np<N && nn<N) {
                ll keepneg= abs(A[ln])*1LL*abs(A[nn]);
                ll keeppos= A[lp]*1LL*A[np];
                if(keepneg>keeppos) {
                    for(int i=0;i<K;i++) {
                        if(i!=lp) ans=mul(ans,abs(A[i]));
                    }
                    ans=mul(ans,abs(A[nn]));
                }
                else {
                    for(int i=0;i<K;i++) {
                        if(i!=ln) ans=mul(ans,abs(A[i]));
                    }
                    ans=mul(ans,A[np]);
                }
            }
            else if(np<N) {
                for(int i=0;i<K;i++) {
                    if(i!=ln) ans=mul(ans,abs(A[i]));
                }
                ans=mul(ans,abs(A[np]));
            }
            else if(nn<N) {
                for(int i=0;i<K;i++) {
                    if(i!=lp) ans=mul(ans,abs(A[i]));
                }
                ans=mul(ans,abs(A[nn]));
            }
            else F=true;
        }
    }

    if(F) {
        ans=1;
        for(int i=0;i<K;i++) {
            ans=mul(ans,abs(A[N-1-i]));
        }
        if(ans==0) cout<<ans<<"\n";
        else cout<<(p-ans)%p<<"\n";
    }
    else cout<<ans<<"\n";
}


int main() {
    fast
    int t=1; 
    while(t--) solve();
    return 0;
}