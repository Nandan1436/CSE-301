#include <bits/stdc++.h>
using namespace std;

#define inf 1000000

int d[1000],prv[1000],w[1000][1000];
string name[1000];
int n=0;
vector<pair<int,int>> edge;

void initialize(int s)
{
    int i;
    for(i=0;i<n;i++){
        d[i]=inf;
        prv[i]=-1;
    }
    d[s]=0;
}

void relax(int u,int v)
{
    if(d[v]>d[u]+w[u][v]){
        d[v]=d[u]+w[u][v];
        prv[v]=u;
    }
}

bool BellmanFord(int s)
{
    initialize(s);
    for(int i=0;i<n-1;i++){
        for(int j=0;j<edge.size();j++){
            relax(edge[j].first,edge[j].second);
        }
    }
    int u,v;
    for(int i=0;i<edge.size();i++){
        u=edge[i].first,v=edge[i].second;
        if(d[v]>d[u]+w[u][v])return false;
    }
    return true;
}

void readInput()
{
    int u,v;
    string s;
    while(cin>>s){
        //if(s=="END")break;
        for(u=0;u<n;u++){
            if(name[u]==s)break;
        }
        if(u==n){
            name[n++]=s;
        }
        cin>>s;
        for(v=0;v<n;v++){
            if(name[v]==s)break;
        }
        if(v==n){
            name[n++]=s;
        }
        cin>>w[u][v];
        edge.push_back(make_pair(u,v));
    }
}

void printPath(int x)
{
    if(x==-1)return;
    printPath(prv[x]);
    cout<<name[x]<<" ";
}

void print()
{
    for(int i=0;i<n;i++){
        cout<<name[i]<<" "<<prv[i]<<endl;
    }
}

int main()
{
    freopen("input.txt","r",stdin);
    readInput();
    bool check=BellmanFord(0);
    if(!check)cout<<"Negative cycle exists!"<<endl;
    else printPath(3);
    //print();

    return 0;
}