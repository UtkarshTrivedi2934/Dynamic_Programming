#include<bits/stdc++.h>
using namespace std;

int minCount(int n) {
    if(n==0)
        return 0;
    int res = n;
    for(int i  =1;i<=n;i++) {
        int temp = i*i;
        if(temp > n)
            break;
        else {
            res = min(res,1+minCount(n-temp));
        }
    }

    return res;
}

int main()
{
int n;
cin>>n;
cout<<minCount(n);
 return 0;
}