#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

string s[51];
int cs = 1;

string check(string &s, string &t) {
    int star1 = 0, star2 = 0;
    string cl1 = "", cl2 = "";
    for(int i = 0; i < s.length(); i++) {
        star1 += (s[i] == '*');
        if(s[i] != '*') cl1 += s[i];
    }
    for(int i = 0; i < t.length(); i++) {
        star2 += (t[i] == '*');
        if(t[i] != '*') cl2 += t[i];
    }

    if(star1 == 0 || star2 == 0) {
        if(cl1 == cl2) return cl1;
        else return "-";
    }
    return "";
}

string merge(string &a, string &b) {
    int n = a.length(), m = b.length();
    int i = 0, j = 0;
    bool k = 0, l = 0;
    string prefix= "", suffix = ""; 
    int s1 = -1, s2 = -1, e1 = -1, e2 = -1;
    
    while(i < n && j < m) {
        if(a[i] == '*') {
            k = 1;
            if(s1 == -1) s1 = i;
            if(l == 1) {
                prefix += '*';
                break;
            }
            if(b[j] != '*') {
                prefix += b[j];
                j++;
                continue;
            } 
            else {
                s2 = j;
                prefix += '*';
                break;
            }
        }

        if(b[j] == '*') {
            l = 1;
            if(s2 == -1) s2 = j;
            if(k == 1) {
                prefix += '*';
                break;
            }
            if(a[i] != '*') {
                prefix += a[i];
                i++;
                continue;
            }
            else {
                s1 = i;
                prefix += '*';
                break;
            }
        }

        if(a[i] == b[j]) {
            prefix += a[i];
            i++; j++;
        }
        else return "";
    }

    i = n-1, j = m-1;
    k = 0, l = 0;
    while(i >= 0 && j >= 0) {
        if(a[i] == '*') {
            k = 1;
            if(e1 == -1) e1 = i;

            if(l == 1) {
                suffix = '*'+suffix;
                break;
            }

            if(b[j] != '*') {
                suffix = b[j]+suffix;
                j--;
                continue;
            } 
            else {
                e2 = j;
                suffix = '*'+suffix;
                break;
            }
        }

        if(b[j] == '*') {
            l = 1;
            if(e2 == -1) e2 = j;

            if(k == 1) {
                suffix = '*'+suffix;
                break;
            }
            if(a[i] != '*') {
                suffix = a[i]+suffix;
                i--;
                continue;
            }
            else {
                e1 = i;
                suffix = '*'+suffix;
                break;
            }
        }

        if(a[i] == b[j]) {
            suffix = a[i]+suffix;
            i--; j--;
        }
        else return "";
    }

    if(prefix.back() != '*') return "";


    return prefix+((s1+1 <= e1-1) ? a.substr(s1+1, e1-1) : "")+((s2+1 <= e2-1) ? b.substr(s2+1, e2) : "") +suffix;
}


void solve() {
    int n; cin >> n;
    for(int i = 0; i < n; i++) cin >> s[i];


    int sz = n;

    while(sz > 1) {
        int ind = 0;
        for(int i = 0; i < sz; i += 2) {
            if(i+1 == sz) {
                s[ind] = s[i];
                break;
            }
            string pre = check(s[i], s[i+1]);
            if(pre == "-") {
                cout << "Case #" << cs++ << ": " << "*\n";
                return;
            }
            else if(pre == "") {
                string ans = merge(s[i], s[i+1]);
                if(ans.length() == 0) {
                    cout << "Case #" << cs++ << ": " << "*\n";
                    return;
                }
                else s[ind] = ans;
            }
            else s[ind] = pre;
            ind++; 
        }

        sz = sz/2 + (sz&1);
    }

    cout << "Case #" << cs++ << ": " ;
    for(int i = 0; i < s[0].length(); i++) {
        if(s[0][i] != '*') cout << s[0][i];
    }
    cout << "\n";
}

signed main() {
    fast int t;
    cin >> t;
    while(t--) solve();
    return 0;
}