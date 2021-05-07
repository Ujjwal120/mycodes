#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

int T, N, Q;
vector<int> a;

void solve() {
    a.clear();
    int nxt = 4;
    int cnt = 0;
    while(1) {
        if(a.size() == N) {
            int x;
            for(int x : a) cout << x << " ";
            cout << endl;
            cout.flush();

            cin >> x;
            if(x == 1) break;
            else {
                exit(0);
            }
        }

        if(a.size() == 0) {
            int median;
            cout << "1 2 3" << endl;

            cout.flush();
            cin >> median;

            if(median == 1) {
                a.push_back(2); a.push_back(1); a.push_back(3);
            }
            else if(median == 2) {
                a.push_back(1); a.push_back(2); a.push_back(3);
            }
            else {
                a.push_back(2); a.push_back(3); a.push_back(1);
            }

        }
        else {
            int median;
            int l = 0, r = a.size()-1;

            while(l <= r) {

                if(l == r) {
                    a.insert(a.begin()+r, nxt++);
                    break;
                }
                else if(l+1 == r) {
                    cout << a[l] << " " << a[r] << " " << nxt << endl;
                    cout.flush();
                    cin >> median;

                    if(median == a[l]) {
                        a.insert(a.begin()+l, nxt++);
                        break;
                    }
                    else if(median == a[r]) {
                        a.insert(a.begin()+r+1, nxt++);
                        break;
                    }
                    else {
                        a.insert(a.begin()+r, nxt++);
                        break;
                    }
                }
                else {
                    int pts = r-l+1;
                    int m1 = l+pts/3, m2 = l+2*(pts/3);
                    
                    cout << a[m1] << " " << a[m2] << " " << nxt << endl;
                    cout.flush();
                    cin >> median;
                    
                    if(median == -1) {
                        exit(0);
                    }

                    if(median == a[m1]) {
                        r = m1;
                    }
                    else if(median == a[m2]) {
                        if(m2 == r) {
                            a.insert(a.begin()+r+1, nxt++);
                            break;
                        }
                        l = m2;
                    }
                    else if(median == nxt) {
                        if(m1+1 == m2) {
                            a.insert(a.begin()+m2, nxt++);
                            break;
                        }
                        l = m1+1;
                        r = m2;
                    }
                }
            }
        }
    }
}

signed main() {
    fast 
    cin >> T >> N >> Q;
    while(T--) solve();
    return 0;
}