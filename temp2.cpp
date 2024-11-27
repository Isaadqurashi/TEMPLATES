#include <bits/stdc++.h>
#define fli(i,fc,n) for(int i=fc;i<n;i++)
#define ll long long
#define pb push_back
#define all(v) v.begin(), v.end()
#define nl "\n"
using namespace std;

void bfs(int s, vector<list<int>> &adj, vector<int> &vis) {
    queue<int> q;
    q.push(s);
    vis[s] = 1;
    while (!q.empty()) {
        int n = q.front();
        q.pop();
        cout << n << " ";
        for (auto v : adj[n]) {
            if (!vis[v]) {
                vis[v] = 1;
                q.push(v);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<list<int>> adj(n + 1);
    vector<int> vis(n + 1, 0);
    fli(i, 0, m) {
        int u, v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    bfs(1, adj, vis);
}


// DFS
//   =========================================================================
//   =========================================================================
//   =========================================================================
  

#include <bits/stdc++.h>
#define fli(i,fc,n) for(int i=fc;i<n;i++)
#define ll long long
#define pb push_back
#define all(v) v.begin(), v.end()
#define nl "\n"
using namespace std;

void dfs(int n, vector<list<int>> &adj, vector<int> &vis) {
    vis[n] = 1;
    cout << n << " ";
    for (auto v : adj[n]) {
        if (!vis[v]) {
            dfs(v, adj, vis);
        }
    }
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<list<int>> adj(n + 1);
    vector<int> vis(n + 1, 0);
    fli(i, 0, m) {
        int u, v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    dfs(1, adj, vis);
}
