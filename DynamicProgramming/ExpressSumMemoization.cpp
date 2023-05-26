#include <bits/stdc++.h>
using namespace std;


class Solution{
    public:
    int mod = 1e9 + 7;
    int numOfWays(int n, int x,int temp,vector<vector<int>> &output) {
        if(n == 0)
        return 1;
        
        if(n < 0 or temp > n)
        return 0;
        //Check if answer exist in array
        if(output[n][temp] != -1)
        return output[n][temp] % mod;
        else {
            int a = numOfWays(n - pow(temp,x),x,temp+1,output);
            int b = numOfWays(n,x,temp+1,output);
            output[n][temp] = a+b;
        }
        return output[n][temp]%mod;
    }
    int numOfWays(int n, int x)
    {
        // create an output array
        vector<vector<int>> output(n+1,vector<int>(n+1,-1));
        return numOfWays(n,x,1,output);
        
    }
};

int main() {
    Solution ob;
    cout<<ob.numOfWays(100, 2);
}