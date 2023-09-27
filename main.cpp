#include <bits/stdc++.h>

using namespace std;

vector<pair<int,pair<string,string>>>graph;
vector<pair<int,pair<string,string>>>tree;
vector<string>parent;
vector<int>Rank;
set<string>vertex;
int totalWeight;

void readInput()
{
  string a,b;
  int w;
  while(cin>>a){
        cin>>b;
        cin>>w;
        pair<string,string>temp;
        temp.first=a;
        temp.second=b;
        pair<int,pair<string,string>>temp1;
        temp1.first=w;
        temp1.second=temp;
        graph.push_back(temp1);
        vertex.insert(a);
        vertex.insert(b);
  }
}

int findIndex(string ch)
{
    int pos=0;
    set<string>::iterator it;
    for(it=vertex.begin();it!=vertex.end();it++){
        if(ch==*it){
            break;
        }
        else pos++;
    }
    return pos;
}

bool compare(const pair<int,pair<string,string>>a, const pair<int,pair<string,string>>b)
{
    return a.first<b.first;
}

void sortWeight()
{
    sort(graph.begin(),graph.end(),compare);
}

string findSet(string x)
{
    if(x!=parent[findIndex(x)]){
        parent[findIndex(x)]=findSet(parent[findIndex(x)]);
    }
    return parent[findIndex(x)];
}

void link(string u,string v)
{
    int x=findIndex(u),y=findIndex(v);
    if(Rank[x]>Rank[y]){
        parent[y]=u;
    }
    else {
        parent[x]=v;
        if(Rank[x]==Rank[y]){
            Rank[y]++;
        }
    }
}

void Union(string u,string v)
{
    link(u,v);
}

void makeSet(string x)
{
    parent.push_back(x);
    Rank.push_back(0);
}

void kruskal()
{
    set<string>::iterator it;
    for(it=vertex.begin();it!=vertex.end();it++){
        makeSet(*it);
    }
    sortWeight();
    for(int i=0;i<graph.size();i++){
        string x=graph[i].second.first;
        string y=graph[i].second.second;
        string u=findSet(x),v=findSet(y);
        if(u!=v){
            tree.push_back(graph[i]);
            Union(u,v);
        }
    }
}

int main()
{
    freopen("kruskal.txt","r",stdin);
    readInput();
    kruskal();
    totalWeight=0;
    for(int i=0;i<tree.size();i++){
        cout<<tree[i].second.first<<" "<<tree[i].second.second<<" "<<tree[i].first;
        totalWeight+=tree[i].first;
        cout<<endl;
    }
    cout<<"Total Weight: "<<totalWeight<<endl;
    //for(int i=0;i<Rank.size();i++)cout<<parent[i]<<" ";

    return 0;
}
