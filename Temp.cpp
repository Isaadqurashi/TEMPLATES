#include <bits/stdc++.h>
using namespace std;

// Node structure for the adjacency list and custom queue
struct Node {
    int val;
    Node* next;
    Node(int x) : val(x), next(nullptr) {}
};

// Custom Queue implementation using linked list
struct Queue {
    Node* front;
    Node* rear;

    Queue() : front(nullptr), rear(nullptr) {}

    void push(int x) {
        Node* n = new Node(x);
        if (!front) {
            front = rear = n;
        } else {
            rear->next = n;
            rear = n;
        }
    }

    int pop() {
        if (!front) return -1;
        int x = front->val;
        Node* temp = front;
        front = front->next;
        delete temp;
        if (!front) rear = nullptr;
        return x;
    }

    bool empty() {
        return front == nullptr;
    }
};

// Graph structure using adjacency list with linked list
struct Graph {
    vector<Node*> adj;  // Array of adjacency lists

    Graph(int n) {
        adj.resize(n + 1, nullptr);
    }

    void addEdge(int u, int v) {
        Node* n1 = new Node(v);
        n1->next = adj[u];
        adj[u] = n1;

        Node* n2 = new Node(u);
        n2->next = adj[v];
        adj[v] = n2;  // For undirected graph
    }
};

// BFS using custom queue
void bfs(Node* adj[], int n, int s, vector<int>& vis) {
    Queue q;
    q.push(s);
    vis[s] = 1;
    while (!q.empty()) {
        int u = q.pop();
        cout << u << " ";
        Node* cur = adj[u];
        while (cur) {
            if (!vis[cur->val]) {
                vis[cur->val] = 1;
                q.push(cur->val);
            }
            cur = cur->next;
        }
    }
}

// DFS using recursion
void dfs(Node* adj[], int u, vector<int>& vis) {
    vis[u] = 1;
    cout << u << " ";
    Node* cur = adj[u];
    while (cur) {
        if (!vis[cur->val]) {
            dfs(adj, cur->val, vis);
        }
        cur = cur->next;
    }
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int n, m;
    cin >> n >> m;

    Graph g(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        g.addEdge(u, v);
    }

    vector<int> vis(n + 1, 0);
    cout << "BFS: ";
    bfs(g.adj.data(), n, 1, vis);
    cout << "\n";

    fill(vis.begin(), vis.end(), 0);
    cout << "DFS: ";
    dfs(g.adj.data(), 1, vis);
}
