#include <bits/stdc++.h>
using namespace std;

    int numOfWays(int n,int temp,int x) {
        int ans;
        if(n == 0)
        return 1;
        if(n<0 or temp > n)
        return 0;
        else {
            int a =numOfWays(n-pow(temp,x),temp+1,x);
            int b =numOfWays(n,temp+1,x);
            ans = a+b;
        }
        return ans;
    }
    int numOfWays(int n, int x)
    {
        // code here

        return numOfWays(n,1,x); 
    }

int main() {
    cout<<numOfWays(100, 2);
}