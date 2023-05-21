#include<iostream>
using namespace std;



int KnapSack(int n,int *weights,int *values,int w) {
    //Base case
    if(n == 0 or w == 0)
    return 0;

    if(weights[0] > w) {
        return KnapSack(n-1,weights+1,values+1,w);
    }
    ///recursion
    int a = KnapSack(n-1,weights + 1,values + 1,w-weights[0]) + values[0];
    int b = KnapSack(n-1,weights+1,values+1,w);

    return max(a,b);
}

int main()
{
    int n;
    cin>>n;
    int *weights = new int[n];
    for(int i = 0;i<n;i++) {
        cin>>weights[i];
    }

    int *values = new int[n];
    for(int i = 0;i<n;i++) {
        cin>>values[i];
    }
    int w;
    cin>>w;
    cout<<KnapSack(n,weights,values,w);
 return 0;
}