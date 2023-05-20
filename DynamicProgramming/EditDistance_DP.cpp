#include<iostream>
using namespace std;

int EditDistance_DP(string s,string t) {
    int m = s.size();
    int n = t.size();

    int **output = new int*[m+1];
    for(int i = 0;i<=m;i++) {
        output[i] = new int[n+1];
    }

    //initialize first row
    for(int j = 0;j<=n;j++) {
        output[0][j] = j;
    }

    //initialize first column
    for(int i = 0;i<=m;i++) {
        output[i][0] = i;
    }

    //remaining cells
    for(int i = 1;i<=m;i++) {
        for(int j = 1;j<=n;j++) {
            if(s[m-i] == t[n-j])
            output[i][j] = output[i-1][j-1];
            else {
                output[i][j] = min(output[i-1][j],min(output[i][j-1],output[i-1][j-1])) + 1;
            }
        }
    }
    return output[m][n];
}

int main()
{
    string s,t;
    cin>>s>>t;
    cout<<EditDistance_DP(s,t);
 return 0;
}