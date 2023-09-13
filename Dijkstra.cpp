#include <bits/stdc++.h>

using namespace std;
#define SIZE 100
#define INFINITY 1000000

int w[SIZE][SIZE], d[SIZE], prv[SIZE];
int n = 0;
bool flag[SIZE];
string name[SIZE];

priority_queue < pair<int, int>, vector<pair<int, int>>, greater <pair<int, int>> > pq;

void initialize_single_source(int s)
{
    for (int v = 0; v < n; v++)
    {
        d[v] = INFINITY;
        prv[v] = -1;
    }
    d[s] = 0;

}

void relax(int u, int v)
{
    if(d[v] > d[u] + w[u][v])
    {
        d[v] = d[u] + w[u][v];
        prv[v] = u;
    }
}

void dijkstra(int s)
{
    initialize_single_source(s);
    for(int i=0;i<n;i++){
         pq.push(pair<int, int>(d[i],i));
    }

    while(!pq.empty())
    {
        int u = pq.top().second;
        pq.pop();

        for (int v = 0; v < n; v++)
        {
            if(w[u][v] > 0)
            {
                relax(u, v);

            }
        }
    }
}

void printPath(int x){
    if(x==-1)return;
    printPath(prv[x]);
    cout<<name[x]<<" ";
}

void readInput()
{
    int u, v;
    string s;
    while (cin>>s)
    {
        if(s == "END")
            break;

        for(u = 0; u < n; u++)
        {
            if(name[u] == s)
                break;
        }
        if (u == n)
        {
            name[n] = s;
            n++;
        }

        cin >> s;
        for(v = 0; v < n; v++)
        {
            if(name[v] == s)
                break;
        }
        if (v == n)
        {
            name[n] = s;
            n++;
        }

        cin >> w[u][v];

    }
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
int main()
{
    freopen("input.txt","r",stdin);
    readInput();
    printGraph();
    dijkstra(0);
    printPath(2);
    return 0;
}
