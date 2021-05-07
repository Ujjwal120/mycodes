#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
// #define input freopen("test_output.txt","r",stdin);
// #define output freopen("pro_output.txt","w",stdout);

using namespace std;

const int maxn = 1e5+10;
int cs = 1;

bitset<maxn> bs;
vector<int> pr;

void sieve() {
    pr.push_back(2);
    bs.set();

    for(int i = 3; i <= maxn; i += 2) {    
        if(bs[i]) {
            pr.push_back(i);
            for(long long j = 1ll*i*i; j <= maxn; j += i) bs[j] = 0;
        }
    }
}

bool isPrime(int x) {
    for(int i = 0; i < pr.size(); i++) {
        if(x == pr[i]) return true;
        if(x % pr[i] == 0) return false;
    }
    return true;
}

void solve () {
    long long z; cin >> z;
    int under_root = sqrt(z);
    
    int pivot;
    bool found = false;
    int temp = under_root;

    while(!found) {
        if(isPrime(temp)) {
            found = true;
            pivot = temp;
        }
        temp--; 
    }

    int pivot2;
    found = false;
    temp = pivot+1;

    while(!found) {
        if(isPrime(temp)) {
            found = true;
            pivot2 = temp;
        }
        temp++; 
    }

    long long ans = 1ll*pivot*pivot2;

    if(ans > z) {
        found = false;
        temp = pivot-1;
        while(!found) {
            if(isPrime(temp)) {
                found = true;
                pivot2 = temp;
            }
            temp--; 
        }

        ans = 1ll*pivot*pivot2;
    }

    cout << "Case #" << cs++ << ": " << ans << "\n";
}

signed main() {
    sieve();
    fast int t;
    cin >> t;
    while(t--) solve();
    return 0;
}