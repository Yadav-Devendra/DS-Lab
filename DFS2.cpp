#include<bits/stdc++.h>
using namespace std;
const int N = 5;
bool vis[N];
vector<int> adj[N];

void DFS(int node){
    vis[node] = 1;
    cout<<node<<endl;
    vector<int> :: iterator it;
    for (it = adj[node].begin(); it != adj[node].end(); it++)
    {
        if (vis[*it])
        {
            
        }
        else{
            DFS(*it);
        }  
    }
    cout<<"Function called"<<endl;
}

int main(){
    for (int i = 0; i < N; i++)
    {
        vis[i] = 0;
    }
    int nodes, edges, a, b, v;
    cout<<"Enter number of nodes: ";
    cin>>nodes;
    cout<<"Enter number of edges: ";
    cin>>edges;
    for (int i = 0; i < edges; i++)
    {
        cout<<"Enter from: "<<endl;
        cin>>a;
        cout<<"From to: "<<endl;
        cin>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    cout<<"Enter vertex to continue: ";
    cin>>v;
    DFS(v);
    return 0;
}