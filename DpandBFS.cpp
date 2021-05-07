#include<bits/stdc++.h>
using namespace std;
 
#define ll long long int
#define FIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define mod 1000000007
 
int main(){
    FIO;
    int t,n,m,k,i,j;
    string ans;
    char c;
    
    cin >> t;
    while(t--){
        cin >> n >> m;
        
        string s[n];
        
        bool valid[n][m],valid2[n][m];
        
        for(i=0;i<n;i++){
            cin >> s[i];
            for(j=0;j<m;j++){
                valid[i][j]=false;
                valid2[i][j]=false;
            }
        }
        
        valid[n-1][m-1]=true;
        for(k=n+m-3;k>=0;k--){
            for(i=max(0,k-(m-1));i<n && i<=k;i++){
                j=k-i;
                if(s[i][j]!='#' && i+1<n && valid[i+1][j])
                    valid[i][j]=true;
                else if(s[i][j]!='#' && j+1<m && valid[i][j+1])
                    valid[i][j]=true;
            }
        }
        
        valid2[0][0]=true;
        ans="";
        ans+=s[0][0];
        for(k=1;k<n+m-1;k++){
            c='z';
            for(i=max(0,k-(m-1));i<n && i<=k;i++){
                j=k-i;
                if(i>0 && valid2[i-1][j] && valid[i][j])
                    c=min(c,s[i][j]);
                else if(j>0 && valid2[i][j-1] && valid[i][j])
                    c=min(c,s[i][j]);
            }
            ans+=c;
            for(i=max(0,k-(m-1));i<n && i<=k;i++){
                j=k-i;
                if(i>0 && valid2[i-1][j] && valid[i][j] && c==s[i][j])
                    valid2[i][j]=true;
                else if(j>0 && valid2[i][j-1] && valid[i][j] && c==s[i][j])
                    valid2[i][j]=true;
            }
        }
        
        cout  << ans << "\n";
    }
    
    return 0;
}