#include <bits/stdc++.h>

using namespace std;

struct point{
    int val;
    int direc;
}c[100][100];

void printFunc(int i,int j,string x,string y){
    if(i==0 && j==0)return;
    if(c[i][j].direc==1){
            printFunc(i-1,j-1,x,y);
    }
    else if(c[i][j].direc==2){
            printFunc(i-1,j-1,x,y);
            cout<<"Substitute "<<x[i-1]<<" by "<<y[j-1]<<endl;
    }
    else if(c[i][j].direc==3){
            printFunc(i-1,j,x,y);
            cout<<"Delete "<<x[i-1]<<" from "<<x<<endl;
    }
    else if(c[i][j].direc==4){
            printFunc(i,j-1,x,y);
            cout<<"Insert: "<<y[j-1]<<endl;
    }

}

void EditEd(string first,string second,int m,int n){
    int i,j;
    c[0][0].val=0;
    c[0][0].direc=0;
    for(i=1;i<n;i++){
        c[0][i].val=i;
        c[0][i].direc=4;
    }
    for(i=1;i<m;i++){
        c[i][0].val=i;
        c[i][0].direc=3;
    }
    for(i=1;i<m;i++){
        for(j=1;j<n;j++){
            if(first[i-1]==second[j-1]){
                c[i][j].val=c[i-1][j-1].val;
                c[i][j].direc=1;
            }
            else {
                int tempMin,symbol;
                if(c[i-1][j-1].val<c[i-1][j].val){
                    tempMin=c[i-1][j-1].val;
                    symbol=2;
                }
                else {
                    tempMin=c[i-1][j].val;
                    symbol=3;
                }
                if(c[i][j-1].val<tempMin){
                    tempMin=c[i][j-1].val;
                    symbol=4;
                }
                c[i][j].val=tempMin + 1;
                c[i][j].direc=symbol;
            }
        }
    }
    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            cout<<c[i][j].val<<" ";
        }
        cout<<endl;
    }
    printFunc(m-1,n-1,first,second);

}

int main()
{
    string first,second;
    int size1,size2;
    cin>>size1;
    cin>>first;
    cin>>size2;
    cin>>second;
    EditEd(first,second,size1,size2);

    return 0;
}
