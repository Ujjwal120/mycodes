#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define output freopen("match_output.txt","w",stdout);

using namespace std;

void compareFiles(FILE *a, FILE *b) {
    char ch1 = getc(a);
    char ch2 = getc(b);
  
    int error = 0, pos = 0, line = 1;
  
    while (ch1 != EOF && ch2 != EOF) {
        pos++;
        if (ch1 == '\n' && ch2 == '\n') {
            line++;
            pos = 0;
        }

        if (ch1 != ch2 || ch1 == '\n' || ch2 == '\n') {
            error++;
            printf("Line Number : %d \tError Position : %d \n", line, pos);
            return;
        }
  
        ch1 = getc(a);
        ch2 = getc(b);
    }
    
    if(ch1 != EOF || ch2 != EOF) printf("Their Ending don't match either\n");
}

signed main() {
    output
    FILE *a = fopen("pro_output.txt", "r");
    FILE *b = fopen("brute_output.txt", "r");

    if (a == NULL || b == NULL){
       printf("Error : Files not open");
       exit(0);
    }

    compareFiles(a, b);

    fclose(a);
    fclose(b);

    return 0;
}
