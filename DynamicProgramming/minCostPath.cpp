#include<bits/stdc++.h>
using namespace std;

int minCost(int **arr,int m,int n,int i,int j) {
    if(i == m-1 and j == n-1)
    return arr[i][j];

    if(i>=m or j>=n)
    return INT_MAX;
    int x = minCost(arr,m,n,i,j+1);
    int y = minCost(arr,m,n,i+1,j+1);   
    int z = minCost(arr,m,n,i+1,j);
    
    int ans = min(x,min(y,z)) + arr[i][j];
    return ans;
}

int minCost(int **arr,int m,int n) {
    return minCost(arr,m,n,0,0);
}
int main()
{
    int m,n;
    cout<<"MINIMUM COST PATH\nENTER DIMENSIONS OF ARRAY:\t";
    cin>>m>>n;
    int **input=new int*[m];//dynamic allocation
    cout<<"ENTER ARRAY ELEMENTS:\n";
    for(int i=0;i<m;i++)
    {
        input[i]=new int[n];
        for(int j=0;j<n;j++){
            cin>>input[i][j];
        }
    }
    cout<<"MINIMUM COST TO REACH THE END IS :\t"<<minCost(input,m,n);
    return 0;
}