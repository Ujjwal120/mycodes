#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

void solve() {
    int a, b;    // a is size of 1st array b is the size of 2nd array
    cin >> a >> b;
    vector<int> A(a), B(b);

    // 0-based indexing for arrays
    for(int i = 0; i < a; i++) cin >> A[i];    // input 1st array
    for(int i = 0; i < b; i++) cin >> B[i];    // input 2nd array

    //  --> Complexity - O((a+b)/2) or O(n)
    int tot_elements = a+b;
    int count_till;
    if(tot_elements&1) {
        count_till = tot_elements/2+1;    //  odd nummber of elements
    }
    else {
        count_till = tot_elements/2;    // even number of elements
    }

    int mid, a_ind = 0, b_ind = 0;
    while(count_till--) {
        if(a_ind < A.size() && b_ind < B.size()) {
            if(A[a_ind] < B[b_ind]) {
                mid = A[a_ind];
                a_ind++;
            }
            else {
                mid = B[b_ind];
                b_ind++;
            }
        }
        else if(a_ind < A.size()) {
            mid = A[a_ind];
            a_ind++;
        }
        else {
            mid = B[b_ind];
            b_ind++;
        }
    }

    cout << "Middle element is : " << mid << "\n";
}

signed main() {
    fast 
    int t = 1;
    while(t--) solve();
    return 0;
}