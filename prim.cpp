#include <bits/stdc++.h>

using namespace std;
#define SIZE 100
#define INF 1000000

int w[SIZE][SIZE], d[SIZE], prv[SIZE];
bool visited[SIZE];
int tree[SIZE];
int n,m,k=0;
bool flag[SIZE];
string name[SIZE];
map<string,int>inputName;
int totalWeight=0;
int minWeight=0;

priority_queue < pair<int, int>, vector<pair<int, int>>, greater <pair<int, int>> > pq;

void readInput()
{
    cin>>n>>m;
    int num=0;
    string u,v;
    for(int i=0;i<m;i++){
        cin>>u>>v;
        if(inputName[u]==0){
            inputName[u]=num++;
            name[inputName[u]]=u;
        }
        if(inputName[v]==0){
            inputName[v]=num++;
            name[inputName[v]]=v;
        }
        cin>>w[inputName[u]][inputName[v]];
        totalWeight+=w[inputName[u]][inputName[v]];
    }
}

void initialize_single_source(int s)
{
    for (int v = 0; v < n; v++)
    {
        d[v] = INF;
        prv[v] = -1;
        visited[v]=false;
    }
    d[s] = 0;

}

void relax(int u, int v)
{
    /*if(d[v] > d[u] + w[u][v])
    {
        d[v] = d[u] + w[u][v];
        prv[v] = u;
    }*/
    if(d[v]>w[u][v]){
        d[v]=w[u][v];
        prv[v]=u;
        pq.push(pair<int,int>(d[v],v));
        //cout<<name[u]<<": "<<d[v]<<" "<<name[v]<<endl;
    }
}

void dijkstra(int s)
{
    initialize_single_source(s);
    /*for(int i=0;i<n;i++){
         pq.push(pair<int, int>(d[i],i));
    }*/
    pq.push(pair<int,int>(0,s));
    while(!pq.empty())
    {
        int u = pq.top().second;
        pq.pop();
        if(!visited[u])tree[k++]=u;
        visited[u]=true;
        int smallest=INT_MAX,vertex=-1;
        for (int v = 0; v < n; v++)
        {
            if(w[u][v] > 0 && !visited[v])
            {
                relax(u, v);
                //cout<<name[v]<<": "<<d[v]<<endl;
                if(d[v]<smallest){
                    smallest=d[v];
                    vertex=v;
                }
                //pq.push(pair<int,int>(d[v],v));
            }
        }
        //cout<<smallest<<" "<<name[vertex]<<endl;
        //if(vertex!=-1)pq.push(pair<int,int>(smallest,vertex));
    }
}

void printPath(int x){
    if(x==-1)return;
    printPath(prv[x]);
    cout<<name[x]<<" ";
}

void printGraph()
{
    int u, v;
    for (u = 0; u < n; u++ )
    {
        for(v = 0; v < n; v++)
        {
            cout << w[u][v] << " ";
        }
        cout << "\n";
    }
}

void printSpanTree()
{
    //cout<<"   Edges   "<<"Weight"<<endl;
    for(int i=0;i<k;i++){
        //if(d[i]!=0)cout<<"    "<<name[prv[tree[i]]]<<"-"<<name[tree[i]]<<"     "<<d[i]<<endl;
        minWeight+=d[tree[i]];
    }
    
}

int main()
{
    freopen("input.txt","r",stdin);
    readInput();
    //printGraph();
    dijkstra(0);
    //for(int i=0;i<5;i++)cout<<prv[i]<<" ";
    //printPath(5);
    //cout<<endl;
    printSpanTree();
    cout<<"Maximum "<<totalWeight-minWeight<<" rupee can be saved"<<endl;


    return 0;
}