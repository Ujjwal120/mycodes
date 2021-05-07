#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define input freopen("1.txt","r",stdin);
#define output freopen("output.txt","w",stdout);
#define ll long long int
#define pb push_back
#define ppb pop_back
#define eb emplace_back
#define vi vector<int>
#define vii vector<vi>
#define vl vector<ll>
#define vll vector<vl>
#define pii pair<int, int>
#define pll pair<ll,ll>
#define mp make_pair
#define vpi vector<pii>
#define vpl vector<pll> 
#define ss second 
#define ff first

using namespace std;

const int p = 1e9 + 7;
const int maxn = 1e6;
int n, k;

std::ostream&
operator<<( std::ostream& dest, __int128_t value )
{
    std::ostream::sentry s( dest );
    if ( s ) {
        __uint128_t tmp = value < 0 ? -value : value;
        char buffer[ 128 ];
        char* d = std::end( buffer );
        do
        {
            -- d;
            *d = "0123456789"[ tmp % 10 ];
            tmp /= 10;
        } while ( tmp != 0 );
        if ( value < 0 ) {
            -- d;
            *d = '-';
        }
        int len = std::end( buffer ) - d;
        if ( dest.rdbuf()->sputn( d, len ) != len ) {
            dest.setstate( std::ios_base::badbit );
        }
    }
    return dest;
}

priority_queue<__int128_t> q;
map<__int128_t, int> m;
vector<bool> ans;

void solve() {
    int n; cin >> n;
    for(int i = 0; i < n; i++) {
        if(k == 1) m[i+1] = 1;
        else if(k == 2) m[__int128_t(i+1)*(i+1)] = 1;
        else if(k == 3) m[__int128_t(i+1)*(i+1)*(i+1)] = 1;
        else {
            __int128_t x = 1ll * (i+1) * (i+1);
            x *= x;
            m[x] = 1;
        }

    }
    while(m.size()>1) {
        auto it = prev(m.end());
        __int128_t f = it->first;
        m.erase(it);
        it = prev(m.end());
        __int128_t s = it->first;
        m.erase(it);
        m[f-s] = 1;
    } 
    cout << m.begin()->first << "\n";
    // q = priority_queue<__int128_t>();
    m.clear();
}

int main() {
    fast
    cin >> k;
    int t; cin >> t;
    while(t--) solve();
    return 0;
}