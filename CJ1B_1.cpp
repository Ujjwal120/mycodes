const int maxn = 1e5+10;
int ten_power_mod[maxn];
int p = 1e9+7;

inline int mulmod(int a,int b) { 
    int x= a*b;
    if(x>=p) return x%p; return x;
}

inline int addmod(int a,int b){ return (a+b>=p?a+b-p:a+b); }

void solve () {
    ten_power_mod[0] = 1;

    for(int i = 1; i < string.length(); i++) {
        ten_power_mod[i] = mulmod(ten_power_mod[i-1], 10);
    }
}