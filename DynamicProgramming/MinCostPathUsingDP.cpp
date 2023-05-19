#include <stdio.h>
#include<iostream>
using namespace std;

/*input is the input array 
  output is the array to store output of unique iterations
  m,n dimensions of the array
*/

int mincostpath(int **input,int m,int n)
{
    int **output=new int*[m];
    for(int i=0;i<m;i++)
    {
        output[i]=new int[n];
    }
    //fill the last cell i.e destination
    output[m-1][n-1]=input[m-1][n-1];
    
    //fill last row from right to left
    for(int j=n-2;j>=0;j--)
    {
        output[m-1][j]=output[m-1][j+1]+input[m-1][j];
    }
    //fill last column from bottom to top
    for(int i=m-2;i>=0;i--)
    {
        output[i][n-1]=output[i+1][n-1]+input[i][n-1];
    }
    
    //fill remainig cells
    for(int i=m-2;i>=0;i--)
    {
        for(int j=n-2;j>=0;j--){
            output[i][j]=min(output[i][j+1],min(output[i+1][j+1],output[i+1][j]))+input[i][j];
        }
    }
    return output[0][0];
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
    cout<<"MINIMUM COST TO REACH THE END IS :\t"<<mincostpath(input,m,n);
    return 0;
}