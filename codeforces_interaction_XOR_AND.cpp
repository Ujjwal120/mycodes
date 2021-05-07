#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

const int maxn = 1e5+1;
int a[maxn];
vector<int> present[maxn];

int queries(string s, int x, int y) {
    cout << s << " " << x << " " << y << endl;
    cout.flush();
    int z; cin >> z;
    assert(z != -1);
    return z;
}
 
void solve() {
    int n; cin >> n;
    for(int i = 2; i <= n; i++) {
        a[i] = queries("XOR", 1, i);
        present[a[i]].push_back(i); 
    }

    int same = -1;
    int i1 = 1, i2 = -1, i3 = -1;
    for(int i = 0; i < n; i++) {
        if(present[i].size() > 1) {
            i2 = present[i][0]; i3 = present[i][1];
            same = i;
            break;
        }
    }

    if(same == -1) {
        for(int i = 2; i <= 3; i++) {
            for(int j = i+1; j <= n; j++) {
                if((a[i]^a[j]) == n-1) {
                    i2 = i; i3 = j;
                }
            }
        }

        int xor_i1_i2 = a[i2], and_i1_i2 = queries("AND", i1, i2);
        int xor_i2_i3 = a[i2] ^ a[i3]; int and_i2_i3 = 0;
        int xor_i1_i3 = a[i3], and_i1_i3 = queries("AND", i1, i3);

        int x = xor_i1_i2 + 2 * and_i1_i2;
        int y = xor_i2_i3 + 2 * and_i2_i3;
        int z = xor_i1_i3 + 2 * and_i1_i3;

        a[i1] = (z - y + x) / 2;
    }
    else {
        int and_i2_i3 = queries("AND", i2, i3);
        a[1] = a[i2] ^ and_i2_i3;
    }

    for(int i = 2; i <= n; i++) a[i] ^= a[1];

    cout << "! ";
    for(int i = 1; i <= n; i++) cout << a[i] << " ";
    cout << endl;
    cout.flush();
}

signed main() {
    fast int t = 1; 
    // cin >> t; 
    while(t--) solve();
    return 0;
}