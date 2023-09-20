#include <bits/stdc++.h>

using namespace std;
#define inf 1000000
#define Max 1000

int w[Max][Max],p[Max][Max],d[Max][Max],n;
int pos=0;
string name[Max];

void initializeWeight()
{
    for(int i=0;i<Max;i++){
        for(int j=0;j<Max;j++){
            if(i==j)w[i][j]=0;
            else w[i][j]=inf;
        }
    }
}

void readInput()
{
    cin>>n;
    int i,u,v;
    string temp1,temp2;
    for(i=0;i<n;i++){
        cin>>temp1;
        for(u=0;u<pos;u++){
            if(name[u]==temp1)break;
        }
        if(u==pos){
            name[pos++]=temp1;
        }
        cin>>temp2;
        for(v=0;v<pos;v++){
            if(name[v]==temp2)break;
        }
        if(v==pos){
            name[pos++]=temp2;
        }
        cin>>w[u][v];
    }
}

void floydWarshall()
{
    int i,j,k;
    for(i=0;i<pos;i++){
        for(j=0;j<pos;j++){
            if(i==j || w[i][j]==inf)p[i][j]=-1;
            else p[i][j]=i;
        }
    }

    for(i=0;i<pos;i++){
        for(j=0;j<pos;j++){
            d[i][j]=w[i][j];
        }
    }

    for(k=0;k<pos;k++){
        for(i=0;i<pos;i++){
            for(j=0;j<pos;j++){
                if(d[i][k]+d[k][j]<d[i][j]){
                    d[i][j]=d[i][k]+d[k][j];
                    p[i][j]=p[k][j];
                }
            }
        }
    }
}

void printPath(int s,int t)
{
    if(p[s][t]==-1){
        cout<<"No path"<<endl;
        return;
    }
    else if(p[s][t]==s){
        cout<<name[s]<<" ";
    }
    else {
        printPath(s,p[s][t]);
        printPath(p[s][t],t);
    }
}

int main()
{
    freopen("fw.txt","r",stdin);
    initializeWeight();
    readInput();
    floydWarshall();
    printPath(0,3);
    cout<<name[3]<<endl;
    /*cout<<endl;
    for(int i=0;i<pos;i++){
        for(int j=0;j<pos;j++){
            cout<<p[i][j]<<" ";
        }
        cout<<endl;
    }*/
    for(int i=0;i<pos;i++)cout<<name[i]<<" ";

    return 0;
}
