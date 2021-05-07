#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define input freopen("23.txt","r",stdin);
#define output freopen("output.txt","w",stdout);
#define ll long long int
#define pb push_back
#define ppb pop_back
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
const int maxn=1e6+2;
map<ll,int> price;
int a[maxn]; 
ll psum[maxn];

int main() {
    fast 
    // input output
    int t, c = 1;
    for(cin >> t; t--;) {
        price.clear();
        int N, M; cin >> N >> M;
        for(int i = 0; i < N; i++) cin >> a[i];
        for(int i=0; i<N; i++) psum[i]=0;
        int nofuel = 0;
        if( M >= N-1 ) cout << "Case #" << c++ << ":" << " " << 0 << endl;
        else {
            bool poss = true;
            for(int i = N-2; i > 0; i--) {
                if(a[i] == 0) ++nofuel; 
                if(nofuel == M) { poss = false; break; }
                if(a[i] != 0) {
                    if(!price.empty()) {
                        if(i >= N-1-M) {
                            psum[i] = a[i];
                            price[psum[i]]++;
                        }
                        else {
                            map<ll, int> :: iterator it = price.begin();    
                            psum[i] = it->first + a[i];
                            price[psum[i]]++;
                        } 
                    }
                    else {
                        psum[i] = a[i];
                        price[psum[i]]++;
                    }
                    nofuel = 0;
                }
                if(i+M <= N-2 && psum[i+M] != 0) {
                    price[psum[i+M]]--;
                    if(price[psum[i+M]]==0) price.erase(psum[i+M]);
                }
            }
            if(!poss) cout << "Case #" << c++ << ":" << " " << -1 << endl;
            else {
                    map<ll, int> :: iterator it = price.begin();
                    cout << "Case #" << c++ << ":" << " " << it->first << endl;
            }
        }
    }
    return 0;
}