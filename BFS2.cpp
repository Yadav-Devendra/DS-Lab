#include <iostream>
#include <queue>
#include <vector>
using namespace std;

const int N = 5;
bool vis[N];
vector<int> adj[N];

int main()
{
    for (int i = 0; i < N; i++)
    {
        vis[i] = 0;
    }
    int nodes, edges, a, b, v;
    cout << "Enter number of nodes: ";
    cin >> nodes;
    cout << "Enter number of edges: ";
    cin >> edges;
    for (int i = 0; i < edges; i++)
    {
        cout << "Enter from" << endl;
        cin >> a;
        cout << "Enter To" << endl;
        cin >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    queue<int> q;
    cout << "Enter vertex to start traversing: ";
    cin >> v;
    q.push(v);
    vis[v] = true;
    // cout<<"Visited queue"<<endl;
    // for (int i = 0; i < N; i++)
    // {
    //     cout<<vis[i]<<endl;
    // }
    // cout<<"Print queue"<<endl;
    // while (!q.empty())
    // {
    //     cout<<q.front();
    //     q.pop();
    // }
    // cout<<"\nadj list"<<endl;
    // for (int i = 0; i < N; i++)
    // {

    //     cout << "Elements at index "
    //          << i << ": ";
    //     for (auto it = adj[i].begin();
    //          it != adj[i].end(); it++)
    //     {
    //         cout << *it << ' ';
    //     }
    //     cout << endl;
    // }
    // int number = 0;
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        cout << node << endl;
        vector<int>::iterator it;
        for (it = adj[node].begin(); it != adj[node].end(); it++)
        {
            if (!vis[*it])
            {
                vis[*it] = true;
                q.push(*it);
            }
        }
    }
    return 0;
}