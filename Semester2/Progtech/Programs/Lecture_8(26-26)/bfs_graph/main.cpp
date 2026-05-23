#include <iostream>
#include <list>
#include <vector>
#include <queue>
using namespace std;

class Graph {
public:
    Graph(int n) : numVertices(n) {
        adjList = new list<int>[n];
    };

    void addEdge(int u, int v) {
        adjList[u].push_back(v);
    };

    bool hasEdge(int u, int v) const {
        for(int i : adjList[u])
            if (i == v) return true;
        return false;
    };
    
    int vertices() const {
        return numVertices;
    };

    const list<int>& edges(int u) const {
        return adjList[u];
    };
private:
    int numVertices;
    list<int>* adjList;
};

enum state{ UNVISITED, VISITED, EXPLORED };

void bfs_help(int u, const Graph& g, vector<int>& p, vector<state>& status) {
    queue<int> Q;
    status[u] = VISITED;
    Q.push(u);

    while (!Q.empty()) {
        int u = Q.front();
        Q.pop();
       
        for (int v : g.edges(u)) {
            if (status[v] == UNVISITED) {
                status[v] = VISITED;
                p[v] = u;
                Q.push(v);
                cout << " -> " << v << " ";
            }
        }

        status[u] = EXPLORED;
    }
    cout << endl;
};


void bfs(const Graph& g, vector<int> &p) {
    int N = g.vertices();

    vector<state> status(N);
    for (int u = 0; u < N; u++) {
        p[u] = -1;
        status[u] = UNVISITED;
    }

    for (int u = 0; u < N; u++) 
        if (status[u] == UNVISITED) {
            cout << "Visited vertice " << u;
            bfs_help(u, g, p, status);
        }
}

int main() {
    Graph g(10);

    //g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 0);
    g.addEdge(1, 6);
    g.addEdge(2, 0);
    g.addEdge(2, 7);
    g.addEdge(4, 5);
    g.addEdge(3, 8);
    g.addEdge(9, 3);

    cout << "Graph: " << endl;
    for (int i = 0; i < g.vertices(); i++) {
        cout << i << ": ";
        if (g.edges(i).empty())
            cout << "No neighbors";
        else { for (int j : g.edges(i))
            cout << j << " ";
        }
        cout << endl;
    }

        if (g.hasEdge(2, 7)) cout << "2 points to 7" << endl;
    if (!g.hasEdge(2, 3)) cout << "2 doesn't point to 3" << endl;

    vector<int> p(g.vertices());
    bfs(g, p);

    for (int i = 0; i < g.vertices(); i++)
        cout << "Found " << i << " through " << p[i] << endl;
}