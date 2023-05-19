#include<bits/stdc++.h>
using namespace std;

int NoOfbalncedtrees(int h) {
    long long int dp[h+1];
    int mod = pow(10,9) + 7;
    dp[0] = 1;
    dp[1] = 1;
    for(int i = 2;i<=h;i++) {
        dp[i] = (dp[i-1]%mod)*(dp[i-1]%mod) + (dp[i-1]%mod)*2*(dp[i-2]%mod); 
    }

    return dp[h];
}

int main()
{
    int h;
    cin>>h;
    cout<<NoOfbalncedtrees(h);
 return 0;
}