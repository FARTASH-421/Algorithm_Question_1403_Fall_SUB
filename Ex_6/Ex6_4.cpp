#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200005;
const int MOD = 1 << 30;

vector<pair<int, int>> adj[MAXN];
int parent[MAXN][20], depth[MAXN];
long long dist[MAXN];
int position[MAXN];
int n, q;

void dfs(int u, int p) {
    for (auto &[v, w] : adj[u]) {
        if (v == p) continue;
        parent[v][0] = u;
        depth[v] = depth[u] + 1;
        dist[v] = dist[u] + w;
        dfs(v, u);
    }
}

void preprocess() {
    for (int j = 1; (1 << j) <= n; ++j) {
        for (int i = 1; i <= n; ++i) {
            if (parent[i][j - 1] != -1) {
                parent[i][j] = parent[parent[i][j - 1]][j - 1];
            }
        }
    }
}

int lca(int u, int v) {
    if (depth[u] < depth[v]) swap(u, v);

    int diff = depth[u] - depth[v];
    for (int i = 0; i < 20; ++i) {
        if ((diff >> i) & 1) {
            u = parent[u][i];
        }
    }

    if (u == v) return u;

    for (int i = 19; i >= 0; --i) {
        if (parent[u][i] != parent[v][i]) {
            u = parent[u][i];
            v = parent[v][i];
        }
    }

    return parent[u][0];
}

long long get_distance(int u, int v) {
    int ancestor = lca(u, v);
    return dist[u] + dist[v] - 2 * dist[ancestor];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> q;

    for (int i = 1; i <= n; ++i) {
        cin >> position[i];
    }

    for (int i = 1; i < n; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].emplace_back(v, w);
        adj[v].emplace_back(u, w);
    }

    memset(parent, -1, sizeof(parent));
    depth[1] = 0;
    dist[1] = 0;
    dfs(1, -1);
    preprocess();

    long long ans = 0;

    while (q--) {
        int t;
        cin >> t;

        if (t == 1) {
            long long a, b, c;
            cin >> a >> b >> c;

            int l = ((ans % MOD) ^ a);
            int r = ((ans % MOD) ^ b);
            int v = ((ans % MOD) ^ c);

            long long sum = 0;
            for (int i = l; i <= r; ++i) {
                sum += get_distance(position[i], v);
            }

            ans = sum;
            cout << ans << '\n';
        } else if (t == 2) {
            long long a;
            cin >> a;

            int x = ((ans % MOD) ^ a);
            swap(position[x], position[x + 1]);
        }
    }

    return 0;
}
