#include <bits/stdc++.h>

using namespace std;

vector<pair<int,pair<string,string>>>graph;
vector<pair<int,pair<string,string>>>tree;
map<string,string>parent;
map<string,int>ranks;
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
        parent.insert({a,""});
        ranks.insert({b,0});
  }
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
    if(x==parent[x]){
        return x;
    }
    return parent[x]=findSet(parent[x]);

}

void Union(string u,string v)
{
    u=findSet(u);
    v=findSet(v);
    if(u!=v){
        if(ranks[u]<ranks[v]){
            swap(u,v);
        }
        parent[v]=u;
        ranks[u]+=ranks[v];
    }

}

void makeSet(string x)
{
    parent[x]=x;
    ranks[x]=1;
}

void kruskal()
{
    map<string,string>::iterator it;
    for(it=parent.begin();it!=parent.end();it++){
        makeSet(it->first);
    }
    sortWeight();
    for(int i=0;i<graph.size();i++){
        string x=graph[i].second.first;
        string y=graph[i].second.second;
        string u=findSet(x),v=findSet(y);
        if(u!=v){
            tree.push_back(graph[i]);
            Union(x,y);
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
    for(auto i=parent.begin();i!=parent.end();i++){
        cout<<i->second<<" ";
    }
    cout<<endl;
    return 0;
}
