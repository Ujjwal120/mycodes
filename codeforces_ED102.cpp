#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

const int maxn = 1e5+10;

int gcd(int a, int b) {
    return (a == 0) ? b : gcd(b%a, a);
}

void solve() {
    string s, t;
    cin >> s >> t;
    int ca1 = 0, cb1 = 0, ca2 = 0, cb2 = 0; 
    for(int i = 0; i < s.length(); i++) {
        if(s[i] == 'a') ca1++;
        else cb1++;
    }

    for(int i = 0; i < t.length(); i++) {
        if(t[i] == 'a') ca2++;
        else cb2++;
    }

    if(cb1 == 0 && cb2 == 0) {
        int sz = ca1*ca2;
        sz /= gcd(ca1, ca2);
        for(int i = 0; i < sz; i++) cout << "a";
        cout << "\n";
    }
    else if(ca1 == 0 && ca2 == 0) {
        int sz = cb1*cb2;
        sz /= gcd(cb1, cb2);
        for(int i = 0; i < sz; i++) cout << "b";
        cout << "\n";
    }
    else if(ca1 != 0 && ca2 != 0 && cb1 != 0 && cb2 != 0) {
        if(ca1*cb2 == ca2*cb1) {
            int x = s.length();
            int y = t.length();
            if(x > y) {
                int min_size = y;
                int i = 1;
                int smallest = min_size;
                while(min_size > 1) {                    
                    min_size = y/i;
                    if(min_size*i == y) {
                        bool change = true;
                        for(int i = 0; i < y-min_size; i++) {
                            if(t[i] != t[i+min_size]) {
                                change = false; break;
                            }
                        }
                        if(change) smallest = min_size;
                    }
                    i++;
                }

                if(x%smallest != 0) cout << "-1\n";
                else {
                    bool poss = true;
                    for(int i = 0; i < x; i++) {
                        if(s[i] != t[i%smallest]) {
                            poss = false; break;
                        }
                    }
                    if(poss) {
                        int a = y/smallest;
                        int b = x/smallest;
                        int lcm = a*b/gcd(a, b);
                        for(int i = 0; i < lcm; i++) {
                            for(int j = 0; j < smallest; j++) cout << t[j];
                        }
                        cout << "\n";
                    }
                    else cout << "-1\n";
                }
            }
            else {
                int min_size = x;
                int i = 1;
                int smallest = min_size;
                while(min_size > 1) {                    
                    min_size = x/i;
                    if(min_size*i == x) {
                        bool change = true;
                        for(int i = 0; i < x-min_size; i++) {
                            if(s[i] != s[i+min_size]) {
                                change = false; break;
                            }
                        }
                        if(change) smallest = min_size;
                    }
                    i++;
                }

                if(y%smallest != 0) cout << "-1\n";
                else {
                    bool poss = true;
                    for(int i = 0; i < y; i++) {
                        if(t[i] != s[i%smallest]) {
                            poss = false; break;
                        }
                    }
                    if(poss) {
                        int a = y/smallest;
                        int b = x/smallest;
                        int lcm = a*b/gcd(a, b);
                        for(int i = 0; i < lcm; i++) {
                            for(int j = 0; j < smallest; j++) cout << s[j];
                        }
                        cout << "\n";
                    }
                    else cout << "-1\n";
                }                
            }
        }
        else cout << "-1\n";
    }
    else cout << "-1\n";
}

signed main() {
    fast int t;
    cin >> t;
    while(t--) solve();
}