#include<bits/stdc++.h>
using namespace std;

int KnapSack_DP(int n,int W,int *value, int *weight) {

    // Create 2D array
    vector<vector<int>> output(n,vector<int>(W+1,0));

    // Analyse Base case
    for(int i = weight[0];i<=W;i++) {
        if(output[0][i] <= W)
        output[0][i] = value[0];
        else
        output[0][i] = 0;
    }   

    // Convert recursion to iteration
    for(int i = 1;i<n;i++) {
        for(int j = 0;j<=W;j++) {

            int include = 0;

            if(weight[i] <= j)
            include = value[i] + output[i-1][j-weight[i]];

            int exclude = 0 + output[i-1][j];
            output[i][j] = max(include,exclude);
        }
    }
    return output[n-1][W];
}

int main()
{
    int n;
    cin>>n;
    int maxweight;
    cin>>maxweight;
    int *weight = new int[n];
    int *value = new int[n];
    for(int i = 0;i<n;i++) {
        cin>>value[i];
    }
    for(int i = 0;i<n;i++) {
        cin>>weight[i];
    }

    
    cout<<KnapSack_DP(n,maxweight,value,weight);
 return 0;
}