#include<bits/stdc++.h>
using namespace std;

int main()
{
    string pattern,text;
    cin>>text>>pattern;

    int n=pattern.size();
    int m=text.size();
    int prefix[n];
    prefix[0]=0;
    int i=1,j=0;
    while(i<n)
    {
        while(j && pattern[i]!=pattern[j]){
            j=prefix[j-1];
        }
        if(pattern[j]==pattern[i])j++;
        prefix[i]=j;
        i++;
    }
    j=0;
    for(i=0;i<m;i++)
    {
        while(j && pattern[j]!=text[i]){
            j=prefix[j-1];
        }
        if(text[i]==pattern[j])j++;
        if(j==n){
            cout<<"Pattern occurs with shift "<<i-n+1<<'\n';
            j=prefix[j-1];
        }
       // cout<<j<<" ";
    }

    //bacbabababacaca ababaca


    return 0;
}