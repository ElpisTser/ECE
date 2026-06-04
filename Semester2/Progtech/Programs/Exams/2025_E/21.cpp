#include <set>
#include <vector>
#include <queue>
using namespace std;

class Graph {
public:
    Graph(int n) : vertices(n), edges(n) {}

    void addEdge(int u, int v) {
        edges[u].insert(v);
        edges[v].insert(u);
    }

    set<int> same_color(int u) const {
        set<int> same_color_vertices;
        vector<int> color(vertices, -1);

        if (!(same_color_help(u, color)))
            return set<int>();

        for (int i = 0; i < vertices; i++) {
            if (color[i] == -1) {
                if (!same_color_help(i, color))
                    return set<int>();
            }

            if (color[i] == 0)
                same_color_vertices.insert(i);
        }
        return same_color_vertices;
    }

private:
    int vertices;
    vector<set<int>> edges;
    bool same_color_help(int n, vector<int>& color) const {
        queue<int> q;
        q.push(n);
        color[n] = 0;

        while (!q.empty()) {
            int head = q.front();
            q.pop();

            for (const auto& neighbor : edges[head]) {
                if (color[neighbor] == -1) {
                    color[neighbor] = 1 - color[head];
                    q.push(neighbor);
                }
                else if (color[neighbor] == color[head])
                    return false;
            }
        }
        return true;
    }
};