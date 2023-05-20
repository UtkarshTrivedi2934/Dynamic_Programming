#include<iostream>
using namespace std;

int EditDistMemo(string s,string t,int **output) {
    int m = s.size();
    int n = t.size();

    //Base case
    if(m == 0 or n == 0)
    return max(m,n);

    int ans;
    // Step-2.Check if answer already exists
    if(output[m][n] != -1) 
    return output[m][n];

    //Recursion
    if(s[0] == t[0])
    return EditDistMemo(s.substr(1),t.substr(1),output);

    else {
        //Insert
        int a = EditDistMemo(s.substr(1),t,output) + 1;
        //Delete
        int b = EditDistMemo(s,t.substr(1),output) + 1;
        //Update
        int c = EditDistMemo(s.substr(1),t.substr(1),output) + 1;
        //Finding minimum distance 
        ans = min(a,min(b,c));
    }
    // Step-3.Saving answer in array
    output[m][n] = ans;

    return ans;
}


int EditDistMemo(string s,string t) {
    int m = s.size();
    int n = t.size();
    // Step-1.Create array
    int **output = new int*[m+1];
    for(int i = 0;i<=n;i++) {
        output[i] = new int[n+1];
        for(int j = 0;j<=n;j++) {
            output[i][j] = -1;
        } 
    }
    return EditDistMemo(s,t,output);
}

int main()
{
    string s,t;
    cin>>s>>t;
    cout<<EditDistMemo(s,t);
 return 0;
}