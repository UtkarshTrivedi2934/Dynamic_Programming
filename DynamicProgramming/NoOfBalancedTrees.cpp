#include<iostream>
using namespace std;

int NoOfbalanceTrees(int h) {
    if(h<=1)
    return 1;

    int x = NoOfbalanceTrees(h-1);
    int y = NoOfbalanceTrees(h-2);

    int ans = x*x + 2*x*y;
    return ans;

}

int main()
{
    int h;
    cin>>h;
    cout<<NoOfbalanceTrees(h);
 return 0;
}