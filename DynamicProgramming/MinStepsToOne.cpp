#include<bits/stdc++.h>
using namespace std;

int minSteps(int n) {
    int x;
    int y = INT_MAX;
    int z = INT_MAX;

    if(n<=1)
    return 0;

    x = minSteps(n-1);
    if(n%2 == 0)
    y = minSteps(n/2);
    if(n%3 == 0)
    z = minSteps(n/3);
    int ans = min(x,min(y,z)) + 1;
    return ans;
}

int main()
{
    int n;
    cin>>n;
    cout<<minSteps(n);
 return 0;
}