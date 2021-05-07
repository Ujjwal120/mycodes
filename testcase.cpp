#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define output freopen("test_output.txt","w",stdout);

using namespace std;

int cs = 0;
int arr[50];

void generate() {
    for(int i = 0; i < 50; i++) arr[i] = i+1;
    unsigned seed = 0;
    random_shuffle(arr, arr + 50);
    for(int i = 0; i < 50; i++) cout << arr[i] << ", ";
    cout << "\n";
}

signed main() {
    fast int t;
    output
    cin >> t;
    cout << t << "\n";
    while(t--) generate();
    return 0;
}