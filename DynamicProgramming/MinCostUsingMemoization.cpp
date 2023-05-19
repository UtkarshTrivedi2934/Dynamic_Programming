#include<bits/stdc++.h>
using namespace std;

int minCost_Memo(int **input,int m,int n,int i,int j,int **output) {
    if(i == m-1 and j == n-1)
    return input[i][j]; 

    if(i>=m or j>=n)
    return INT_MAX;

    if(output[i][j] != -1)
        return output[i][j];

    int x = minCost_Memo(input,m,n,i,j+1,output);
    int y = minCost_Memo(input,m,n,i+1,j+1,output);   
    int z = minCost_Memo(input,m,n,i+1,j,output); 
    
    int ans = min(x,min(y,z)) + input[i][j];
    output[i][j] = ans;
    return ans;
}

int minCost_Memo(int **input,int m,int n,int i,int j) {
    int **output = new int*[m];
    for(int i = 0;i<m;i++) {
        output[i] = new int[n];
        for(int j = 0;j<n;j++) {
            output[i][j] = -1;
        }
    }
    return minCost_Memo(input,m,n,i,j,output);
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
    cout<<"MINIMUM COST TO REACH THE END IS :\t"<<minCost_Memo(input,m,n,0,0);
    return 0;
}