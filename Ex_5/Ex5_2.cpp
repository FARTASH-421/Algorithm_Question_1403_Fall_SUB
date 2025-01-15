#include <bits/stdc++.h>
using namespace std;
#define INF 1e9

int main() {
    int node, edge;
    cin >> node >> edge;
    node += 1;

    vector<vector<pair<int, int>>> myGraph(node);

    int u, v, k;
    for (int i = 0; i < edge; i++) {
        cin >> u >> v >> k;
        myGraph[u].push_back({v, k});
    }

    vector<int> dist(node, INF);
    vector<bool> visited(node, false);

    dist[1] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, 1});

    while (!pq.empty()) {
        int current_dist = pq.top().first;
        int current_node = pq.top().second;
        pq.pop();

        if (visited[current_node]) continue;
        visited[current_node] = true;

        for (auto &neighbor : myGraph[current_node]) {
            int next_node = neighbor.first;
            int edge_weight = neighbor.second;

            if (dist[next_node] > current_dist + edge_weight) {
                dist[next_node] = current_dist + edge_weight;
                pq.push({dist[next_node], next_node});
            }
        }
    }

    int result = 0;
    bool check = true;
    for (int i = 2; i < node; i++) {
        if (dist[i] == INF) {
            check = false;
            cout << -1 << endl;
            break;
        }
        result = max(result, dist[i]);
    }

    if (check) cout << result << endl;

    return 0;
}
