#include<iostream>
using namespace std;

int KnapSack(int n,int *weight,int *value,int maxweight,int **output) {
    //Base case
    if(n == 0 or maxweight == 0)
    return 0;

    int ans;
    // 2.Check if answer exists
    if(output[n][maxweight] != -1)
    return output[n][maxweight];

    //Recursion
    if(weight[0] > maxweight) {
        output[n][maxweight] = KnapSack(n-1,weight+1,value + 1,maxweight,output);
        return KnapSack(n-1,weight+1,value + 1,maxweight,output);
    }
    

    else {
        int x = KnapSack(n-1,weight+1,value+1,maxweight - weight[0],output) + value[0];
        int y = KnapSack(n-1,weight+1,value+1,maxweight,output);
        ans = max(x,y);
    }
    // 3. Save answer
    output[n][maxweight] = ans;
    return ans;

}

int KnapSack(int n,int *weight,int *value,int maxweight) {
    int **output = new int*[n+1];
    // 1.Create output array
    for(int i = 0;i<=n;i++) {
        output[i] = new int[maxweight+1];
            for(int j = 0;j<=maxweight;j++)  {
                output[i][j] = -1;
            }
    }
    return KnapSack(n,weight,value,maxweight,output);
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
    
    
    cout<<KnapSack(n,weight,value,maxweight);
    return 0;
}