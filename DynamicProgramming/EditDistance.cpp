#include<iostream>
using namespace std;

int EditDist(string s,string t) {
    //Base case
    if(s.size() == 0 or t.size() == 0)
    return max(s.size(),t.size());

    int count = 0;

    //Recursion
    if(s[0] == t[0])
    return EditDist(s.substr(1),t.substr(1));

    else {
        int a = EditDist(s.substr(1),t) + 1;
        int b = EditDist(s,t.substr(1)) + 1;
        int c = EditDist(s.substr(1),t.substr(1)) + 1;
        count = min(a,min(b,c));
    }
    return count;
}

int main()
{
    string s,t;
    cin>>s>>t;
    cout<<EditDist(s,t);
 return 0;
}